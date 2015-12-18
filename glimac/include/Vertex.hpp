//
// Created by koro on 15/12/15.
//

#ifndef DEGAMMA_VERTEX_HPP
#define DEGAMMA_VERTEX_HPP

#include "common.hpp"

using namespace glm;

namespace glimac {
    struct Vertex {
        // Vertex attributes
        vec3 position;
        vec3 normal;
        vec2 texCoords;

        Vertex(vec3 pos = vec3(0), vec3 normal, vec2 texCoords);
        Vertex(const Vertex &p);
    };
}

#endif //DEGAMMA_VERTEX_HPP
