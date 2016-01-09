//
// Created by Lucas Hörand on 04/01/2016.
//

#include "Light.hpp"

namespace glimac{
    glm::vec3 Light::getLightPos(){
        return lightPos;
    }

    glm::vec3 Light::getLightColor(){
        return lightColor;
    }

    void Light::setLightPos(glm::vec3 pos) {
        lightPos = pos;
    }

    void Light::setLightColor(glm::vec3 color) {
        lightColor = color;
    }
}






