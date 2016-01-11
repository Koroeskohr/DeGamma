//
// Created by koro on 16/12/15.
//

#ifndef DEGAMMA_MOUNTAINMODEL_HPP
#define DEGAMMA_MOUNTAINMODEL_HPP

#include "Model.hpp"

using namespace glimac;

class MountainModel: public Model{

public:
    MountainModel()
        : Model("assets/Mountain/Mountain.obj") {}

    ~MountainModel () {
        std::cout << "Deleted mountain model" << std::endl;
    }

};

#endif //DEGAMMA_MOUNTAINMODEL_HPP
