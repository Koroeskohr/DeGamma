#include <iostream>

#include <common.hpp>


#include <SDLWindowManager.hpp>
#include <GL/glew.h>

#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <assimp/DefaultLogger.hpp>
#include "Program.hpp"
#include "Model.hpp"
#include "FilePath.hpp"

using namespace glimac;

struct ModelProgram {

    Program mProgram;
    GLint uProjection;
    GLint uView;
    GLint uModel;

    ModelProgram(const FilePath& applicationPath):
    mProgram(loadProgram(applicationPath.dirPath() + "shaders/modelLoading.vs.glsl", 
                         applicationPath.dirPath() + "shaders/modelLoading.fs.glsl")) {

        uProjection = glGetUniformLocation(mProgram.getGLId(), "projection");
        uView = glGetUniformLocation(mProgram.getGLId(), "view");
        uModel = glGetUniformLocation(mProgram.getGLId(), "model");
    }

};

int main(){
    


    SDLWindowManager windowManager(800, 600, "GLImac");

    glewExperimental = GL_TRUE;

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }


    //initialisation 
    string modelPath = "/Users/burckelmegane/Desktop/test/degamma/models/airboat.obj";
    Model myModel(modelPath);

    FilePath myFilePath;

    ModelProgram myProgram(myFilePath);

    myProgram.mProgram.use();

    glm::mat4 projection = glm::perspective(glm::radians(70.f), 800.f/600.f, 0.1f, 100.0f);
    glm::mat4 MVMatrix = glm::translate(glm::mat4(1), glm::vec3(0,0,-5));
    glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));


        // Draw the loaded model
        glm::mat4 model;
        model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f)); // Translate it down a bit so it's at the center of the scene
        model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f)); // It's a bit too big for our scene, so scale it down
        glUniformMatrix4fv(glGetUniformLocation(myProgram.mProgram.getGLId(), "model"), 1, GL_FALSE, glm::value_ptr(model));
        


    /* START LOOP */
    bool done = false;
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
        }
        
        glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix*MVMatrix));
        glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
        glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));

        myModel.Draw(myProgram.mProgram);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        windowManager.swapBuffers();
    }

    return 0;

}