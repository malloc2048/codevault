#ifndef QUANTLAB_SYMBOL_H
#define QUANTLAB_SYMBOL_H

#include <map>
#include <string>
#include <vector>

class Symbol
{
public:
    Symbol();

    explicit Symbol(std::vector<std::string> &vec);

    void update(std::vector<std::string> &vec);

    std::string toString();

private:
    std::string name;

    long volume;
    long maxPrice;
    long timeDifferental;
    long newestTimestamp;
    long previousTimestamp;


    std::map<uint64_t, uint64_t> prices;

    long calculateAvg();
    void updateVolume(const std::string& quantityStr);
    void updateTimestamp(const std::string &timestampStr);
    void updatePrice(const std::string &priceStr, const std::string &quantityStr);
};
#endif //QUANTLAB_SYMBOL_H
