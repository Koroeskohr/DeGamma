//
// Created by koro on 16/12/15.
//

#include "ResourceManager.hpp"

namespace glimac {
    ResourceManager *ResourceManager::getInstance () {
        if (!mInstance) {
            mInstance = new ResourceManager;
        }
        return mInstance;
    }

    ResourceManager::ResourceManager ()
        : mImporter(),
          mModelsMap()
    { }

    // called by Renderable childs instances
    Model* ResourceManager::makeModel(const int modelId){
        switch(modelId){
            case ResourceManager::AIRBOAT:
                return new AirboatModel;

            default:
                throw std::runtime_error("Wrong model id input");
        }
    }

    const aiScene* ResourceManager::import (std::string str) const {
        return mImporter.ReadFile(str, aiProcessPreset_TargetRealtime_Fast);
    }

}