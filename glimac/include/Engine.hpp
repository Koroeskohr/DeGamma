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
#include "ModelManager.hpp"
#include "TimeManager.hpp"
#include "Scene.hpp"
#include "Program.hpp"
#include "FreeflyCamera.hpp"

#include "Renderable.hpp"
#include "app/include/renderables/renderables.hpp"

using namespace glimac;
class Engine {
public:
    static Engine* getInstance();
    ~Engine();

    void loop();
    void loadSceneFromFile(std::string & path);
    long getGlobalTime();


    //TODO : remove when wmanager is singleton
    std::unique_ptr<SDLWindowManager> const & getWindowManager();

    /*
     * No default copy constructor since it's a singleton
     */
    Engine(const Engine&) = delete;
    void operator=(const Engine&) = delete;

private:
    static Engine* mInstance;
    Engine();
    void createManagers();

    std::unique_ptr<Scene> mCurrentScene;

    std::unique_ptr<ModelManager> mResourceManager;
    std::unique_ptr<SDLWindowManager> mWindowManager;
    std::unique_ptr<TimeManager> mTimeManager;

    std::shared_ptr<Timer> mProgramTimer;
};


#endif //DEGAMMA_ENGINE_HPP
