//
// Created by koro on 27/12/15.
//

#ifndef DEGAMMA_AIRBOAT_HPP
#define DEGAMMA_AIRBOAT_HPP

#include "Renderable.hpp"

class Airboat : public Renderable {
public:
    Airboat()
        : Renderable(ModelManager::AIRBOAT) { };
    Airboat(glm::vec3 pos)
        : Renderable(ModelManager::AIRBOAT, pos) { };

    ~Airboat(){
        std::cout << "Deleted airboat renderable" << std::endl;
    }
};


#endif //DEGAMMA_AIRBOAT_HPP
