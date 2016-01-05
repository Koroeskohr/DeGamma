//
// Created by koro on 15/12/15.
//

#ifndef DEGAMMA_SCENE_HPP
#define DEGAMMA_SCENE_HPP

#include "Program.hpp"
#include "Renderable.hpp"
#include "FreeflyCamera.hpp"
#include "Light.hpp"

#include <vector>

namespace glimac {
    class Scene {

    public:
        Scene();
        ~Scene();

        void update();
        void render();

        void addRenderable(Renderable * renderable);
        std::vector<Renderable*> & getRenderables();
        std::vector<Light*> & getLights();

        //TODO : void addLight(const Light& light);
        //void setCamera(const FreeflyCamera& camera);
        FreeflyCamera * getCamera();

        void addProgram(Program * program);
        void setProgram(Program * program);

        void addLight(Light * light);
        Program* getCurrentProgram ();


    private:
        std::vector<Renderable*> mRenderables;
        //TODO : std::vector<Light*> mLights;
        FreeflyCamera * mCamera;

        Program* mCurrentProgram;
        std::vector<Program*> mPrograms;
        std::vector<Light*> mLights;
        void loadPrograms();
    };

}


#endif //DEGAMMA_SCENE_HPP
