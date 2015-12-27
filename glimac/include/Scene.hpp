//
// Created by koro on 15/12/15.
//

#ifndef DEGAMMA_SCENE_HPP
#define DEGAMMA_SCENE_HPP

#include "Program.hpp"
#include "Renderable.hpp"

#include <vector>

namespace glimac {
    class Scene {

    public:
        Scene();
        ~Scene();

        void update();
        void render();

        void addRenderable(Renderable * renderable);
        //TODO : void addLight(const Light& light);
        //TODO : void setCamera(const Camera& camera);

        void addProgram(Program * program);
        void setProgram(Program * program);


    private:
        std::vector<Renderable*> mRenderables;
        //TODO : std::vector<Light*> mLights;
        //TODO : Camera* camera;

        Program* mCurrentProgram;
        std::vector<Program*> mPrograms;
        void loadPrograms();
    };

}


#endif //DEGAMMA_SCENE_HPP
