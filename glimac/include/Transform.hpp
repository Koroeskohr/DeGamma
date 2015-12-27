//
// Created by koro on 16/12/15.
//

#ifndef DEGAMMA_TRANSFORM_HPP
#define DEGAMMA_TRANSFORM_HPP

#include <common.hpp>

using namespace glm;

struct Transform {
    mat4 modelMatrix;

    mat4 rotation;
    vec3 position;
    vec3 scale;

    void updateModelMatrix(){
        modelMatrix = mat4(0);
        modelMatrix *= rotation;
        modelMatrix = glm::translate(modelMatrix, position);
        modelMatrix = glm::scale(modelMatrix, scale);
    }

    Transform()
        : rotation(0), position(0), scale(1)
    { }
    Transform(glm::vec3 pos)
        : rotation(0), position(pos), scale(1)
    { }
};

#endif //DEGAMMA_TRANSFORM_HPP
