#ifndef PORTFOLIO_STOCK_PROCESSOR_H
#define PORTFOLIO_STOCK_PROCESSOR_H

#include <memory>

class Report;
class DataStore;
class DataSource;

class StockProcessor {
public:
    StockProcessor() = delete;
    ~StockProcessor() = default;
    StockProcessor(
        std::shared_ptr<Report> report, std::shared_ptr<DataStore> data_store, std::shared_ptr<DataSource> data_source);

    void run();

private:
    std::shared_ptr<Report> report;
    std::shared_ptr<DataStore> data_store;
    std::shared_ptr<DataSource> data_source;
};

#endif
