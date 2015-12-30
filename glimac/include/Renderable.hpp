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

    void setPosition(glm::vec3 pos);
    void setRotation(glm::mat4 rot);
    void setScale(glm::vec3 scale);
    void setScale(float ratio);

    virtual ~Renderable() = 0;

private:
    Model* mModel; //DESIGN PATTERN POIDS MOUCHE
    Transform mTransform;
};


}
