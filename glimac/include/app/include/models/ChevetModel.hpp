//
// Created by koro on 16/12/15.
//

#ifndef DEGAMMA_CHEVETMODEL_HPP
#define DEGAMMA_CHEVETMODEL_HPP

#include "Model.hpp"

using namespace glimac;

class ChevetModel: public Model{

public:
    ChevetModel()
        : Model("assets/chevet/Bedside Table D.obj") {}

    ~ChevetModel () {
        std::cout << "Deleted dragon model" << std::endl;
    }

};

#endif //DEGAMMA_CHEVETMODEL_HPP
