//
// Created by koro on 16/12/15.
//

#ifndef DEGAMMA_DRAGONMODEL_HPP
#define DEGAMMA_DRAGONMODEL_HPP

#include "Model.hpp"

using namespace glimac;

class DragonModel: public Model{

public:
    DragonModel()
        : Model("assets/dragon_vrip.ply") {}

    ~DragonModel () {
        std::cout << "Deleted dragon model" << std::endl;
    }

};

#endif //DEGAMMA_DRAGONMODEL_HPP
