#include <vector>
#include "report/report.h"
#include "stock_processor.h"
#include "data_store/data_store.h"
#include "data_source/data_source.h"

StockProcessor::StockProcessor(
    std::shared_ptr<Report> report, std::shared_ptr<DataStore> data_store, std::shared_ptr<DataSource> data_source):
    report(std::move(report)), data_store(std::move(data_store)), data_source(std::move(data_source)){
}

void StockProcessor::run() {
    std::string data = data_source->get_data();
    while(!data.empty()) {
        data_store->update(data);
        data = data_source->get_data();
    }

    std::vector<std::string> vec;
    data_store->get_data(vec);

    for(auto& entry: vec)
        report->add_to_report(entry);
}
