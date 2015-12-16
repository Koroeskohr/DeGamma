//
// Created by koro on 16/12/15.
//

#ifndef DEGAMMA_MODEL_HPP
#define DEGAMMA_MODEL_HPP

#include "Mesh.hpp"
#include "Texture.hpp"

namespace glimac {

class Model {
    Mesh mMesh;
    Texture mTexture;

public:
    virtual Model() = 0;
    virtual ~Model() = 0;
};

}

#endif //DEGAMMA_MODEL_HPP
