//
// Created by koro on 14/12/15.
//

#ifndef DEGAMMA_TIMER_HPP
#define DEGAMMA_TIMER_HPP

#include "TimeDefinitions.hpp"
#include <iostream>

using std::chrono::time_point;
using std::chrono::milliseconds;

namespace glimac {

class Timer {
    friend class TimeManager;
    friend class Engine;

public:
    long elapsedTime() const;
    void reset();

protected:
    Timer();

private:
    time_point<Clock> mStartTime;
};
    
}



#endif //DEGAMMA_TIMER_HPP
