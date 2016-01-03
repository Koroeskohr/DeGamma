//
// Created by koro on 03/01/16.
//

#include "RenderableFactory.hpp"


namespace glimac {
    Renderable * RenderableFactory::getByName (std::string &name) {
        Renderable * renderable = nullptr;
        if(name == "airboat")
            renderable = (Renderable*)(new Airboat);



        if (renderable == nullptr)
            throw std::runtime_error("type doesnt exist");

        return renderable;
    }
}
