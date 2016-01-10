//
// Created by koro on 27/12/15.
//

#include "Airboat.hpp"

Airboat::Airboat()
    : Renderable(ModelManager::AIRBOAT)
{ }

Airboat::Airboat(glm::vec3 pos)
    : Renderable(ModelManager::AIRBOAT, pos)
{ }
