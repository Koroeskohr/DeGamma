//
// Created by Lucas Hörand on 04/01/2016.
//

#include "Light.hpp"

namespace glimac{
    Light::Light()
        : lightPos(glm::vec3(0.0f, 0.0f, 0.0f)),
          lightColor(glm::vec3(1.0f, 1.0f, 1.0f))
    { }

    Light::Light (glm::vec3 pos, glm::vec3 color)
            : lightPos(pos),
              lightColor(color)
    { }

    glm::vec3 Light::getLightPos() const{
        return lightPos;
    }

    glm::vec3 Light::getLightColor() const{
        return lightColor;
    }

    void Light::setLightPos(glm::vec3 pos) {
        lightPos = pos;
    }

    void Light::setLightColor(glm::vec3 color) {
        lightColor = color;
    }

}






