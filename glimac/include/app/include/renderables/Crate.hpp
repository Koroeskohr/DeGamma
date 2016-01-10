//
// Created by koro on 27/12/15.
//

#ifndef DEGAMMA_CRATE_HPP
#define DEGAMMA_CRATE_HPP

#include "Renderable.hpp"

class Crate : public Renderable {
public:
    Crate()
        : Renderable(ModelManager::CRATE) { };
    Crate(glm::vec3 pos)
        : Renderable(ModelManager::CRATE, pos) { };

    ~Crate(){
        std::cout << "Deleted Dragon renderable" << std::endl;
    }
};


#endif //DEGAMMA_WHEELCHAIR_HPP
