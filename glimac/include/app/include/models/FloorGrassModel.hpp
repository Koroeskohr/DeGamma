//
// Created by koro on 16/12/15.
//

#ifndef DEGAMMA_FLOORGRASSMODEL_HPP
#define DEGAMMA_FLOORGRASSMODEL_HPP

#include "Model.hpp"

using namespace glimac;

class FloorGrassModel: public Model{

public:
    FloorGrassModel()
        : Model("assets/floorGrass/floorGrass.obj") {}

    ~FloorGrassModel () {
        std::cout << "Deleted dragon model" << std::endl;
    }

};

#endif //DEGAMMA_FLOORGRASSMODEL_HPP
