//
// Created by koro on 16/12/15.
//

#ifndef DEGAMMA_WALLCHAMBREMODEL_HPP
#define DEGAMMA_WALLCHAMBREMODEL_HPP

#include "Model.hpp"

using namespace glimac;

class WallChambreModel: public Model{

public:
    WallChambreModel()
        : Model("assets/wallChambre/fullChambre2.obj") {}

    ~WallChambreModel () {
        std::cout << "Deleted dragon model" << std::endl;
    }

};

#endif //DEGAMMA_WALLCHAMBREMODEL_HPP
