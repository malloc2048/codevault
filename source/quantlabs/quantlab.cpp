#include "Report/FileReport.h"
#include "DataStore/MapDataStore.h"
#include "DataSource/FileStreamer.h"
#include "StockProcessor.h"

#include <iostream>

int main(int arg, char** argv)
{
    auto datastore = std::make_shared<MapDataStore>();
    auto report = std::make_shared<FileReport>("test/output.csv");
    auto datasource = std::make_shared<FileStreamer>("test/input.csv");

    StockProcessor processor(report, datastore, datasource);
    
    std::cout << "Processing test/input.csv" << std::endl;
    processor.run();

    return 0;
}
