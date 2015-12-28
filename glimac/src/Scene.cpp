//
// Created by koro on 15/12/15.
//

#include "Scene.hpp"

namespace glimac{
    //HACK : ratio should be retrieved
    Scene::Scene ()
        : mCamera(new FreeflyCamera(glm::perspective(glm::radians(40.0f), 1280.0f/720.0f, 0.1f, 100.0f)))
    {
        loadPrograms();
        std::cout << "Program added has ID " << mPrograms.at(0)->getGLId() << std::endl;
        setProgram(mPrograms.at(0));
        mCurrentProgram->setUniformMatrix4("projection", mCamera->getProjectionMatrix());
        mCamera->moveFront(-1.0f);
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
        glm::mat4 view = mCamera->getViewMatrix();
        mCurrentProgram->setUniformMatrix4("view", view);

        for(auto renderable: mRenderables){
            renderable->render(mCurrentProgram);
        }
    }

    void Scene::addRenderable (Renderable *renderable) {
        mRenderables.push_back(renderable);
    }

    void Scene::loadPrograms () {
        //TODO : more shaders ?
        Program * p  = glimac::loadProgram("shaders/3D.vs.glsl", "shaders/3D.fs.glsl");
        addProgram(p);
        std::cout << "mprograms has " << mPrograms.size() << std::endl;

    }

    void Scene::addProgram (Program * program) {
        mPrograms.push_back(program);
    }

    void Scene::setProgram (Program * program) {
        mCurrentProgram = program;
        mCurrentProgram->use();
    }

    Program *Scene::getCurrentProgram () {
        return mCurrentProgram;
    }

    FreeflyCamera* Scene::getCamera () {
        return mCamera;
    }
}