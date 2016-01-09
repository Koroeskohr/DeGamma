//
// Created by koro on 16/12/15.
//

#ifndef DEGAMMA_MODEL_HPP
#define DEGAMMA_MODEL_HPP

#include <map>
#include <assimp/Importer.hpp>
#include <GL/glew.h>
#include <iostream>

#include "Mesh.hpp"
#include "Texture.hpp"
#include "Program.hpp"
#include "Image.hpp"
#include "FreeflyCamera.hpp"


namespace glimac {

class Model {
public:
    Model(const std::string& fileName);
    virtual ~Model() = 0;

    void draw(Program * program);
    std::vector<Mesh*> mMeshes;

private:
    void loadMaterials(const aiScene* scene, const std::string & directory);
    void loadMeshes(const aiScene* scene);

    glm::vec3 aiToGlm(const aiColor3D& c);

    std::map<std::string, Texture*> mTextures;
    std::map<int, std::string> mTexCorrespondanceMap;
};

}

#endif //DEGAMMA_MODEL_HPP
