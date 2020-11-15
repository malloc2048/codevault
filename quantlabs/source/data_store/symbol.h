#ifndef PORTFOLIO_SYMBOL_H
#define PORTFOLIO_SYMBOL_H

#include <map>
#include <string>
#include <vector>

class Symbol {
public:
    Symbol() = default;
    ~Symbol() = default;
    explicit Symbol(std::vector<std::string>& vec);

    std::string to_string();
    void update(const std::vector<std::string>& data);

private:
    std::string name;

    long volume {0};
    long max_price {0};
    long newest_timestamp {0};
    long time_differential {0};
    long previous_timestamp {0};

    std::map<uint64_t, uint64_t> prices;

    decltype(uint32_t()) PRICE_INDEX { 3 };
    decltype(uint32_t()) VOLUME_INDEX { 2 };
    decltype(uint32_t()) TIMESTAMP_INDEX { 0 };

    uint64_t calculate_average();
    void update_volume(const std::string& quantity_string);
    void update_timestamp(const std::string &timestamp_string);
    void update_price(const std::string &price_string, const std::string &quantity_string);
};
#endif
