//
// Created by koro on 03/01/16.
//

#include "RenderableFactory.hpp"


namespace glimac {
    Renderable * RenderableFactory::getByName (std::string &name) {
        Renderable * renderable;
        if(name == "airboat")
            renderable = (Renderable*)(new Airboat);

        return renderable;
    }
}
