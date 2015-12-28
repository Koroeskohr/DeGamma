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
    baseScene->addRenderable(new Airboat);
    baseScene->addRenderable(new Airboat(glm::vec3(0.5,0,0)));



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


    FreeflyCamera myCamera;


    glm::mat4 view = myCamera.getViewMatrix();
    mCurrentScene->getCurrentProgram()->setUniformMatrix4("projection", projection);
    mCurrentScene->getCurrentProgram()->setUniformMatrix4("view", view);
    glm::mat4 model(1);
    model = glm::translate(model, glm::vec3(0.0f, -1.75f, -5.0f)); // Translate it down a bit so it's at the center of the scene
    model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));	// It's a bit too big for our scene, so scale it down
    mCurrentScene->getCurrentProgram()->setUniformMatrix4("model", model);

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

        model = glm::rotate(model, 0.01f, glm::vec3(0, 1, 0));
        glUniformMatrix4fv(program.model, 1, GL_FALSE, glm::value_ptr(model));

        myLittleAirboat.draw(program.mProgram->getGLId());

        mWindowManager->swapBuffers();


    }

}
