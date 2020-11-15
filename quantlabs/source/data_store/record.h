#ifndef PORTFOLIO_RECORD_H
#define PORTFOLIO_RECORD_H

#include <string>
#include <vector>

class Record {
public:
    Record() = default;
    ~Record() = default;
    explicit Record(std::vector<std::string> &vec);

    std::string to_string();
    void update(std::vector<std::string> &vec);

protected:
    long update_reps(std::vector<std::string> &vec);
    void calculate_time_differential(std::vector<std::string> &vec, long current_reps);

private:
    long reps {0};
    long worst {0};
    std::string name;
    long best {INT32_MAX};

    long convert_time_to_long_minutes(const std::string& string_time) const;
};
#endif
