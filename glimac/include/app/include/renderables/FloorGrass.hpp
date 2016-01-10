//
// Created by koro on 27/12/15.
//

#ifndef DEGAMMA_FLOORGRASS_HPP
#define DEGAMMA_FLOORGRASS_HPP

#include "Renderable.hpp"

class FloorGrass : public Renderable {
public:
    FloorGrass()
        : Renderable(ModelManager::FLOORGRASS) { };
    FloorGrass(glm::vec3 pos)
        : Renderable(ModelManager::FLOORGRASS, pos) { };

    ~FloorGrass(){
        std::cout << "Deleted Dragon renderable" << std::endl;
    }
};


#endif //DEGAMMA_FLOORGRASS_HPP
