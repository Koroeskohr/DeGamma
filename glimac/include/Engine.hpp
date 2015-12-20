//
// Created by koro on 16/12/15.
//

#ifndef DEGAMMA_ENGINE_HPP
#define DEGAMMA_ENGINE_HPP

#include <memory>
#include <iostream>

#include "glm.hpp"
#include <GL/glew.h>

#include "SDLWindowManager.hpp"
#include "ResourceManager.hpp"

using namespace glimac;
class Engine {
public:
    static Engine* getInstance();

    ~Engine();

    void loop();
    /*
     * No default copy constructor since it's a singleton
     */
    Engine(const Engine&) = delete;
    void operator=(const Engine&) = delete;

private:
    static Engine* mInstance;
    Engine();
    void createManagers();

    std::unique_ptr<ResourceManager> mResourceManager;
    std::unique_ptr<SDLWindowManager> mWindowManager;
};


#endif //DEGAMMA_ENGINE_HPP
