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
    Mesh(std::vector<Vertex>& vertices, std::vector<unsigned>& indices, const std::string& materialName);
    //TODO : put this in private
    // init in Mesh::init
    GLuint mVAOid;
    GLuint mVBOid;
    GLuint mIBOid;
    std::vector<Vertex> mVertices;
    std::vector<unsigned> mIndices;
    unsigned long mVerticesAmount;

private:
    void init();

    //init in Mesh::init



    //init in Mesh::Mesh
    std::string mMaterialName;



};

}


#endif //DEGAMMA_MESH_HPP
