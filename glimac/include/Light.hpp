//
// Created by Lucas Hörand on 04/01/2016.
//

#ifndef DEGAMMA_LIGHT_HPP
#define DEGAMMA_LIGHT_HPP

#include "glm.hpp"

namespace glimac{
    class Light {

    private:
        glm::vec3 lightPos;
        glm::vec3 lightColor;

    public:

        Light():
                lightPos(glm::vec3(0.0f, 0.0f, 0.0f)),
                lightColor(glm::vec3(1.0f, 1.0f, 1.0f)){}

        Light(glm::vec3 pos, glm::vec3 color):
                lightPos(pos), lightColor(color){}


        ~Light();

        glm::vec3 getLightPos();

        glm::vec3 getLightColor();

        void setLightPos(glm::vec3 pos);
        void setLightColor(glm::vec3 color);

    };
}





#endif //DEGAMMA_LIGHT_HPP

