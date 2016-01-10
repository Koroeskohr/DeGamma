//
// Created by koro on 27/12/15.
//

#ifndef DEGAMMA_TULIP_HPP
#define DEGAMMA_TULIP_HPP

#include "Renderable.hpp"

class Tulip : public Renderable {
public:
    Tulip()
        : Renderable(ModelManager::TULIP) { };
    Tulip(glm::vec3 pos)
        : Renderable(ModelManager::TULIP, pos) { };

    ~Tulip(){
        std::cout << "Deleted Dragon renderable" << std::endl;
    }
};


#endif //DEGAMMA_TULIP_HPP
