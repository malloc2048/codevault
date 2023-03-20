#ifndef QUANTLAB_FILEREPORT_H
#define QUANTLAB_FILEREPORT_H

#include <string>
#include <fstream>
#include "Report.h"

class FileReport : public Report
{
public:
    explicit FileReport(const std::string& filename);
    ~FileReport();

    void addToReport(const std::string& entry);

private:
    std::ofstream file;
};
#endif //QUANTLAB_FILEREPORT_H
