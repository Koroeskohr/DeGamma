//
// Created by koro on 16/12/15.
//

#ifndef DEGAMMA_RESOURCEMANAGER_HPP
#define DEGAMMA_RESOURCEMANAGER_HPP

#include <map>
#include <sstream>

#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>

#include "Model.hpp"
#include "app/include/models/models.hpp"

namespace glimac {

class ModelManager {

public:
    static ModelManager * getInstance();

    ~ModelManager ();

    enum Models { AIRBOAT, COTTAGE } ;

    /*
     * Model factory
     */
    Model* getModel(const int modelId); //see ModelManager::EModels enum

    /*
     * No default copy constructor since it's a singleton
     */
    ModelManager (const ModelManager &) = delete;
    void operator=(const ModelManager &) = delete;


private:
    ModelManager ();
    static ModelManager * mInstance;

    Model* makeModel(const int modelId);
    std::map<int, Model*> mModelsMap;

    Models EModels;

};

}

#endif //DEGAMMA_RESOURCEMANAGER_HPP
