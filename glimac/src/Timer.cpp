//
// Created by koro on 14/12/15.
//

#include "Timer.hpp"

namespace glimac {
    Timer::Timer()
        : mStartTime(Clock::now()),
          mElapsedTime(std::chrono::milliseconds::zero())
    {
    }

    long Timer::elapsed () const {
        return mElapsedTime.count();
    }

    void Timer::updateTime () {
        mElapsedTime = std::chrono::duration_cast<milliseconds>(Clock::now() - mStartTime);
    }

}