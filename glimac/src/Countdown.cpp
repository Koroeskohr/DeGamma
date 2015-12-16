//
// Created by koro on 14/12/15.
//

#include "Countdown.hpp"

namespace glimac {
    Countdown::Countdown(milliseconds duration, std::function<void()> callback)
        : mCallback(callback),
          mStartTime(Clock::now()),
          mDuration(duration)
    {
    }

    bool Countdown::isFinished() const{
        return std::chrono::duration_cast<milliseconds>(Clock::now() - mStartTime).count() <= 0;
    }

    void Countdown::sendCallback(){
        try {
            mCallback();
        }
        catch (const std::exception&){

        }
    }



}

