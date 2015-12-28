#pragma once

#include <common.hpp>

#include "Transform.hpp"
#include "ResourceManager.hpp"

namespace glimac {
class Model;


class Renderable {
public:
    Renderable(const int modelId, const glm::vec3& position = glm::vec3(0));

    virtual void update();
    virtual void render(Program * program);

    Transform getTransform() const;

    virtual ~Renderable() = 0;

private:
    Transform mTransform;
    Model* mModel; //DESIGN PATTERN POIDS MOUCHE
};


}
