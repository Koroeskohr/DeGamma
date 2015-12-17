#include <iostream>

#include <common.hpp>


#include <SDLWindowManager.hpp>
#include <GL/glew.h>

#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <assimp/DefaultLogger.hpp>

using namespace glimac;

int main(){
    std::cout << "hello" << std::endl;
    Assimp::Importer importer;
    std::string file = "airboat.obj";
    const aiScene *scene = importer.ReadFile(file, aiProcessPreset_TargetRealtime_Fast);//aiProcessPreset_TargetRealtime_Fast has the configs you'll need

    if (!scene)
    {
        std::cout << "Error loading file: (assimp:) " << importer.GetErrorString();
        return false;
    }
    aiMesh *mesh = scene->mMeshes[0]; //assuming you only want the first mesh

    std::cout << scene->mNumMeshes << std::endl;

    SDLWindowManager windowManager(800, 600, "GLImac");

    glewExperimental = GL_TRUE;

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }


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
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        windowManager.swapBuffers();
    }

    return 0;

}