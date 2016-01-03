//
// Created by koro on 14/12/15.
//

#include "TimeManager.hpp"


namespace glimac {

    TimeManager* TimeManager::mInstance = nullptr;

    TimeManager* TimeManager::getInstance()
    {
        if (!mInstance) {
            mInstance = new TimeManager;
        }
        return mInstance;
    }

    TimeManager::TimeManager()
        : mProgramStart(Clock::now()),
          mTimers(),
          mCountdowns()
    { }

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

    std::shared_ptr<Timer> TimeManager::registerTimer(){
        std::shared_ptr<Timer> timer(new Timer);
        mTimers.push_back(timer);

        return timer;
    }

}
