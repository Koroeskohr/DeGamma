#pragma once

#include <common.hpp>

#include "Transform.hpp"
#include "Mesh.hpp"
#include "Model.hpp"
#include "Texture.hpp"


namespace glimac {

class Renderable {
public:
    virtual ~Renderable () = 0;

private:
    Transform mTransform;
    Model* mModel; //DESIGN PATTERN POIDS MOUCHE
    GLint vaoId;
};


}