//
// Created by koro on 16/12/15.
//

#include "ModelManager.hpp"

ModelManager *ModelManager::mInstance = nullptr;

namespace glimac {
    ModelManager *ModelManager::getInstance () {
        if (!mInstance) {
            mInstance = new ModelManager;
        }
        return mInstance;
    }

    ModelManager::ModelManager ()
        : mModelsMap()
    { }

    // called by Renderable childs instances
    Model*ModelManager::makeModel(const int modelId){
        switch(modelId){
            case ModelManager::AIRBOAT:
                return new AirboatModel;
            case ModelManager::COTTAGE:
                return new CottageModel;

            default:
                throw std::runtime_error("Wrong model id input");
        }
    }


    Model *ModelManager::getModel (const int modelId) {
        long modelCount = mModelsMap.count(modelId);
        Model * model;

        if(modelCount > 1){
            std::ostringstream errorMessage;
            errorMessage << "There is more than one model : " << modelId;
            throw std::runtime_error(errorMessage.str());
        }
        else if(modelCount == 0){
            model = makeModel(modelId);
            std::cout << "creating model " << modelId << std::endl;
            mModelsMap.insert(std::make_pair(modelId, model));
        }
        else {
            std::cout << "getting model " << modelId << std::endl;
            model = mModelsMap.at(modelId);
        }

        return model;
    }

    ModelManager::~ModelManager () {
        std::cout << "Resource manager deleted";
    }
}