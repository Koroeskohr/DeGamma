//
// Created by koro on 16/12/15.
//

#ifndef DEGAMMA_CAVEMODEL_HPP
#define DEGAMMA_CAVEMODEL_HPP

#include "Model.hpp"

using namespace glimac;

class CaveModel: public Model{

public:
    CaveModel()
        : Model("assets/cave/boite.obj") {}

    ~CaveModel () {
        std::cout << "Deleted CaveModel model" << std::endl;
    }

};

#endif //DEGAMMA_CAVEMODEL_HPP
