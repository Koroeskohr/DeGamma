//
// Created by koro on 27/12/15.
//

#ifndef DEGAMMA_CHEVET_HPP
#define DEGAMMA_CHEVET_HPP

#include "Renderable.hpp"

class Chevet : public Renderable {
public:
    Chevet()
        : Renderable(ModelManager::CHEVET) { };
    Chevet(glm::vec3 pos)
        : Renderable(ModelManager::CHEVET, pos) { };

    ~Chevet(){
        std::cout << "Deleted Dragon renderable" << std::endl;
    }
};


#endif //DEGAMMA_CHEVET_HPP
