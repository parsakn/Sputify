
#include <iomanip>
#include "Duration.h"


Duration::Duration(int Hours, int Minutes, int Seconds) {
    this->hours = Hours;
    this->minutes = Minutes;
    this->seconds = Seconds;
}



Duration::Duration(const std::string& durationStr) {
        try {
            std::istringstream iss(durationStr);
            char delimiter1, delimiter2;

            if (!(iss >> hours >> delimiter1 >> minutes >> delimiter2 >> seconds) ||
                delimiter1 != DURATIONDELIMITER || delimiter2 != DURATIONDELIMITER) {
                throw std::invalid_argument(BADREQUESTERROR);
            }
        } catch (const std::exception& e) {
            throw std::invalid_argument(BADREQUESTERROR);
        }
    }


    std::string Duration::formatDuration()  {
        std::ostringstream oss;
        oss << std::setw(2) << std::setfill('0') << hours << DURATIONFORMATTER
            << std::setw(2) << std::setfill('0') << minutes << DURATIONFORMATTER
            << std::setw(2) << std::setfill('0') << seconds;
        return oss.str();
    }

int Duration::get_in_seconds() {
    return hours*SECOFHOUR + minutes*SECSOFMIN + seconds;
}

