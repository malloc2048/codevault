#include <sstream>
#include "symbol.h"

Symbol::Symbol(std::vector<std::string> &vec) : name(vec[0]){
    update(vec);
}

std::string Symbol::to_string() {
    std::stringstream ss;
    ss << name << "," <<
       time_differential << "," <<
       volume << "," <<
       calculate_average() << "," <<
       max_price;
    return ss.str();
}

void Symbol::update(const std::vector<std::string> &data) {
    update_volume(data[VOLUME_INDEX]);
    update_timestamp(data[TIMESTAMP_INDEX]);
    update_price(data[PRICE_INDEX], data[VOLUME_INDEX]);
}

uint64_t Symbol::calculate_average() {
    uint64_t avg = 0;
    for(auto& price: prices) {
        avg += price.first * price.second;
    }
    return avg / volume;
}

void Symbol::update_volume(const std::string& quantity_string) {
    long quantity = strtol(quantity_string.c_str(), nullptr, 10);
    volume += quantity;
}

void Symbol::update_timestamp(const std::string &timestamp_string) {
    long timestamp = strtol(timestamp_string.c_str(), nullptr, 10);

    if (previous_timestamp > 0)
    {
        if ((timestamp - previous_timestamp) > time_differential)
            time_differential = timestamp - previous_timestamp;
    }
    previous_timestamp = timestamp;
}

void Symbol::update_price(const std::string &price_string, const std::string &quantity_string) {
    long quantity =  strtol(quantity_string.c_str(), nullptr, 10);
    long price = strtol(price_string.c_str(), nullptr, 10);

    prices[price] += quantity;
    if (price > max_price)
        max_price = price;
}
