#ifndef PORTFOLIO_FILE_REPORT_H
#define PORTFOLIO_FILE_REPORT_H

#include <fstream>
#include "report.h"

class FileReport: public Report {
public:
    FileReport() = default;
    ~FileReport() override = default;
    explicit FileReport(const std::string& filename);

    void add_to_report(const std::string& entry) override;

private:
    std::ofstream file;
};
#endif
