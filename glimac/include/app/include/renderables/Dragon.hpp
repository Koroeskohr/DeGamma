//
// Created by koro on 27/12/15.
//

#ifndef DEGAMMA_DRAGON_HPP
#define DEGAMMA_DRAGON_HPP

#include "Renderable.hpp"

class Dragon : public Renderable {
public:
    Dragon()
        : Renderable(ModelManager::DRAGON) { };
    Dragon(glm::vec3 pos)
        : Renderable(ModelManager::DRAGON, pos) { };

    ~Dragon(){
        std::cout << "Deleted Dragon renderable" << std::endl;
    }
};


#endif //DEGAMMA_DRAGON_HPP
