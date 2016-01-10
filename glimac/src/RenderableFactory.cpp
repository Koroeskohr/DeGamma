//
// Created by koro on 03/01/16.
//

#include "RenderableFactory.hpp"


namespace glimac {
    Renderable * RenderableFactory::getByName (std::string &name) {
        Renderable * renderable = nullptr;
        if(name == "airboat")
            renderable = (Renderable*)(new Airboat);
        if(name == "cottage")
            renderable = (Renderable*)(new Cottage);
        if(name == "dragon")
            renderable = (Renderable*)(new Dragon);
        if(name == "horf")
            renderable = (Renderable*)(new Horf);
        if(name == "lantern")
            renderable = (Renderable*)(new Lantern);
        if(name == "wallchambre")
            renderable = (Renderable*)(new WallChambre);
        if(name == "hospitalbed")
            renderable = (Renderable*)(new HospitalBed);
        if(name == "wheelchair")
            renderable = (Renderable*)(new Wheelchair);
        if(name == "crate")
            renderable = (Renderable*)(new Crate);
        if(name == "chevet")
            renderable = (Renderable*)(new Chevet);
        if(name == "tulip")
            renderable = (Renderable*)(new Tulip);


        if (renderable == nullptr)
            throw std::runtime_error("type doesnt exist");

        return renderable;
    }
}
