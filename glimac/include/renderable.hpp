#pragma once

#include <common.hpp>

using namespace glimac;

namespace Engine {

class Renderable{
private:

public:
    virtual void render() = 0;
};

}
