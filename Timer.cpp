//@(#) Timer.cpp


#include "Timer.h"

void Timer::set_Turbo(int turbo) {
    this->booster = turbo;
}

Timer * Timer::getInstance() {
    if (!instanceFlag) {
        theTimer = new Timer();
        instanceFlag = true;
        return theTimer;
    } else {
        return theTimer;
    }
}

void Timer::sleep(long milliseconds) {
    std::clock_t limit;
    std::clock_t now = clock();
    limit = now + milliseconds * CLOCKS_PER_SEC / 1000 / booster;

    while (limit > now) {
        this_time = clock();
        time_counter += (double) (this_time - last_time);
        last_time = this_time;
        if (time_counter > (double) CLOCKS_PER_SEC / booster) {
            time_counter -= (double) CLOCKS_PER_SEC / booster;
            std::cout << "*" << std::flush;
        }
        now = clock();
    }
}


bool Timer::instanceFlag = false;

Timer * Timer::theTimer = 0;
