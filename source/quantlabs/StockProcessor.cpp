#include "StockProcessor.h"

#include <utility>

StockProcessor::StockProcessor(std::shared_ptr<Report> report_,
    std::shared_ptr<DataStore> datastore_, std::shared_ptr<DataSource> datasource_) :
    report(std::move(report_)), datastore(std::move(datastore_)), datasource(std::move(datasource_))
{}

void StockProcessor::run()
{
    std::string data = datasource->getData();
    while(!data.empty())
    {
        datastore->update(data);
        data = datasource->getData();
    }

    std::vector<std::string> vec;
    datastore->getData(vec);

    for(auto& entry: vec)
        report->addToReport(entry);
}
