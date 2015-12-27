//
// Created by koro on 27/12/15.
//

#include "Airboat.hpp"

Airboat::Airboat()
    : Renderable(ResourceManager::AIRBOAT)
{ }

Airboat::Airboat(glm::vec3 pos)
    : Renderable(ResourceManager::AIRBOAT, pos)
{ }
