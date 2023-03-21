#ifndef QUANTLAB_MAPDATASTORE_H
#define QUANTLAB_MAPDATASTORE_H

#include <map>
#include <string>
#include <vector>
#include "DataStore/StoreImpls/Symbol.h"
#include "DataStore/DataStore.h"

class MapDataStore : public DataStore
{
public:
    void update(const std::string& data) override;
    void getData(std::vector<std::string>& vec) override;

protected:
    uint64_t elementCount() const;
    bool hasElement(const std::string& symbol);

private:
    void addNewSymbol(std::vector<std::string>& vec);
    void updateExistingSymbol(std::vector<std::string>& vec);

    void toVector(const std::string& data, std::vector<std::string>& vec);

    std::map<std::string, Symbol> symbols;
};
#endif //QUANTLAB_MAPDATASTORE_H
