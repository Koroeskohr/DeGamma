#include "Renderable.hpp"

namespace glimac {

    Renderable::Renderable(const int modelId, const glm::vec3& position)
        : mModel(ResourceManager::getInstance()->getModel(modelId)),
          mTransform(position)
    {

    }


}