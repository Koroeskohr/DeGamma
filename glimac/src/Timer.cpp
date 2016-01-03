//
// Created by koro on 14/12/15.
//

#include "Timer.hpp"

namespace glimac {
    Timer::Timer()
        : mStartTime(Clock::now())
    {
    }

    long Timer::elapsedTime() const {
        return std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now() - mStartTime).count();
    }

    void Timer::reset () {
        mStartTime = Clock::now();
    }
}