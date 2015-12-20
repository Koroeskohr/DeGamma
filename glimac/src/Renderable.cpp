#include "Renderable.hpp"

namespace glimac {

    Renderable::Renderable(const int modelId, const glm::vec3& position)
        : mModel(ResourceManager::getInstance()->getModel(modelId)),
          mTransform(position)
    {

    }


    void Renderable::update () {
        //TODO
        mTransform.position.x += 0.1;
    }

    void Renderable::render(){
        //TODO
    }
}