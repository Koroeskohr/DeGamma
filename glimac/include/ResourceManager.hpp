//
// Created by koro on 16/12/15.
//

#ifndef DEGAMMA_RESOURCEMANAGER_HPP
#define DEGAMMA_RESOURCEMANAGER_HPP

#include "Model.hpp"
#include <map>

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
    static Model* makeModel(const int modelId);

    /*
     * No default copy constructor since it's a singleton
     */
    ResourceManager(const ResourceManager&) = delete;
    void operator=(const ResourceManager&) = delete;


private:
    ResourceManager();
    static Assimp::Importer mImporter;
    std::map<int, Model*> mModelsMap;
    Models EModels;

    static ResourceManager* mInstance;



};

}

#endif //DEGAMMA_RESOURCEMANAGER_HPP
