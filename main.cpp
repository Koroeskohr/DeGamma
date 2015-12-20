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
    //TODO : remove stuff, add engine stuff
    FileLogger debug ("0.0.1", "log.txt");

    // Writing warnings or errors to file is very easy and C++ style
    debug << FileLogger::e_logType::LOG_WARNING << "Hey! ... This is a warning message!";
    debug << FileLogger::e_logType::LOG_ERROR << "WOW! Something really wrong is happening here!";
    debug << "This is just a simple text";

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