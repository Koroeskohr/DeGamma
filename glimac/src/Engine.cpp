//
// Created by koro on 16/12/15.
//

#include "Engine.hpp"



Engine* Engine::GetInstance() {
    if (mInstance == nullptr)
        mInstance = new Engine;

    return mInstance;
}

Engine::Engine()
    : mResourceManager(),
      mWindowManager()
{
    glewExperimental = GL_TRUE;

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        throw std::runtime_error("Error initializing glew");
    }
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_CULL_FACE);
    glDepthFunc(GL_LEQUAL);

    createManagers();

}

void Engine::createManagers () {
    mResourceManager = std::unique_ptr<ResourceManager>(ResourceManager::getInstance());
    mWindowManager = std::unique_ptr<SDLWindowManager>(new SDLWindowManager(1280,720, "DeGamma"));
}