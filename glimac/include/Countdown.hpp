//
// Created by koro on 14/12/15.
//

#ifndef DEGAMMA_COUNTDOWN_HPP
#define DEGAMMA_COUNTDOWN_HPP

#include "TimeDefinitions.hpp"
#include <functional>

namespace glimac{
class Countdown {
    friend class TimeManager;
    using std::chrono::time_point;
    using std::chrono::milliseconds;

protected:
    Countdown(milliseconds duration, std::function callback);

    template <typename T>
    std::function<T> mCallback;

    bool isFinished() const;

private:
    const milliseconds mDuration;
    const time_point<Clock> mStartTime;

};
}


#endif //DEGAMMA_COUNTDOWN_HPP
