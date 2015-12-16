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
        vec3 color; // albedo ?
        vec3 normal;

        //Materials
        vec3 ambientColor;
        vec3 specularColor;
        vec3 emissiveColor;

        Vertex(vec3 pos = vec3(0), vec3 color = vec3(0), vec3 normal = vec3(0,0,-1), vec3 ambiant = vec3(0.6), vec3 specular = vec3(0.6), vec3 emissive = vec3(0.6));
        Vertex(const Vertex &p);
    };
}

#endif //DEGAMMA_VERTEX_HPP
