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
        //glm::mat4 transform(1);
        //transform = glm::translate(transform, glm::vec3(0.0f, -1.75f, -5.0f));
        //transform = glm::scale(transform, glm::vec3(0.2,0.2,0.2));
        mTransform.scale = glm::vec3(0.2);
        mTransform.updateModelMatrix();

        //transform = mTransform.modelMatrix; //FIXME
        program->setUniformMatrix4("model", mTransform.modelMatrix);
        mModel->draw(program->getGLId());
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