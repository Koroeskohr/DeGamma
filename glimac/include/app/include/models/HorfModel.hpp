//
// Created by koro on 16/12/15.
//

#ifndef DEGAMMA_HORFMODEL_HPP
#define DEGAMMA_HORFMODEL_HPP

#include "Model.hpp"

using namespace glimac;

class HorfModel: public Model{

public:
    HorfModel()
        : Model("assets/horf.stl") {}

    ~HorfModel () {
        std::cout << "Deleted horf model" << std::endl;
    }

};

#endif //DEGAMMA_HORFMODEL_HPP
