//
// Created by koro on 16/12/15.
//

#include "Model.hpp"

namespace glimac {
    Model::Model (const std::string& fileName)
    {
        const aiScene* scene = ResourceManager::import("airboat.obj");
        if(scene->mNumMeshes == 0)
            throw std::runtime_error("Scene was empty");

        //TODO vectorify c tables and call Model constructor
        /*
        for(int i = 0; i < scene->mNumMeshes; i++)
            mMeshes.push_back(Mesh(scene->mMeshes[i]));

        scene->mMeshes[i],
        scene->mMaterials[aScene->mMeshes[i]->mMaterialIndex

         */
    }
}