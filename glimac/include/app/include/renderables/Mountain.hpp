//
// Created by koro on 27/12/15.
//

#ifndef DEGAMMA_MOUNTAIN_HPP
#define DEGAMMA_MOUNTAIN_HPP

#include "Renderable.hpp"

class Mountain : public Renderable {
public:
    Mountain()
        : Renderable(ModelManager::MOUNTAIN) { };
    Mountain(glm::vec3 pos)
        : Renderable(ModelManager::MOUNTAIN, pos) { };

    ~Mountain(){
        std::cout << "Deleted  renderable" << std::endl;
    }
};


#endif //DEGAMMA_MOUNTAIN_HPP
