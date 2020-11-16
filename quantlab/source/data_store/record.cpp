#include <sstream>
#include "record.h"

Record::Record(std::vector<std::string> &vec): name(vec[0]) {
 update(vec);
}

std::string Record::to_string() {
    // <exercise>,<best>,<worst>,<improvement>
    std::stringstream ss;
    ss << name << "," << best << "," << worst << "," << reps;
    return ss.str();
}

void Record::update(std::vector<std::string> &vec) {
    long current_reps = update_reps(vec);
    calculate_time_differential(vec, current_reps);
}

long Record::update_reps(std::vector<std::string> &vec) {
    long current_reps = strtol(vec[3].c_str(), nullptr, 10);
    reps += current_reps;
    return current_reps;}

void Record::calculate_time_differential(std::vector<std::string> &vec, long current_reps) {
    long start = convert_time_to_long_minutes(vec[1]);
    long end = convert_time_to_long_minutes(vec[2]);

    long diff = (end - start) / current_reps;

    if(diff < best)
        best = diff;
    if(diff > worst)
        worst = diff;
}

long Record::convert_time_to_long_minutes(const std::string &string_time) const {
    std::stringstream ss(string_time);
    std::string hours;
    std::string minutes;
    getline(ss, hours, ':');
    getline(ss, minutes, ':');
    return strtol(hours.c_str(), nullptr, 10) * 60 + strtol(minutes.c_str(), nullptr, 10);
}
