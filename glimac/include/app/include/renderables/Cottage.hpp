//
// Created by koro on 03/01/16.
//

#ifndef DEGAMMA_CHUB_HPP
#define DEGAMMA_CHUB_HPP

#include "Renderable.hpp"

class Cottage : public Renderable {
public:
    Cottage ();
    Cottage (glm::vec3 pos);

    ~Cottage () {
        std::cout << "Deleted cottage renderable" << std::endl;
    }
};


#endif //DEGAMMA_CHUB_HPP
