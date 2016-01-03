//
// Created by koro on 14/12/15.
//

#ifndef DEGAMMA_TIMEMANAGER_HPP
#define DEGAMMA_TIMEMANAGER_HPP

#include <vector>
#include <memory>

#include "TimeDefinitions.hpp"
#include "Timer.hpp"
#include "Countdown.hpp"

using std::chrono::time_point;

namespace glimac {
class TimeManager {
public:
    static TimeManager* getInstance();

    TimeManager(TimeManager const&) = delete;
    void operator=(TimeManager const&) = delete;

    bool checkCountdowns();

    std::shared_ptr<Timer> registerTimer();

private:
    TimeManager();
    static TimeManager* mInstance;
    const time_point<Clock> mProgramStart;
    std::vector<std::shared_ptr<Timer>> mTimers;
    std::vector<Countdown> mCountdowns;
};
}



#endif //DEGAMMA_TIMEMANAGER_HPP
