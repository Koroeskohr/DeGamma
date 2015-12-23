#include <iostream>

#include <common.hpp>


#include <SDLWindowManager.hpp>
#include <GL/glew.h>

#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <assimp/DefaultLogger.hpp>
#include <Vertex.hpp>
#include <Mesh.hpp>
#include <models/AirboatModel.hpp>
#include <Renderable.hpp>
#include "FilePath.hpp"



#include "Engine.hpp"



using namespace glimac;


int main(int argc, char** argv){


    Engine * engine = Engine::getInstance();
    //TODO : remove stuff, add engine stuff
    FileLogger debug ("0.0.1", "log.txt");

    // Writing warnings or errors to file is very easy and C++ style
    debug << FileLogger::e_logType::LOG_WARNING << "Hey! ... This is a warning message!";
    debug << FileLogger::e_logType::LOG_ERROR << "WOW! Something really wrong is happening here!";
    debug << "This is just a simple text";




    //TODO : render loop

    engine->loop();

    return 0;

}