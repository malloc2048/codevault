#ifndef PORTFOLIO_REPORT_H
#define PORTFOLIO_REPORT_H

#include <string>

class Report {
public:
    Report() = default;
    virtual ~Report() = default;
    virtual void add_to_report(const std::string& entry) = 0;
};
#endif
