//
// Created by koro on 16/12/15.
//

#ifndef DEGAMMA_TULIPMODEL_HPP
#define DEGAMMA_TULIPMODEL_HPP

#include "Model.hpp"

using namespace glimac;

class TulipModel: public Model{

public:
    TulipModel()
        : Model("assets/tulip/some tulips.obj") {}

    ~TulipModel () {
        std::cout << "Deleted dragon model" << std::endl;
    }

};

#endif //DEGAMMA_TULIPMODEL_HPP
