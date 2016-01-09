//
// Created by Lucas Hörand on 04/01/2016.
//

#ifndef DEGAMMA_LIGHT_HPP
#define DEGAMMA_LIGHT_HPP

#include "glm.hpp"
#include <iostream>

namespace glimac{
    class Light {

    private:
        glm::vec3 lightPos;
        glm::vec3 lightColor;

    public:

        Light();
        Light(glm::vec3 pos, glm::vec3 color);

        ~Light();

        glm::vec3 getLightPos() const;
        glm::vec3 getLightColor() const;

        void setLightPos(glm::vec3 pos);
        void setLightColor(glm::vec3 color);

    };
}





#endif //DEGAMMA_LIGHT_HPP

