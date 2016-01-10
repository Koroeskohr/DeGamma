//
// Created by koro on 03/01/16.
//

#ifndef DEGAMMA_COTTAGEMODEL_HPP
#define DEGAMMA_COTTAGEMODEL_HPP
#include "Model.hpp"

using namespace glimac;

class CottageModel : public Model{

public:
    CottageModel ()
            : Model("assets/cottage/Snow covered CottageOBJ.obj") {}

    ~CottageModel () {
        std::cout << "Deleted cottage model" << std::endl;
    }

};

#endif //DEGAMMA_CHUBMODEL_HPP
