#ifndef QUANTLAB_REPORT_H
#define QUANTLAB_REPORT_H

#include <string>

class Report
{
public:
    virtual ~Report(){}

    virtual void addToReport(const std::string& entry) = 0;
};
#endif //QUANTLAB_REPORT_H
