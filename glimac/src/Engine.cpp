//
// Created by koro on 16/12/15.
//

#include "Engine.hpp"
#include "Program.hpp"





Engine * Engine::mInstance = nullptr;

Engine* Engine::getInstance() {
    if (mInstance == nullptr)
        mInstance = new Engine;

    return mInstance;
}

Engine::Engine()
        : mWindowManager(new SDLWindowManager(640,480,"YOloGL")),
          mResourceManager()
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

    //createManagers();



    //TODO : start timers
}

Engine::~Engine(){
    //TODO
}

void Engine::createManagers () {
    mResourceManager = std::unique_ptr<ResourceManager>(ResourceManager::getInstance());
    mWindowManager = std::unique_ptr<SDLWindowManager>(new SDLWindowManager(1280,720, "DeGamma"));
}

void Engine::loop () {

    AirboatModel myLittleAirboat;





    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);


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

        myLittleAirboat.draw();

        mWindowManager->swapBuffers();


    }

}
