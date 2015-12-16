//
// Created by koro on 15/12/15.
//

#include "Vertex.hpp"

namespace glimac {
    Vertex::Vertex(vec3 pos, vec3 color, vec3 normal, vec3 ambiant, vec3 specular, vec3 emissive)
            : position(pos),
              color(color),
              normal(normal),
              ambientColor(ambiant),
              specularColor(specular),
              emissiveColor(emissive)
    {}

    Vertex::Vertex(const Vertex &p)
            : position(p.position),
              color(p.color),
              normal(p.normal),
              ambientColor(p.ambientColor),
              specularColor(p.specularColor),
              emissiveColor(p.emissiveColor)
    {}
}