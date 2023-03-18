#include "ExerciseStore.h"
#include <sstream>

void ExerciseStore::update(const std::string &data)
{
    std::vector<std::string> vec;
    toVector(data, vec);

    if(records.end() == records.find(vec[0]))
        addNewRecord(vec);
    else
        updateExistingRecord(vec);
}

void ExerciseStore::getData(std::vector<std::string> &vec)
{
    for(auto& record: records)
    {
        std::string data = record.second.toString();
        vec.push_back(data);
    }
}

uint64_t ExerciseStore::elementCount() const
{
    return records.size();
}

bool ExerciseStore::hasElement(const std::string &recordName)
{
    return records.end() != records.find(recordName);
}

void ExerciseStore::addNewRecord(std::vector<std::string> &vec)
{
    Record record(vec);
    records[vec[0]] = record;
}

void ExerciseStore::updateExistingRecord(std::vector<std::string> &vec)
{

}

void ExerciseStore::toVector(const std::string &data, std::vector<std::string> &vec)
{
    std::stringstream ss(data);
    while(ss.good())
    {
        std::string token;
        std::getline(ss, token, ',');
        if(!token.empty())
            vec.push_back(token);
    }
}
