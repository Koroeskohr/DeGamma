//
// Created by koro on 27/12/15.
//

#include "Cottage.hpp"

Cottage::Cottage ()
        : Renderable(ModelManager::COTTAGE)
{ }

Cottage::Cottage (glm::vec3 pos)
        : Renderable(ModelManager::COTTAGE, pos)
{ }
