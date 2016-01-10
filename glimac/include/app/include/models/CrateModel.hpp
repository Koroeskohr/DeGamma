//
// Created by koro on 16/12/15.
//

#ifndef DEGAMMA_CRATEMODEL_HPP
#define DEGAMMA_CRATEMODEL_HPP

#include "Model.hpp"

using namespace glimac;

class CrateModel: public Model{

public:
    CrateModel()
        : Model("assets/Crate/Crate1.obj") {}

    ~CrateModel () {
        std::cout << "Deleted dragon model" << std::endl;
    }

};

#endif //DEGAMMA_WHEELCHAIRMODEL_HPP
