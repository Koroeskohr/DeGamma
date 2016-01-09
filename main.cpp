#include <iostream>
#include "Engine.hpp"

using namespace glimac;


int main(int argc, char** argv){
    std::unique_ptr<Engine> engine(Engine::getInstance());
    engine->loop();

    return 0;

}