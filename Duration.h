
#ifndef SPUTIFY_DURATION_H
#define SPUTIFY_DURATION_H

#include <iostream>
#include <sstream>
#include <stdexcept>


class Duration {
private:
    int hours;
    int minutes;
    int seconds;
public:
    explicit Duration(const std::string& durationStr);
    int get_in_seconds();
    std::string formatDuration() ;


};


#endif //SPUTIFY_DURATION_H
