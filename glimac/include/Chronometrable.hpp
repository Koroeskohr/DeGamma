//
// Created by koro on 14/12/15.
//

#ifndef DEGAMMA_CHRONOMETRABLE_HPP
#define DEGAMMA_CHRONOMETRABLE_HPP

#include <vector>
#include <memory>

#include "TimeDefinitions.hpp"
#include "Timer.hpp"
#include "TimeManager.hpp"

namespace glimac {

class Chronometrable {
public:
    void addTimer();

    virtual ~Chronometrable () = 0;

private:
    std::vector<std::shared_ptr<Timer>> mTimers;
};

}

#endif //DEGAMMA_CHRONOMETRABLE_HPP
