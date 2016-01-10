//
// Created by koro on 27/12/15.
//

#ifndef DEGAMMA_LANTERN_HPP
#define DEGAMMA_LANTERN_HPP

#include "Renderable.hpp"

class Lantern : public Renderable {
public:
    Lantern()
        : Renderable(ModelManager::LANTERN) { };
    Lantern(glm::vec3 pos)
        : Renderable(ModelManager::LANTERN, pos) { };

    ~Lantern(){
        std::cout << "Deleted Lantern renderable" << std::endl;
    }
};


#endif //DEGAMMA_LANTERN_HPP
