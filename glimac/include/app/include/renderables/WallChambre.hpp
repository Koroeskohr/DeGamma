//
// Created by koro on 27/12/15.
//

#ifndef DEGAMMA_WALLCHAMBRE_HPP
#define DEGAMMA_WALLCHAMBRE_HPP

#include "Renderable.hpp"

class WallChambre : public Renderable {
public:
    WallChambre()
        : Renderable(ModelManager::WALLCHAMBRE) { };
    WallChambre(glm::vec3 pos)
        : Renderable(ModelManager::WALLCHAMBRE, pos) { };

    ~WallChambre(){
        std::cout << "Deleted Dragon renderable" << std::endl;
    }
};


#endif //DEGAMMA_WALLCHAMBRE_HPP
