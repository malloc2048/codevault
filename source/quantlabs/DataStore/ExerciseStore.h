#ifndef QUANTLAB_EXERCISESTORE_H
#define QUANTLAB_EXERCISESTORE_H

#include <map>
#include <string>
#include "DataStore.h"
#include "StoreImpls/Record.h"

class ExerciseStore : public DataStore
{
public:
    void update(const std::string& data) override;
    void getData(std::vector<std::string>& vec) override;

protected:
    uint64_t elementCount() const;
    bool hasElement(const std::string& recordName);

private:
    void addNewRecord(std::vector<std::string>& vec);
    void updateExistingRecord(std::vector<std::string>& vec);

    void toVector(const std::string& data, std::vector<std::string>& vec);

    std::map<std::string, Record> records;
};
#endif //QUANTLAB_EXERCISESTORE_H
