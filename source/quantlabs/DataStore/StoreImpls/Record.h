#ifndef QUANTLAB_RECORD_H
#define QUANTLAB_RECORD_H

#include <string>
#include <vector>

class Record
{
public:
    Record();
    explicit Record(std::vector<std::string> &vec);

    void update(std::vector<std::string> &vec);

    std::string toString();

protected:
    long updateReps(std::vector<std::string> &vec);
    void calculateTimeDiff(std::vector<std::string> &vec, long currentReps);

private:
    long reps;
    long best;
    long worst;
    std::string name;

    long convertTimeToLongMinutes(const std::string& stringTime) const;
};
#endif
