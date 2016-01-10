//
// Created by koro on 16/12/15.
//

#ifndef DEGAMMA_HOSPITALBEDMODEL_HPP
#define DEGAMMA_HOSPITALBEDMODEL_HPP

#include "Model.hpp"

using namespace glimac;

class HospitalBedModel: public Model{

public:
    HospitalBedModel()
        : Model("assets/hospital_Bed/Bed.obj") {}

    ~HospitalBedModel () {
        std::cout << "Deleted bed model" << std::endl;
    }

};

#endif //DEGAMMA_HOSPITALBEDMODEL_HPP
