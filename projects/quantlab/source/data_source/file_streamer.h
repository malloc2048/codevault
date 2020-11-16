#ifndef PORTFOLIO_FILE_STREAMER_H
#define PORTFOLIO_FILE_STREAMER_H

#include <fstream>
#include "data_source.h"

class FileStreamer: public DataSource {
public:
    FileStreamer() = delete;
    ~FileStreamer() override = default;
    explicit FileStreamer(const std::string& filename);

    std::string get_data() override;

private:
    std::ifstream file;
};
#endif
