//
// Created by koro on 03/01/16.
//

#ifndef DEGAMMA_RENDERABLEFACTORY_HPP
#define DEGAMMA_RENDERABLEFACTORY_HPP

#include "Renderable.hpp"
#include "app/include/renderables/renderables.hpp"

namespace glimac {

class RenderableFactory {
public:
    static Renderable* getByName(std::string & name);
};

}



#endif //DEGAMMA_RENDERABLEFACTORY_HPP
