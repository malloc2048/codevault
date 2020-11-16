#include <map>
#include <algorithm>
#include "code_fights.h"

int CodeFights::first_duplicate(std::vector<int> a) {
    int duplicateIndex = -1;

    std::map<int, int> found;
    for(int i = 0; i < a.size(); i++) {
        if(found.find(a[i]) == found.end()){
            found[a[i]] = 1;
        } else {
            duplicateIndex = a[i];
            i = a.size();
        }
    }
    return duplicateIndex;
}


char CodeFights::first_not_repeating_character(const std::string& s) {
    int nextRepeatedIdx = 0;
    std::vector<int> counts(26, 0);
    std::vector<char> notRepeatedChars(26, '_');

    for(auto character: s) {
        counts[character - 'a']++;
        if(counts[character - 'a'] == 1) {
            notRepeatedChars[nextRepeatedIdx++] = character;
        }
        else {
            auto a = std::find(notRepeatedChars.begin(), notRepeatedChars.end(), character);
            if(notRepeatedChars.end() != a)
                *a = '_';
        }
    }

    for(auto item: notRepeatedChars){
        if(item != '_'){
            return item;
        }
    }
    return '_';
}

bool not_visited(int col, int row, std::vector<std::pair<int, int>>& visited) {
    auto new_pair = std::make_pair(col, row);
    auto visited_pair = std::find(visited.begin(), visited.end(), new_pair);
    return !(visited.end() != visited_pair);
}

std::vector<std::vector<int>> CodeFights::rotate_image(std::vector<std::vector<int>> a) {
    std::vector<std::pair<int, int>> visited;

    for (int col = 0; col < a.size(); col++){
        for (int row = 0; row < a[col].size(); row++){
            if (not_visited(col, row, visited)) {
                auto newPosition = static_cast<int>(a[row].size() - 1 - col);
                visited.emplace_back(row, newPosition);
                int temp = a[col][row];
                a[col][row] = a[row][a[row].size() - 1 - col];
                a[row][a[row].size() - 1 - col] = temp;
            }
        }
    }
    int temp = a[0][a.size() - 1];

    return a;
}
