#include "Report/FileReport.h"

FileReport::FileReport(const std::string &filename) : file(filename)
{}

FileReport::~FileReport()
{
    if(file.is_open())
        file.close();
}

void FileReport::addToReport(const std::string &entry)
{
    if(file.is_open())
        file << entry << std::endl;
}

