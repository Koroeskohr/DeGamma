//
// Created by koro on 14/12/15.
//

#ifndef DEGAMMA_TIMER_HPP
#define DEGAMMA_TIMER_HPP

#include "TimeDefinitions.hpp"

using std::chrono::time_point;
using std::chrono::milliseconds;

namespace glimac {

class Timer {
    friend class TimeManager;

public:
    long elapsedTime() const;

protected:
    Timer();

private:
    const time_point<Clock> mStartTime;
};
    
}



#endif //DEGAMMA_TIMER_HPP
