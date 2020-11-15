#ifndef PORTFOLIO_DATA_STORE_H
#define PORTFOLIO_DATA_STORE_H

#include <string>
#include <vector>

class DataStore {
public:
    DataStore() = default;
    virtual ~DataStore() = default;

    virtual void update(const std::string& data) = 0;
    virtual void get_data(std::vector<std::string>& vec) = 0;
};
#endif
