//
// Created by koro on 27/12/15.
//

#ifndef DEGAMMA_WHEELCHAIR_HPP
#define DEGAMMA_WHEELCHAIR_HPP

#include "Renderable.hpp"

class Wheelchair : public Renderable {
public:
    Wheelchair()
        : Renderable(ModelManager::WHEELCHAIR) { };
    Wheelchair(glm::vec3 pos)
        : Renderable(ModelManager::WHEELCHAIR, pos) { };

    ~Wheelchair(){
        std::cout << "Deleted Dragon renderable" << std::endl;
    }
};


#endif //DEGAMMA_WHEELCHAIR_HPP
