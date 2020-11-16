#ifndef PORTFOLIO_MAP_DATA_STORE_H
#define PORTFOLIO_MAP_DATA_STORE_H

#include <map>
#include "data_store/symbol.h"
#include "data_store/data_store.h"

class MapDataStore: public DataStore {
public:
    MapDataStore() = default;
    ~MapDataStore() override = default;

    void update(const std::string& data) override;
    void get_data(std::vector<std::string>& vec) override;

protected:
    uint64_t element_count() const;
    bool has_element(const std::string& symbol);

private:
    void add_new_symbol(std::vector<std::string>& vec);
    void update_existing_symbol(std::vector<std::string>& vec);
    void to_vector(const std::string& data, std::vector<std::string>& vec);

    std::map<std::string, Symbol> symbols;
};
#endif
