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
        : mModelsMap()
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

    const aiScene* ResourceManager::import (std::string str) {
        Assimp::Importer importer;
        return importer.ReadFile(str, aiProcessPreset_TargetRealtime_Fast);
    }

    Model *ResourceManager::getModel (const int modelId) {
        long modelCount = mModelsMap.count(modelId);
        Model * model;

        if(modelCount > 1){
            std::ostringstream errorMessage;
            errorMessage << "There is more than one model : " << modelId;
            throw std::runtime_error(errorMessage.str());
        }
        else if(modelCount == 0){
            model = makeModel(modelId);
            mModelsMap.insert(std::make_pair(modelId, model));
        }
        else {
            model = mModelsMap.at(modelId);
        }

        return model;
    }
}