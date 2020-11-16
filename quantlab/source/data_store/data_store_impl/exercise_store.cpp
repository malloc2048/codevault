#include <sstream>
#include "exercise_store.h"

void ExerciseStore::update(const std::string &data) {
    std::vector<std::string> vec;
    to_vector(data, vec);

    if(records.end() == records.find(vec[0]))
        add_new_record(vec);
    else
        update_existing_record(vec);
}

void ExerciseStore::get_data(std::vector<std::string> &vec) {
    for(auto& record: records) {
        std::string data = record.second.to_string();
        vec.push_back(data);
    }
}

uint64_t ExerciseStore::element_count() const {
    return records.size();
}

bool ExerciseStore::has_element(const std::string &record_name) {
    return records.end() != records.find(record_name);
}

void ExerciseStore::add_new_record(std::vector<std::string> &vec) {
    Record record(vec);
    records[vec[0]] = record;
}

void ExerciseStore::update_existing_record(std::vector<std::string> &vec) {

}

void ExerciseStore::to_vector(const std::string &data, std::vector<std::string> &vec) {
    std::stringstream ss(data);
    while(ss.good()) {
        std::string token;
        std::getline(ss, token, ',');
        if(!token.empty())
            vec.push_back(token);
    }
}
