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
        glm::mat4 transform;
        mTransform.scale = glm::vec3(0.2);
        mTransform.updateModelMatrix();

        transform = mTransform.modelMatrix; //FIXME
        transform = mat4(1);
        program->setUniformMatrix4("model", transform);
        mModel->draw(program->getGLId());
    }

    Transform Renderable::getTransform () const {
        return mTransform;
    }
}