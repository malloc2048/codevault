#include "MapDataStore.h"
#include <sstream>

void MapDataStore::update(const std::string& data)
{
    std::vector<std::string> vec;
    toVector(data, vec);

    if(symbols.end() == symbols.find(vec[1]))
        addNewSymbol(vec);
    else
        updateExistingSymbol(vec);
}

uint64_t MapDataStore::elementCount() const
{
    return symbols.size();
}

bool MapDataStore::hasElement(const std::string &symbol)
{
    return symbols.end() != symbols.find(symbol);
}

void MapDataStore::toVector(const std::string &data, std::vector<std::string>& vec)
{
    std::stringstream ss(data);
    while(ss.good())
    {
        std::string token;
        std::getline(ss, token, ',');
        if(!token.empty())
            vec.push_back(token);
    }
}

void MapDataStore::addNewSymbol(std::vector<std::string> &vec)
{
    Symbol symbol(vec);
    symbols[vec[1]] = symbol;
}

#include <iostream>
void MapDataStore::getData(std::vector<std::string>& vec)
{
    for(auto& element: symbols)
    {
        std::string data = element.second.toString();
        vec.push_back(data);
    }
}

void MapDataStore::updateExistingSymbol(std::vector<std::string> &vec)
{
    symbols[vec[1]].update(vec);
}
