//
// Created by koro on 03/01/16.
//

#ifndef DEGAMMA_COTTAGE_HPP
#define DEGAMMA_COTTAGE_HPP

#include "Renderable.hpp"

class Cottage : public Renderable {
public:
    Cottage ()
        : Renderable(ModelManager::COTTAGE){};
    Cottage (glm::vec3 pos)
        : Renderable(ModelManager::COTTAGE, pos) { }

    ~Cottage () {
        std::cout << "Deleted cottage renderable" << std::endl;
    }
};


#endif //DEGAMMA_COTTAGE_HPP
