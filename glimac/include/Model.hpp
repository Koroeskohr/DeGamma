//
// Created by koro on 16/12/15.
//

#ifndef DEGAMMA_MODEL_HPP
#define DEGAMMA_MODEL_HPP

#include <map>

#include "Mesh.hpp"
#include "Texture.hpp"
#include "ResourceManager.hpp"


namespace glimac {

class Model {
public:
    Model(const std::string& fileName);
    virtual ~Model() = 0;


private:
    std::vector<Mesh> mMeshes;
    std::map<std::string, Texture> mTextures;
};

}

#endif //DEGAMMA_MODEL_HPP
