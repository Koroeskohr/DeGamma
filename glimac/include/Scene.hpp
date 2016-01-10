//
// Created by koro on 15/12/15.
//

#ifndef DEGAMMA_SCENE_HPP
#define DEGAMMA_SCENE_HPP

#include "Program.hpp"
#include "app/include/renderables/renderables.hpp"
#include "Renderable.hpp"
#include "FreeflyCamera.hpp"
#include "RenderableFactory.hpp"
#include "rapidjson/document.h"
#include "Light.hpp"
#include "Skybox.hpp"

#include <fstream>
#include <vector>

using namespace rapidjson;


namespace glimac {
    class Scene {

    public:
        Scene();
        Scene(std::string & path);
        ~Scene();

        void update();
        void render();

        void addRenderable(Renderable * renderable);
        std::vector<Renderable*> & getRenderables();

        FreeflyCamera * getCamera();

        void addProgram(Program * program);
        void setProgram(Program * program);
        Program* getCurrentProgram ();

        void addPointLight(Light * light);
        void setDirLight(glm::vec3 dir, glm::vec3 color);
        std::vector<Light*> & getPointLights();
        void createLightsUniforms();

        void useNextShader();


    private:
        std::vector<Renderable*> mRenderables;
        std::vector<Program*> mPrograms;
        std::vector<Light*> mPointLights;
        FreeflyCamera * mCamera;
        Program* mCurrentProgram;
        unsigned int mCurrentProgramId;

        Light * mDirLight;
        Skybox * mSkybox;


        void loadPrograms();
    };

}


#endif //DEGAMMA_SCENE_HPP
