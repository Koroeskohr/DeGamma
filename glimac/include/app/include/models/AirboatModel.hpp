//
// Created by koro on 16/12/15.
//

#ifndef DEGAMMA_AIRBOATMODEL_HPP
#define DEGAMMA_AIRBOATMODEL_HPP

#include "Model.hpp"

using namespace glimac;

class AirboatModel: public Model{

public:
    AirboatModel()
        : Model("assets/nanosuit/nanosuit.obj") {}

    ~AirboatModel () {
        std::cout << "Deleted ab model" << std::endl;
    }

};

#endif //DEGAMMA_AIRBOATMODEL_HPP
