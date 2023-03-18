#ifndef QUANTLAB_FILESTREAMER_H
#define QUANTLAB_FILESTREAMER_H

#include <string>
#include <fstream>
#include "DataSource/DataSource.h"

class FileStreamer : public DataSource
{
public:
    explicit FileStreamer(const std::string& filename);
    ~FileStreamer();

    std::string getData();

private:
    std::ifstream file;
};
#endif //QUANTLAB_FILESTREAMER_H
