//
// Created by koro on 15/12/15.
//

#ifndef DEGAMMA_MESH_HPP
#define DEGAMMA_MESH_HPP

#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>


#include <vector>
#include "Vertex.hpp"


namespace glimac {

class Mesh {
public:
    Mesh(const aiMesh* mesh, const std::string& materialName);




private:
    unsigned int mVerticesAmount;
    std::vector<Vertex> mVertices;
    std::vector<uint32_t> mIndices;

    std::string mMaterialName;

    //TODO : do we add material to the mesh ?
    // probably not
};

}


#endif //DEGAMMA_MESH_HPP
