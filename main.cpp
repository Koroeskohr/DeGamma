#include <iostream>

#include <common.hpp>

#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>
#include <assimp/DefaultLogger.hpp>

int main(){
    std::cout << "hello" << std::endl;
    Assimp::Importer importer;
    std::string file = "airboat.obj";
    const aiScene *scene = importer.ReadFile(file, aiProcessPreset_TargetRealtime_Fast);//aiProcessPreset_TargetRealtime_Fast has the configs you'll need

    if (!scene)
    {
        std::cout << "Error loading file: (assimp:) " << importer.GetErrorString();
        return false;
    }
    aiMesh *mesh = scene->mMeshes[0]; //assuming you only want the first mesh

    std::cout << scene->mNumMeshes << std::endl;


}