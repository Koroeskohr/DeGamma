//
// Created by koro on 15/12/15.
//

#include "Vertex.hpp"

namespace glimac {
    Vertex::Vertex(vec3 pos, vec3 normal, vec2 texCoords)
            : position(pos),
              normal(normal),
              texCoords(texCoords)
    {}

    Vertex::Vertex(const Vertex &p)
            : position(p.position),
              normal(p.normal),
              texCoords(p.texCoords)
    {}
}