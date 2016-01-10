//
// Created by koro on 27/12/15.
//

#ifndef DEGAMMA_HORF_HPP
#define DEGAMMA_HORF_HPP

#include "Renderable.hpp"

class Horf : public Renderable {
public:
    Horf()
        : Renderable(ModelManager::HORF) { };
    Horf(glm::vec3 pos)
        : Renderable(ModelManager::HORF, pos) { };

    ~Horf(){
        std::cout << "Deleted HORF renderable" << std::endl;
    }
};


#endif //DEGAMMA_HORF_HPP
