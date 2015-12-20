#pragma once

#include <GL/glew.h>
#include "glm.hpp"
#include "FileLogger.hpp"

#define VERTEX_ATTR_POSITION 0
#define VERTEX_ATTR_NORMAL 1
#define VERTEX_ATTR_TEX_COORDS 2


namespace glimac {

struct ShapeVertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
};

}
