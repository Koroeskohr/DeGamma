//
// Created by koro on 14/12/15.
//

#include "Chronometrable.hpp"

namespace glimac {
    void Chronometrable::addTimer () {
        std::shared_ptr<Timer> t = TimeManager::getInstance()->registerTimer();

        mTimers.push_back(t);
    }
}