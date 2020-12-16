#ifndef QUANTLAB_DATASTORE_H
#define QUANTLAB_DATASTORE_H

#include <string>
#include <vector>

class DataStore
{
public:
    virtual ~DataStore() = default;

    virtual void update(const std::string& data) = 0;
    virtual void getData(std::vector<std::string>& vec) = 0;
};
#endif //QUANTLAB_DATASTORE_H
