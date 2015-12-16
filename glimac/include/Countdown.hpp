//
// Created by koro on 14/12/15.
//

#ifndef DEGAMMA_COUNTDOWN_HPP
#define DEGAMMA_COUNTDOWN_HPP

#include "TimeDefinitions.hpp"
#include <functional>

using std::chrono::time_point;
using std::chrono::milliseconds;

namespace glimac{
    class Countdown {
    friend class TimeManager;

protected:
    Countdown(milliseconds duration, std::function<void()> callback);

    bool isFinished() const;
    void sendCallback();

private:
    std::function<void()> mCallback;
    const milliseconds mDuration;
    const time_point<Clock> mStartTime;

};
}


#endif //DEGAMMA_COUNTDOWN_HPP
