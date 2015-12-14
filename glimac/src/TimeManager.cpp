//
// Created by koro on 14/12/15.
//

#include "TimeManager.hpp"

namespace glimac {
    TimeManager::TimeManager()
        : mProgramStart(Clock::now()),
          mTimers(),
          mCountdowns()
    {

    }

    void TimeManager::updateTimers() {
        for(Timer& timer : mTimers) {
            timer.updateTime();
        }
    }

    bool TimeManager::checkCountdowns () {
        bool didAThing = false;
        for(Countdown& countdown : mCountdowns) {
            if(countdown.isFinished()){
                // TODO: implement callback
                didAThing = true;
            }
        }

        return didAThing;
    }
}