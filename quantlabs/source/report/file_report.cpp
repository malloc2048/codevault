#include "file_report.h"

FileReport::FileReport(const std::string &filename): file(filename) {

}

void FileReport::add_to_report(const std::string &entry) {
    if(file.is_open())
        file << entry << std::endl;
}
