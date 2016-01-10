//
// Created by koro on 16/12/15.
//

#ifndef DEGAMMA_WHEELCHAIRMODEL_HPP
#define DEGAMMA_WHEELCHAIRMODEL_HPP

#include "Model.hpp"

using namespace glimac;

class WheelchairModel: public Model{

public:
    WheelchairModel()
        : Model("assets/Wheelchair/Wheelchair.obj") {}

    ~WheelchairModel () {
        std::cout << "Deleted dragon model" << std::endl;
    }

};

#endif //DEGAMMA_WHEELCHAIRMODEL_HPP
