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
        const aiScene *scene = importer.ReadFile(fileName, aiProcess_Triangulate | aiProcess_FlipUVs);

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


        for (int i = 0; i < scene->mNumMeshes; i++) {
            aiMesh * currMesh = scene->mMeshes[i];
            const aiMaterial *material = scene->mMaterials[currMesh->mMaterialIndex];


            //TODO : make this nicer by using a filepath

            std::string fullPath = "assets/nanosuit/";

            if (AI_SUCCESS != material->Get(AI_MATKEY_NAME, name))
                std::cout << name.data <<"No material name" << std::endl;

            if (AI_SUCCESS != material->Get(AI_MATKEY_COLOR_DIFFUSE, diffuse))
                std::cout << name.data << "No material diffuse color" << std::endl;

            if (AI_SUCCESS != material->Get(AI_MATKEY_COLOR_AMBIENT, ambient))
                std::cout << name.data << "No material ambient color" << std::endl;

            if (AI_SUCCESS != material->Get(AI_MATKEY_COLOR_SPECULAR, specular))
                std::cout << name.data << "No material specular color" << std::endl;

            if (AI_SUCCESS != material->Get(AI_MATKEY_SHININESS, shininess))
                std::cout << name.data <<"No material shininess" << std::endl;

            if (AI_SUCCESS == material->GetTexture(aiTextureType_DIFFUSE, 0, &imagePath)) {
                fullPath.append(imagePath.C_Str());
                imagePath = fullPath;

                std::string imageName(imagePath.data);

                std::unique_ptr<Image> texImage = loadImage(imageName);

                if (mTextures.count(name.data) == 0){
                    mTextures.insert(std::make_pair(name.data,
                                                    new Texture(name.data,
                                                                texImage,
                                                                aiToGlm(diffuse),
                                                                aiToGlm(ambient),
                                                                aiToGlm(specular),
                                                                (GLfloat) shininess)));
                }

            }
            else if (mTextures.count(name.data) == 0){
                mTextures.insert(std::make_pair(name.data,
                                                new Texture(name.data,
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

                glm::vec2 currTexCoords;
                if(mesh->HasTextureCoords(0)){
                    currTexCoords = glm::vec2(texCoords.x, texCoords.y);
                }
                else currTexCoords = glm::vec2(0.0f,0.0f);

                glm::vec3 currNormals;
                if(mesh->HasNormals()){
                    currNormals = glm::vec3(normals.x, normals.y, normals.z);
                }
                else currNormals = glm::vec3(0);

                Vertex v(glm::vec3(position.x, position.y, position.z),
                         glm::vec3(currNormals.x, currNormals.y, currNormals.z),
                         glm::vec2(currTexCoords.x, currTexCoords.y));

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

    void Model::draw(GLuint program) {
        for (int i = 0; i < mMeshes.size(); i++) {
            Mesh *currMesh = mMeshes[i];

            //TODO : a better way than this one to deal with things with no textures
            GLuint currTexId =  mTextures.at(currMesh->getMaterialName())->getGlTexture();
            glm::vec4 dColor = mTextures.at(currMesh->getMaterialName())->getDiffuseColor();

            glUniform1i(glGetUniformLocation(program, "hasTexture"), mTextures.at(currMesh->getMaterialName())->hasTexture);

            glUniform1i(glGetUniformLocation(program, "texture_diffuse1"), 0);
            glUniform3f(glGetUniformLocation(program, "color_diffuse"), dColor.r, dColor.g, dColor.b);
            glBindTexture(GL_TEXTURE_2D, currTexId);

            glBindVertexArray(currMesh->getVAOid());


            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, currMesh->getIBOid());

            glDrawElements(GL_TRIANGLES, currMesh->getVertexAmount(), GL_UNSIGNED_INT, (void*)0);

            glBindTexture(GL_TEXTURE_2D, 0);

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

            glBindVertexArray(0);

        }

    }
}
