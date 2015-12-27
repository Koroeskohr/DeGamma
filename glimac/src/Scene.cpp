//
// Created by koro on 15/12/15.
//

#include "Scene.hpp"

namespace glimac{

    Scene::Scene () {
        loadPrograms();
    }

    Scene::~Scene () {
        for(auto renderable: mRenderables){
            delete renderable;
        }
        for(auto program: mPrograms){
            delete program;
        }
    }

    void Scene::update () {
        for(auto renderable: mRenderables){
            renderable->update();
        }
    }

    void Scene::render () {
        for(auto renderable: mRenderables){
            renderable->render();
        }
    }

    void Scene::addRenderable (Renderable *renderable) {
        mRenderables.push_back(renderable);
    }

    void Scene::loadPrograms () {
        //TODO : more shaders ?
        Program * p  = glimac::loadProgram("shaders/3D.vs.glsl", "shaders/3D.fs.glsl");
        addProgram(p);
        setProgram(p);
    }

    void Scene::addProgram (Program * program) {
        mPrograms.push_back(program);
    }

    void Scene::setProgram (Program * program) {
        mCurrentProgram = program;
    }

}