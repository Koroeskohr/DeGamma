//
// Created by koro on 16/12/15.
//

#ifndef DEGAMMA_TRANSFORM_HPP
#define DEGAMMA_TRANSFORM_HPP

#include <common.hpp>

using namespace glm;

struct Transform {
    mat4 modelMatrix;

    mat4 rotation = glm::mat4(0);
    vec3 position = glm::vec3(0);
    vec3 scale = glm::vec3(1);

    void updateModelMatrix(){
        modelMatrix = mat4(1);
        modelMatrix *= rotation;
        modelMatrix = glm::translate(modelMatrix, position);
        modelMatrix = glm::scale(modelMatrix, scale);
    }

    Transform()
        : position(0), rotation(1), scale(1)
    { }
    Transform(glm::vec3 pos)
        : position(pos), rotation(1), scale(1)
    { }
    Transform(glm::vec3 pos, glm::mat4 rot, glm::vec3 scale)
        : position(pos), rotation(rot), scale(scale)
    { }
};

#endif //DEGAMMA_TRANSFORM_HPP
