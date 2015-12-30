#include "Renderable.hpp"

namespace glimac {

    Renderable::Renderable(const int modelId, const glm::vec3& position)
        : mModel(ResourceManager::getInstance()->getModel(modelId)),
          mTransform(position)
    { }

    Renderable::~Renderable () {
        std::cout << "Renderable deleted" << std::endl;
    }

    void Renderable::update () {
        //TODO
        mTransform.position.x += 0.01;
    }

    void Renderable::render(Program * program){
        
        mTransform.scale = glm::vec3(0.2);
        mTransform.updateModelMatrix();
        program->setUniformMatrix4("model", mTransform.modelMatrix);
        mModel->draw(program);
    }

    Transform Renderable::getTransform () const {
        return mTransform;
    }

    void Renderable::setPosition (glm::vec3 pos) {
        mTransform.position = pos;
    }

    void Renderable::setRotation (glm::mat4 rot) {
        mTransform.rotation = rot;
    }

    void Renderable::setScale (glm::vec3 scale) {
        mTransform.scale = scale;
    }

    void Renderable::setScale (float ratio) {
        mTransform.scale = glm::vec3(ratio);
    }
}