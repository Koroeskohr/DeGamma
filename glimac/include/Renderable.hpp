#pragma once

#include <common.hpp>

#include "Transform.hpp"
#include "Mesh.hpp"
#include "Model.hpp"
#include "Texture.hpp"


namespace glimac {

class Renderable {
public:
    Renderable(const int modelId, const glm::vec3& position = glm::vec3(0));

    virtual ~Renderable() = 0;

private:
    Transform mTransform;
    Model* mModel; //DESIGN PATTERN POIDS MOUCHE
};


}