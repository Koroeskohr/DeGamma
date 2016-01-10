//
// Created by koro on 16/12/15.
//

#ifndef DEGAMMA_LANTERNMODEL_HPP
#define DEGAMMA_LANTERNMODEL_HPP

#include "Model.hpp"

using namespace glimac;

class LanternModel: public Model{

public:
    LanternModel()
        : Model("assets/lantern.stl") {}

    ~LanternModel () {
        std::cout << "Deleted LanternModel model" << std::endl;
    }

};

#endif //DEGAMMA_LANTERNMODEL_HPP
