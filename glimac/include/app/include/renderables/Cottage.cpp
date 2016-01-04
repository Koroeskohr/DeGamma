//
// Created by koro on 27/12/15.
//

#include "Cottage.hpp"

Cottage::Cottage ()
        : Renderable(ResourceManager::CHUB)
{ }

Cottage::Cottage (glm::vec3 pos)
        : Renderable(ResourceManager::CHUB, pos)
{ }
