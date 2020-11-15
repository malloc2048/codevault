#include "file_streamer.h"

FileStreamer::FileStreamer(const std::string &filename): file(filename) {

}

std::string FileStreamer::get_data() {
    std::string line;
    if(file.is_open())
        std::getline(file, line);
    return line;
}
