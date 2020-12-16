#include "DataSource/FileStreamer.h"

#include <iostream>
FileStreamer::FileStreamer(const std::string& filename) : file(filename)
{}

FileStreamer::~FileStreamer()
{
    if(file.is_open())
        file.close();
}

std::string FileStreamer::getData()
{
    std::string str;

    if(file.is_open())
        std::getline(file, str);

    return str;
}

