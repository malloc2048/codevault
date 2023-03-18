#include <map>
#include <set>
#include "spacex.h"
#include <iostream>
#include <algorithm>

namespace spacex {
    bool launchSequenceChecker(const std::vector<std::string>& systemNames, const std::vector<int>& stepNumbers) {
        std::map<std::string, std::vector<int>> stages;

        for(size_t i = 0; i < systemNames.size(); i++) {
            stages[systemNames[i]].push_back(stepNumbers[i]);
        }

        for(auto& stage: stages) {
            if(!std::is_sorted(stage.second.begin(), stage.second.end())) {
                return false;
            } else {
                auto itr = std::unique(stage.second.begin(), stage.second.end());
                if(itr != stage.second.end()) {
                    return false;
                }
            }
        }
        return true;
    }

    bool validateSeq(std::map<int, std::vector<char>>& seqMap) {
        auto itr = seqMap.begin();
        auto lower = seqMap.begin()->first;

        for(itr++; itr != seqMap.end(); ++itr) {
            auto diff = itr->first - lower;
            if(diff != 1) {
                return false;
            }
            lower = itr->first;
        }
        return true;
    }

    char getHighest(std::vector<char>& data, int n) {
        auto targetCount = (n / 2) + 1;

        for(auto& fragment: data) {
            if(targetCount <= std::count(data.begin(), data.end(), fragment)) {
                return fragment;
            }
        }
        return '\0';
    }

    bool validateFinal(std::map<int, std::vector<char>>& seqMap, int n) {
        auto seqNum = seqMap.size() - 1;
        auto itr = seqMap.find(seqNum);
        if(seqMap.end() == itr){
            return false;
        }

        auto fragment = getHighest(itr->second, n);
        return fragment == '#';
    }

    std::string packetDescrambler(std::vector<int> seq, std::vector<char> fragmentData, int n) {
        std::map<int, std::vector<char>> seqMap;

        for(size_t i = 0; i < seq.size(); i++) {
            seqMap[seq[i]].push_back(fragmentData[i]);
        }

        if(!validateFinal(seqMap, n)) {
            return "";
        }

        if(!validateSeq(seqMap)){
            return "";
        }

        std::string msg;
        for(auto i: seqMap) {
            auto token = getHighest(i.second, n);
            if(token != '\0') {
                msg += token;
            } else {
                return "";
            }
        }
        return msg;
    }
}
