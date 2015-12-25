//
// Created by koro on 16/12/15.
//

#include "Model.hpp"

#include <iostream>
#include "Program.hpp"
#include "Image.hpp"
#include "FreeflyCamera.hpp"




namespace glimac {

    Model::Model(const std::string &fileName) {
        Assimp::Importer importer;
        const aiScene *scene = importer.ReadFile(fileName, aiProcessPreset_TargetRealtime_Fast);

        std::cout << "starting loading materials" << std::endl;

        if (scene->HasMaterials()) {


            loadMaterials(scene);
        }

        std::cout << "loaded cube materials" << std::endl;

        if (!scene->HasMeshes())
            throw std::runtime_error("Scene was empty");
        else {
            loadMeshes(scene);
        }

        std::cout << "loaded cube meshes" << std::endl;


    }

    Model::~Model() {
        std::cout << "Model deleted" << std::endl;
    }

    //TODO : refactor
    void Model::loadMaterials(const aiScene *scene) {
        aiString name;
        aiColor3D diffuse;
        aiColor3D ambient;
        aiColor3D specular;
        float shininess;

        aiString imagePath;


        for (int i = 0; i < scene->mNumMaterials; i++) {


            //TODO : make this nicer by using a filepath

            std::string fullPath = "/Users/Luhof/Documents/IMAC2/projetogl/DeGamma/nanosuit/";

            const aiMaterial *material = scene->mMaterials[i];
            if (AI_SUCCESS != material->Get(AI_MATKEY_NAME, name))
                throw std::runtime_error("No material name");

            if (AI_SUCCESS != material->Get(AI_MATKEY_COLOR_DIFFUSE, diffuse))
                throw std::runtime_error("No material diffuse color");

            if (AI_SUCCESS != material->Get(AI_MATKEY_COLOR_AMBIENT, ambient))
                throw std::runtime_error("No material ambient color");

            if (AI_SUCCESS != material->Get(AI_MATKEY_COLOR_SPECULAR, specular))
                throw std::runtime_error("No material specular color");

            if (AI_SUCCESS != material->Get(AI_MATKEY_SHININESS, shininess))
                throw std::runtime_error("No material shininess");

            if (AI_SUCCESS != material->Get(AI_MATKEY_TEXTURE_DIFFUSE(0), imagePath)) {
                std::cout << "No material imagepath" << std::endl;
            }
            else {

                fullPath.append(imagePath.C_Str());
                imagePath = fullPath;

                std::string imageName(imagePath.data);
                std::unique_ptr<Image> texImage = loadImage(imageName);

                if (mTextures.count(name.data) != 0)
                    throw std::runtime_error("Texture already added");

                mTextures.insert(std::make_pair(name.data,
                                                new Texture(name.data,
                                                        texImage,
                                                        aiToGlm(diffuse),
                                                        aiToGlm(ambient),
                                                        aiToGlm(specular),
                                                        (GLfloat) shininess)));

            }

            std::string materialName(name.data);
            mTexCorrespondanceMap.insert(std::make_pair(i, materialName));


        }


    }

    //TODO : refactor
    void Model::loadMeshes(const aiScene *scene) {

        std::vector<Vertex> vertices;
        std::vector<unsigned> indices;

        for (int i = 0; i < scene->mNumMeshes; i++) {

            const aiMesh *mesh = scene->mMeshes[i];

            // Filling the vertices vector
            for (int j = 0; j < mesh->mNumVertices; ++j) {
                // references to avoid data copy. Way too many vertices to afford copying them
                const aiVector3D &position = mesh->mVertices[j];
                const aiVector3D &normals = mesh->mNormals[j];
                //texture coords for texture at id 0
                const aiVector3D &texCoords = mesh->mTextureCoords[0][j];

                Vertex v(glm::vec3(position.x, position.y, position.z),
                         glm::vec3(normals.x, normals.y, normals.z),
                         glm::vec2(texCoords.x, texCoords.y));

                vertices.push_back(v);
            }

            // Now filling the indices vector with faces
            for (int j = 0; j < mesh->mNumFaces; ++j) {
                const aiFace &meshFace = mesh->mFaces[j];
                indices.push_back(meshFace.mIndices[0]);
                indices.push_back(meshFace.mIndices[1]);
                indices.push_back(meshFace.mIndices[2]);
            }


            std::string materialName;

            // Initializing mesh and pushing in mesh vector
            if (mTexCorrespondanceMap.count(i) > 0)
                materialName = mTexCorrespondanceMap.at(i);
            else
                materialName = "default";

            mMeshes.push_back(new Mesh(vertices, indices, materialName));

            vertices.clear();
            indices.clear();
        }
    }

    glm::vec3 Model::aiToGlm(const aiColor3D &c) {
        return glm::vec3(c.r, c.g, c.b);
    }

    void Model::draw() {
        for (int i = 0; i < mMeshes.size(); i++) {
            Mesh *currMesh = mMeshes[i];


            //GLuint currTexId =  mTextures.at(currMesh->mMaterialName);

            glBindVertexArray(currMesh->mVAOid);

            // glBindTexture(GL_TEXTURE_2D, currTexId);

            glDrawElements(GL_TRIANGLES, currMesh->mVerticesAmount, GL_FLOAT, 0);

            //glBindTexture(GL_TEXTURE_2D, 0);

            glBindVertexArray(0);

        }

    }
}
