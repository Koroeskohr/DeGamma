//
// Created by koro on 27/12/15.
//

#ifndef DEGAMMA_HOSPITALBED_HPP
#define DEGAMMA_HOSPITALBED_HPP

#include "Renderable.hpp"

class HospitalBed : public Renderable {
public:
    HospitalBed()
        : Renderable(ModelManager::HOSPITALBED) { };
    HospitalBed(glm::vec3 pos)
        : Renderable(ModelManager::HOSPITALBED, pos) { };

    ~HospitalBed(){
        std::cout << "Deleted Dragon renderable" << std::endl;
    }
};


#endif //DEGAMMA_HOSPITALBED_HPP
