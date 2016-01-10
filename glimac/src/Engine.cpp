//
// Created by koro on 16/12/15.
//

#include "Engine.hpp"

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;
const char * WINDOW_NAME = "DeGamma";

Engine * Engine::mInstance = nullptr;

Engine* Engine::getInstance() {
    if (mInstance == nullptr)
        mInstance = new Engine;

    return mInstance;
}

Engine::Engine()
        : mWindowManager(),
          mResourceManager(),
          mTimeManager(),
          mCurrentScene(nullptr)
{
    createManagers();

    mProgramTimer = mTimeManager->registerTimer();

    glewExperimental = GL_TRUE;
    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        throw std::runtime_error("Error initializing glew");
    }
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);


    //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE ); // TODO : remove, it displays meshes as wireframe

    std::string baseScenePath("model.json");
    loadSceneFromFile(baseScenePath);

    /*
    Scene * baseScene = new Scene;
    mCurrentScene = baseScene;
    mCurrentScene->addRenderable(new Airboat(glm::vec3(3.0f, -1.75f, -5.0f)));
    mCurrentScene->addRenderable(new Airboat(glm::vec3(0.0f, -1.75f, -15.0f)));
    mCurrentScene->addRenderable(new Airboat(glm::vec3(-1.0f, -1.75f, -2.0f)));
    mCurrentScene->getRenderables().at(0)->setScale(0.2);
    mCurrentScene->getRenderables().at(1)->setScale(0.2);
    mCurrentScene->getRenderables().at(2)->setScale(0.2);
    */

    std::cout << "creating lights uniforms" << std::endl;
    mCurrentScene->createLightsUniforms();
}

Engine::~Engine(){
    mCurrentScene.reset(nullptr);
    std::cout << "Engine deleted" << std::endl;
}

void Engine::createManagers () {
    mResourceManager = std::unique_ptr<ModelManager>(ModelManager::getInstance());
    mWindowManager = std::unique_ptr<SDLWindowManager>(
                         new SDLWindowManager(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME));
    mTimeManager = std::unique_ptr<TimeManager>(TimeManager::getInstance());
}

void Engine::loop () {
    bool done = false;
    glm::ivec2 initialMousePosition(WINDOW_WIDTH/2,WINDOW_HEIGHT/2), actualMousePosition(WINDOW_WIDTH/2,WINDOW_HEIGHT/2), difference(0,0);

    std::shared_ptr<Timer> frameTimer = mTimeManager->registerTimer();
    std::shared_ptr<Timer> inputDelay = mTimeManager->registerTimer();
    while(!done) {
        frameTimer->reset();

        // Event loop:
        SDL_Event e;
        while (mWindowManager->pollEvent(e)) {
            if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE) {
                done = true; // Leave the loop after this iteration
            }
        }

        actualMousePosition = getWindowManager()->getMousePosition();
        difference = actualMousePosition - initialMousePosition;
        initialMousePosition = actualMousePosition;

        //SDL_WarpMouse(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);


        if(getWindowManager()->isMouseButtonPressed(SDL_BUTTON_RIGHT)){
            mCurrentScene->getCamera()->rotateLeft(-difference.x/4.0f);
            mCurrentScene->getCamera()->rotateUp(-difference.y/4.0f);
        }

        if(getWindowManager()->isKeyPressed(SDLK_z))
            mCurrentScene->getCamera()->moveFront(0.25f);
        else if (getWindowManager()->isKeyPressed(SDLK_s))
            mCurrentScene->getCamera()->moveFront(-0.25f);

        if(getWindowManager()->isKeyPressed(SDLK_q))
            mCurrentScene->getCamera()->moveLeft(0.25f);
        else if (getWindowManager()->isKeyPressed(SDLK_d))
            mCurrentScene->getCamera()->moveLeft(-0.25f);

        /*if(getWindowManager()->isKeyPressed(SDLK_LSHIFT))
            mCurrentScene->getCamera()->moveUp(0.25f);

        if(getWindowManager()->isKeyPressed(SDLK_LCTRL))
            mCurrentScene->getCamera()->moveUp(-0.25f);*/

        if(getWindowManager()->isKeyPressed(SDLK_o) && inputDelay->elapsedTime() > 1000){
            std::string n("model.json");
            loadSceneFromFile(n);
            inputDelay->reset();
        }

        if(getWindowManager()->isKeyPressed(SDLK_p) && inputDelay->elapsedTime() > 1000){
            std::string n("2.json");
            loadSceneFromFile(n);
            inputDelay->reset();
        }

        difference = glm::ivec2(0,0);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //mCurrentScene->update();
        mCurrentScene->render();
        mWindowManager->swapBuffers();

        int loopIterationDuration = (int)frameTimer->elapsedTime();
        SDL_Delay(std::max<int>(0, 1000/60.0f - loopIterationDuration));
    }
}

void Engine::loadSceneFromFile (std::string & path) {
    std::cout << "--------- NEW SCENE ----------" << std::endl;
    Scene * scene = new Scene(path);
    if(mCurrentScene != nullptr) {
        std::cout << "--------- DELETING PREVIOUS SCENE ----------" << std::endl;
        mCurrentScene.reset(scene);
    } else {
        mCurrentScene = std::unique_ptr<Scene>(scene);
    }
}

std::unique_ptr<SDLWindowManager> const &Engine::getWindowManager () {
    return mWindowManager;
}

long Engine::getGlobalTime () {
    return mProgramTimer->elapsedTime();
}
