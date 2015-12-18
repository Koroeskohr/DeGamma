//
// Created by koro on 15/12/15.
//

#include "Mesh.hpp"

namespace glimac {
    Mesh::Mesh (std::vector<Vertex>& vertices, std::vector<unsigned>& indices, const std::string& materialName)
        : mVertices(vertices),
          mIndices(indices),
          mMaterialName(materialName)
    {
        init();
    }

    void Mesh::init(){
        mVerticesAmount = mVertices.size();

        glGenBuffers(1, &mVBOid);
        glGenVertexArrays(1, &mVAOid);

        glBindVertexArray(mVAOid);
        glBindBuffer(GL_ARRAY_BUFFER, mVBOid);

        glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * mVerticesAmount, &mVertices[0], GL_STATIC_DRAW);

        glGenBuffers(1, &mIBOid);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIBOid);

        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * mVerticesAmount, &mIndices[0], GL_STATIC_DRAW);

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

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

}

