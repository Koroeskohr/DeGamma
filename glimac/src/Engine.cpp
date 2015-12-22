//
// Created by koro on 16/12/15.
//

#include "Engine.hpp"
#include "Program.hpp"
#include "FreeflyCamera.hpp"

struct myProgram{

    glimac::Program mProgram;

    GLint uMVPMatrix;
    GLint uMVMatrix;
    GLint uNormalMatrix;


    myProgram():
            mProgram(glimac::loadProgram("/Users/Luhof/Documents/IMAC2/projetogl/DeGamma/shaders/3D.vs.glsl",
                                         "/Users/Luhof/Documents/IMAC2/projetogl/DeGamma/shaders/3D.fs.glsl")){
        uMVPMatrix = glGetUniformLocation(mProgram.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(mProgram.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(mProgram.getGLId(), "uNormalMatrix");

    }

};





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

    myProgram theProgram;

    theProgram.mProgram.use();
    FreeflyCamera myCamera;
    glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), 800.f/600.f, 0.1f, 100.f);
    glm::mat4 globalMVMatrix = myCamera.getViewMatrix();
    globalMVMatrix = glm::scale(globalMVMatrix, glm::vec3(0.2, 0.2, 0.2));
    glm::mat4 normalMatrix = glm::transpose(glm::inverse(globalMVMatrix));
    glm::mat4 MVPMatrix = ProjMatrix * globalMVMatrix;


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


        glUniformMatrix4fv(theProgram.uMVMatrix, 1, GL_FALSE, glm::value_ptr(globalMVMatrix));
        glUniformMatrix4fv(theProgram.uNormalMatrix, 1, GL_FALSE, glm::value_ptr(normalMatrix));
        glUniformMatrix4fv(theProgram.uMVPMatrix, 1, GL_FALSE, glm::value_ptr(MVPMatrix));



        myLittleAirboat.draw();

        myCamera.moveFront(-0.1);


        mWindowManager->swapBuffers();


    }

}
