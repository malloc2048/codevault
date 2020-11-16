#include <iostream>
#include "stock_processor.h"
#include "report/file_report.h"
#include "data_source/file_streamer.h"
#include "data_store/data_store_impl/map_data_store.h"

int main() {
    auto data_store = std::make_shared<MapDataStore>();
    auto report = std::make_shared<FileReport>("test/output.csv");
    auto data_source = std::make_shared<FileStreamer>("test/input.csv");

    StockProcessor processor(report, data_store, data_source);

    std::cout << "Processing test/input.csv" << std::endl;
    processor.run();

    return 0;
}
