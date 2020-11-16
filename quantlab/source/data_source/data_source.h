#ifndef PORTFOLIO_DATA_SOURCE_H
#define PORTFOLIO_DATA_SOURCE_H

#include <string>

class DataSource {
public:
    DataSource() = default;
    virtual ~DataSource() = default;

    virtual std::string get_data() = 0;
};
#endif
