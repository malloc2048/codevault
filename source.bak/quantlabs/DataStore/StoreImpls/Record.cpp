#include "Record.h"
#include <sstream>

Record::Record() = default;

Record::Record(std::vector<std::string> &vec) :
    reps(0), best(INT32_MAX), worst(0), name(vec[0])
{
    update(vec);
}

void Record::update(std::vector<std::string> &vec)
{
    long currentReps = updateReps(vec);
    calculateTimeDiff(vec, currentReps);
}

std::string Record::toString()
{
    //<exercise>,<best>,<worst>,<improvement>
    std::stringstream ss;
    ss << name << "," << best << "," << worst << "," << reps;
    return ss.str();
}

long Record::updateReps(std::vector<std::string> &vec)
{
    long currentReps = strtol(vec[3].c_str(), nullptr, 10);
    reps += currentReps;
    return currentReps;
}

void Record::calculateTimeDiff(std::vector<std::string> &vec, long currentReps)
{
    long start = convertTimeToLongMinutes(vec[1]);
    long end = convertTimeToLongMinutes(vec[2]);

    long diff = (end - start) / currentReps;

    if(diff < best)
        best = diff;
    if(diff > worst)
        worst = diff;
}

long Record::convertTimeToLongMinutes(const std::string& stringTime) const
{
    std::stringstream ss(stringTime);
    std::string hours;
    std::string minutes;
    getline(ss, hours, ':');
    getline(ss, minutes, ':');
    return strtol(hours.c_str(), nullptr, 10) * 60 + strtol(minutes.c_str(), nullptr, 10);
}
