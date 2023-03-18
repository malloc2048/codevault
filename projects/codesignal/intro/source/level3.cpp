#include "level3.h"
#include <algorithm>

namespace level3 {
    std::vector<std::string> allLongestStrings(std::vector<std::string> inputArray) {
        std::vector<std::string> result;
        std::sort(inputArray.begin(), inputArray.end(), [](const std::string &a, const std::string &b) {
            return a.size() > b.size();
        });

        auto targetSize = inputArray[0].size();
        for (auto &item: inputArray) {
            if (item.size() == targetSize) {
                result.push_back(item);
            } else {
                break;
            }
        }
        return result;
    }

    int commonCharacterCount(std::string s1, std::string s2) {
        return 0;
    }
}
