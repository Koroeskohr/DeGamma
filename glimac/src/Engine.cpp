//
// Created by koro on 16/12/15.
//

#include "Engine.hpp"

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;
const char * WINDOW_NAME = "DeGamma";

struct myProgram{

    glimac::Program * mProgram;

    GLint model;
    GLint view;
    GLint projection;


    myProgram():
        mProgram(glimac::loadProgram("shaders/3D.vs.glsl", "shaders/3D.fs.glsl"))
    {
        model = glGetUniformLocation(mProgram->getGLId(), "model");
        view = glGetUniformLocation(mProgram->getGLId(), "view");
        projection = glGetUniformLocation(mProgram->getGLId(), "projection");
    }
};

Engine * Engine::mInstance = nullptr;

Engine* Engine::getInstance() {
    if (mInstance == nullptr)
        mInstance = new Engine;

    return mInstance;
}

//TODO : add timemanager
Engine::Engine()
        : mWindowManager(),
          mResourceManager()
{
    createManagers();
    glewExperimental = GL_TRUE;

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        throw std::runtime_error("Error initializing glew");
    }
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glDepthFunc(GL_LEQUAL);
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

    //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE ); // TODO : remove, it displays meshes as wireframe

    Scene * baseScene = new Scene;
    mCurrentScene = baseScene;
    mCurrentScene->addRenderable(new Airboat(glm::vec3(3.0f, -1.75f, -5.0f)));
    mCurrentScene->addRenderable(new Airboat(glm::vec3(0.0f, -1.75f, -15.0f)));
    mCurrentScene->addRenderable(new Airboat(glm::vec3(-1.0f, -1.75f, -2.0f)));

    mCurrentScene->getRenderables().at(0)->setScale(0.2);
    mCurrentScene->getRenderables().at(1)->setScale(0.2);
    mCurrentScene->getRenderables().at(2)->setScale(0.2);

    //mCurrentScene->addLight(new Light(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f)));




    //TODO : start timers
}

Engine::~Engine(){
    //TODO

    std::cout << "Engine deleted" << std::endl;
}

void Engine::createManagers () {
    mResourceManager = std::unique_ptr<ResourceManager>(ResourceManager::getInstance());
    mWindowManager = std::unique_ptr<SDLWindowManager>(
                         new SDLWindowManager(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME));
}

void Engine::loop () {
    bool done = false;
    while(!done) {
        // Event loop:
        SDL_Event e;
        while (mWindowManager->pollEvent(e)) {
            if (e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //mCurrentScene->update();
        mCurrentScene->render();

        mWindowManager->swapBuffers();


    }

}
