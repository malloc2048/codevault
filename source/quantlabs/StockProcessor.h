#ifndef QUANTLAB_STOCKPROCESSOR_H
#define QUANTLAB_STOCKPROCESSOR_H

#include "Report/Report.h"
#include "DataStore/DataStore.h"
#include "DataSource/DataSource.h"

#include <memory>

class StockProcessor
{
public:
    StockProcessor( std::shared_ptr<Report> report_,
                    std::shared_ptr<DataStore> datastore_,
                    std::shared_ptr<DataSource> datasource_);

    void run();

private:
    std::shared_ptr<Report> report;
    std::shared_ptr<DataStore> datastore;
    std::shared_ptr<DataSource> datasource;
};
#endif //QUANTLAB_STOCKPROCESSOR_H
