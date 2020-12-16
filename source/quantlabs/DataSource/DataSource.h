#ifndef QUANTLAB_DATASOURCE_H
#define QUANTLAB_DATASOURCE_H

#include <string>

class DataSource
{
public:
    virtual ~DataSource(){}

    virtual std::string getData() = 0;
};
#endif //QUANTLAB_DATASOURCE_H
