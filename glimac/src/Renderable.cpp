#include "Renderable.hpp"

namespace glimac {

    Renderable::Renderable(const int modelId, const glm::vec3& position)
        : mModel(ResourceManager::getInstance()->getModel(modelId)),
          mTransform(position)
    {

    }

    Renderable::~Renderable () {
        std::cout << "Renderable deleted" << std::endl;
    }

    void Renderable::update () {
        //TODO
        mTransform.position.x += 0.1;
    }

    void Renderable::render(){
        //TODO
    }
}