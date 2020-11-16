#ifndef PORTFOLIO_EXERCISE_STORE_H
#define PORTFOLIO_EXERCISE_STORE_H

#include <map>
#include "data_store/record.h"
#include "data_store/data_store.h"

class ExerciseStore: public DataStore {
public:
    ExerciseStore() = default;
    ~ExerciseStore() override = default;

    void update(const std::string& data) override;
    void get_data(std::vector<std::string>& vec) override;

protected:
    uint64_t element_count() const;
    bool has_element(const std::string& record_name);

private:
    void add_new_record(std::vector<std::string>& vec);
    void update_existing_record(std::vector<std::string>& vec);
    static void to_vector(const std::string& data, std::vector<std::string>& vec);

    std::map<std::string, Record> records;
};

#endif
