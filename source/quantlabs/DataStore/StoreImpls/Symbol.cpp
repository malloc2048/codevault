#include "Symbol.h"
#include <sstream>

Symbol::Symbol() = default;

Symbol::Symbol(std::vector<std::string> &vec) :
    name(vec[1]), volume(0), maxPrice(0), newestTimestamp(0), previousTimestamp(0), timeDifferental(0)
{
    update(vec);
}

void Symbol::update(std::vector<std::string> &vec)
{
    updateVolume(vec[2]);
    updatePrice(vec[3], vec[2]);
    updateTimestamp(vec[0]);
}

void Symbol::updateTimestamp(const std::string &timestampStr) {
    long timestamp = strtol(timestampStr.c_str(), nullptr, 10);

    if (previousTimestamp > 0)
    {
        if ((timestamp - previousTimestamp) > timeDifferental)
            timeDifferental = timestamp - previousTimestamp;
    }
    previousTimestamp = timestamp;
}

void Symbol::updatePrice(const std::string &priceStr, const std::string &quantityStr) {
    long quantity =  strtol(quantityStr.c_str(), nullptr, 10);
    long price = strtol(priceStr.c_str(), nullptr, 10);

    prices[price] += quantity;
    if (price > maxPrice)
        maxPrice = price;
}

void Symbol::updateVolume(const std::string& quantityStr)
{
    long quantity = strtol(quantityStr.c_str(), nullptr, 10);
    volume += quantity;
}

std::string Symbol::toString()
{
    std::stringstream ss;
    ss << name << "," <<
        timeDifferental << "," <<
        volume << "," <<
        calculateAvg() << "," <<
        maxPrice;
    return ss.str();
}

long Symbol::calculateAvg()
{
    uint64_t avg = 0;
    for(auto& price: prices)
    {
        avg += price.first * price.second;
    }
    return avg / volume;
}
