
#ifndef SPUTIFY_DURATION_H
#define SPUTIFY_DURATION_H

#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Manual.h"

class Duration {
private:
    int hours;
    int minutes;
    int seconds;
public:
    Duration(int Hours, int Minutes, int Seconds);
    Duration(const std::string& durationStr);
    int get_in_seconds();
    std::string formatDuration() ;


};


#endif //SPUTIFY_DURATION_H
