//
// Created by Piotr Szczypior on 25/03/2023.
//

#ifndef LIST_TIMER_H
#define LIST_TIMER_H

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Timer {
private:
    high_resolution_clock::time_point endTime;
    high_resolution_clock::time_point initialTime;
public:

    void timeStart();
    void timeStop();
    long long elapsedTime();
};




#endif //LIST_TIMER_H
