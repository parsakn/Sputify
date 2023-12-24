
#include <iomanip>
#include "Duration.h"




    Duration::Duration(const std::string& durationStr) {
        try {
            std::istringstream iss(durationStr);
            char delimiter1, delimiter2;

            if (!(iss >> hours >> delimiter1 >> minutes >> delimiter2 >> seconds) ||
                delimiter1 != ':' || delimiter2 != ':') {
                throw std::invalid_argument("Invalid duration format");
            }
        } catch (const std::exception& e) {
            throw std::invalid_argument("Invalid duration format");
        }
    }


    std::string Duration::formatDuration()  {
        std::ostringstream oss;
        oss << std::setw(2) << std::setfill('0') << hours << ":"
            << std::setw(2) << std::setfill('0') << minutes << ":"
            << std::setw(2) << std::setfill('0') << seconds;
        return oss.str();
    }

int Duration::get_in_seconds() {
    return hours*3600 + minutes*60 + seconds;
}

