//
// Created by koro on 14/12/15.
//

#ifndef DEGAMMA_TIMEMANAGER_HPP
#define DEGAMMA_TIMEMANAGER_HPP

#include <vector>
#include "TimeDefinitions.hpp"
#include "Timer.hpp"
#include "Countdown.hpp"


namespace glimac {
class TimeManager {
    using std::chrono::time_point;
public:
    TimeManager();

    void updateTimers();
    bool checkCountdowns();
private:
    const time_point<Clock> mProgramStart;
    std::vector<Timer> mTimers;
    std::vector<Countdown> mCountdowns;
};
}



#endif //DEGAMMA_TIMEMANAGER_HPP
