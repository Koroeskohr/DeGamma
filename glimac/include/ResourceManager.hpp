//
// Created by koro on 16/12/15.
//

#ifndef DEGAMMA_RESOURCEMANAGER_HPP
#define DEGAMMA_RESOURCEMANAGER_HPP

#include <map>
#include <sstream>

#include "Model.hpp"
#include "models/models.hpp"

namespace glimac {

class ResourceManager {

public:
    static ResourceManager* getInstance();

    /*
     * Let's not have multiple importer since one is enough
     */
    static const aiScene* import(std::string str) const;

    enum Models { AIRBOAT } ;

    /*
     * Model factory
     */
    Model* getModel(const int modelId); //see ResourceManager::EModels enum

    /*
     * No default copy constructor since it's a singleton
     */
    ResourceManager(const ResourceManager&) = delete;
    void operator=(const ResourceManager&) = delete;


private:
    ResourceManager();
    static ResourceManager* mInstance;

    static Assimp::Importer mImporter;

    Model* makeModel(const int modelId);
    std::map<int, Model*> mModelsMap;

    Models EModels;

};

}

#endif //DEGAMMA_RESOURCEMANAGER_HPP
