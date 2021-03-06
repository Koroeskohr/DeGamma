//
// Created by koro on 15/12/15.
//

#include "Mesh.hpp"
#include <iostream>

namespace glimac {
    Mesh::Mesh (std::vector<Vertex>& vertices, std::vector<unsigned>& indices, const std::string& materialName)
        : mVertices(vertices),
          mIndices(indices),
          mMaterialName(materialName)
    {
        std::cout << "creating mesh using material name " << materialName << std::endl;
        init();
    }

    Mesh::~Mesh () {
        std::cout << "Mesh deleted, it used material " << mMaterialName << std::endl << "VAO id : " << mVAOid << std::endl;
    }

    void Mesh::init(){
        mVerticesAmount = mVertices.size();

        glGenBuffers(1, &mVBOid);
        glGenVertexArrays(1, &mVAOid);

        glBindVertexArray(mVAOid);
        glBindBuffer(GL_ARRAY_BUFFER, mVBOid);

        glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * mVerticesAmount, &mVertices[0], GL_STATIC_DRAW);

        glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
        glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
        glEnableVertexAttribArray(VERTEX_ATTR_TEX_COORDS);

        glVertexAttribPointer(
                VERTEX_ATTR_POSITION,   //index
                3,                      //size
                GL_FLOAT,               //type
                GL_FALSE,               //normalized
                sizeof(Vertex),         //stride (écart entre deux jeux de données)
                (const GLvoid*) 0       //pointer (décalage en octets jusqu'à nos données)
        );
        glVertexAttribPointer(
                VERTEX_ATTR_NORMAL,   //index
                3,                    //size
                GL_FLOAT,             //type
                GL_FALSE,             //normalized
                sizeof(Vertex),       //stride (écart entre deux jeux de données)
                (const GLvoid*) (offsetof(Vertex, normal))                  //pointer (décalage en octets jusqu'à nos données)
        );

        glVertexAttribPointer(
                VERTEX_ATTR_TEX_COORDS,  //index
                2,                       //size
                GL_FLOAT,                //type
                GL_FALSE,                //normalized
                sizeof(Vertex),          //stride (écart entre deux jeux de données)
                (const GLvoid*) (offsetof(Vertex, texCoords))                  //pointer (décalage en octets jusqu'à nos données)
        );

        glGenBuffers(1, &mIBOid);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIBOid);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * mVerticesAmount, &mIndices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    std::vector<Vertex> & Mesh::getVertices () {
        return mVertices;
    }

    std::vector<unsigned> & Mesh::getIndices () {
        return mIndices;
    }

    unsigned long Mesh::getVertexAmount () const {
        return mVerticesAmount;
    }

    const std::string &Mesh::getMaterialName () const {
        return mMaterialName;
    }

    GLuint Mesh::getIBOid () const {
        return mIBOid;
    }

    GLuint Mesh::getVBOid () const {
        return mVBOid;
    }

    GLuint Mesh::getVAOid () const {
        return mVAOid;
    }
}

