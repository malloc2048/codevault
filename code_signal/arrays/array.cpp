#include <map>
#include "array.h"
#include <algorithm>

int Array::first_duplicate(std::vector<int> a){
    int duplicateIndex = -1;

    std::map<int, int> found;
    for(std::size_t i = 0; i < a.size(); i++)
    {
        if(found.find(a[i]) == found.end()){
            found[a[i]] = 1;
        }
        else{
            duplicateIndex = a[i];
            i = a.size();
        }
    }
    return duplicateIndex;
}

char Array::first_not_repeating_character(const std::string& s) {
    std::map<int, std::vector<char>> countMapReally = {
        {1, std::vector<char>()},
        {2, std::vector<char>()}
    };

    for(auto character: s) {
        auto charPosition = std::find(countMapReally[2].begin(), countMapReally[2].end(), character);

        // has this character been seen multiple times?
        if(charPosition == countMapReally[2].end()) {
            charPosition = std::find(countMapReally[1].begin(), countMapReally[1].end(), character);

            // has this character been seen once?
            if(charPosition != countMapReally[1].end()) {
                countMapReally[2].push_back(character);
                countMapReally[1].erase(charPosition);
            } else { // character never seen before
                countMapReally[1].push_back(character);
            }
        }
    }

    if(!countMapReally[1].empty()) {
        return countMapReally[1][0];
    }
    return '_';
}
