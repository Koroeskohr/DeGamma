//
// Created by koro on 27/12/15.
//

#ifndef DEGAMMA_CAVE_HPP
#define DEGAMMA_CAVE_HPP

#include "Renderable.hpp"

class Cave : public Renderable {
public:
    Cave()
        : Renderable(ModelManager::CAVE) { };
    Cave(glm::vec3 pos)
        : Renderable(ModelManager::CAVE, pos) { };

    ~Cave(){
        std::cout << "Deleted Cave renderable" << std::endl;
    }
};


#endif //DEGAMMA_CAVE_HPP
