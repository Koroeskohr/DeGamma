//
// Created by koro on 14/12/15.
//

#ifndef DEGAMMA_TIMER_HPP
#define DEGAMMA_TIMER_HPP

#include "TimeDefinitions.hpp"

namespace glimac {
class Timer {
    friend class TimeManager;
    using std::chrono::time_point;
    using std::chrono::milliseconds;

public:
    long elapsed() const;

protected:
    void updateTime();
    Timer();

private:
    const time_point<Clock> mStartTime;
    milliseconds mElapsedTime;
};
}



#endif //DEGAMMA_TIMER_HPP
