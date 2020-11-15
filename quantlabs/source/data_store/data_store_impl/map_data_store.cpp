#include <sstream>
#include "map_data_store.h"

void MapDataStore::update(const std::string &data) {
    std::vector<std::string> vec;
    to_vector(data, vec);

    if(symbols.end() == symbols.find(vec[1]))
        add_new_symbol(vec);
    else
        update_existing_symbol(vec);
}

void MapDataStore::get_data(std::vector<std::string> &vec) {
    for(auto& element: symbols) {
        std::string data = element.second.to_string();
        vec.push_back(data);
    }
}

uint64_t MapDataStore::element_count() const {
    return symbols.size();
}

bool MapDataStore::has_element(const std::string &symbol) {
    return symbols.end() != symbols.find(symbol);
}

void MapDataStore::add_new_symbol(std::vector<std::string> &vec) {
    Symbol symbol(vec);
    symbols[vec[1]] = symbol;
}

void MapDataStore::update_existing_symbol(std::vector<std::string> &vec) {
    symbols[vec[1]].update(vec);
}

void MapDataStore::to_vector(const std::string &data, std::vector<std::string> &vec) {
    std::stringstream ss(data);
    while(ss.good()) {
        std::string token;
        std::getline(ss, token, ',');
        if(!token.empty())
            vec.push_back(token);
    }
}
