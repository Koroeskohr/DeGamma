#pragma once

#include <common.hpp>

#include "Transform.hpp"
#include "Mesh.hpp"
#include "Model.hpp"
//TODO : #include "Texture.hpp"


namespace glimac {

class Renderable {


private:
    Transform mTransform;
    Model* mModel; //DESIGN PATTERN POIDS MOUCHE

};


}