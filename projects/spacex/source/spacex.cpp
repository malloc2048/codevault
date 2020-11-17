#include "spacex.h"
#include <gtest/gtest.h>

bool SpaceX::launch_sequence_checker(const std::vector<std::string>& system_names, const std::vector<int>& step_numbers) {
    std::map<std::string, std::vector<int>> stages;

    for(size_t i = 0; i < system_names.size(); i++) {
        stages[system_names[i]].push_back(step_numbers[i]);
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

bool validate_seq(std::map<int, std::vector<char>>& seqMap) {
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

char get_highest(std::vector<char>& data, int n) {
    auto targetCount = (n / 2) + 1;

    for(auto& fragment: data) {
        if(targetCount <= std::count(data.begin(), data.end(), fragment)) {
            return fragment;
        }
    }
    return '\0';
}

bool validate_final(std::map<int, std::vector<char>>& seqMap, int n) {
    auto seqNum = seqMap.size() - 1;
    auto itr = seqMap.find(seqNum);
    if(seqMap.end() == itr){
        return false;
    }

    auto fragment = get_highest(itr->second, n);
    return fragment == '#';
}

std::string SpaceX::packet_descrambler(std::vector<int> seq, std::vector<char> fragment_data, int n) {
    std::map<int, std::vector<char>> seqMap;

    for(size_t i = 0; i < seq.size(); i++) {
        seqMap[seq[i]].push_back(fragment_data[i]);
    }

    if(!validate_final(seqMap, n)) {
        return "";
    }

    if(!validate_seq(seqMap)){
        return "";
    }

    std::string msg;
    for(auto i: seqMap) {
        auto token = get_highest(i.second, n);
        if(token != '\0') {
            msg += token;
        } else {
            return "";
        }
    }
    return msg;
}

TEST(SpaceX, LaunchSequenceChecker) {
    ASSERT_TRUE(SpaceX::launch_sequence_checker(
        std::vector<std::string>({ "stage_1", "stage_2", "dragon", "stage_1", "stage_2", "dragon" }),
        std::vector<int>({ 1, 10, 11, 2, 12, 111 }))
    );

    ASSERT_FALSE(SpaceX::launch_sequence_checker(
        std::vector<std::string>({ "stage_1", "stage_1", "stage_2", "dragon" }),
        std::vector<int>({ 2, 1, 12, 111 }))
    );

    ASSERT_FALSE(SpaceX::launch_sequence_checker(
        std::vector<std::string>({ "Falcon 9", "Falcon 9", "Falcon 9", "Falcon 9", "Falcon 9", "Falcon 9" }),
        std::vector<int>({ 1, 3, 5, 7, 7, 9 }))
    );

    ASSERT_TRUE(SpaceX::launch_sequence_checker(
        std::vector<std::string>({ "Dragon", "Dragon", "Dragon", "Dragon", "dragon", "Dragon", "dragon" }),
        std::vector<int>({ 1, 3, 5, 7, 7, 9, 8 }))
    );

    ASSERT_TRUE(SpaceX::launch_sequence_checker(
        std::vector<std::string>({ "Dragon" }),
        std::vector<int>({ 1000000000 }))
    );

    ASSERT_FALSE(SpaceX::launch_sequence_checker(
        std::vector<std::string>({ "CrewDragon", "CrewDragon" }),
        std::vector<int>({ 100, 23 }))
    );

    ASSERT_TRUE(SpaceX::launch_sequence_checker(
        std::vector<std::string>({ "CrewDragon", "Dragon", "SuperDraco", "Falcon 9" }),
        std::vector<int>({ 4, 3, 2, 1 }))
    );

    ASSERT_FALSE(SpaceX::launch_sequence_checker(
        std::vector<std::string>(
            { "Dragon", "Falcon 9", "Dragon", "Falcon 9", "Falcon 9", "Dragon", "Dragon", "Dragon", "Falcon 9" }
        ),
        std::vector<int>({ 1, 1, 3, 2, 4, 10, 20, 100, 4 }))
    );
}

TEST(SpaceX, PacketDescrambler) {
    ASSERT_STREQ("A+#", SpaceX::packet_descrambler(
        std::vector<int>({ 1, 1, 0, 0, 0, 2, 2, 2 }),
        std::vector<char>({ '+', '+', 'A', 'A', 'B', '#', '#', '#' }), 3).c_str()
    );

    ASSERT_STREQ("", SpaceX::packet_descrambler(
        std::vector<int>({ 1, 1, 0, 0, 0, 2, 2, 2 }),
        std::vector<char>({ '+', '+', 'A', 'A', 'B', '#', '#', '#' }), 4).c_str()
    );

    ASSERT_STREQ("", SpaceX::packet_descrambler(
        std::vector<int>({ 1, 1, 2, 2, 2, 0, 0, 0 }),
        std::vector<char>({ '+', '+', 'A', 'A', 'B', '#', '#', '#' }), 3).c_str()
    );

    ASSERT_STREQ("", SpaceX::packet_descrambler(
        std::vector<int>({ 1, 1, 2, 2, 2, 0, 0, 0, 4, 4 }),
        std::vector<char>({ '+', '+', 'A', 'A', 'B', '#', '#', '#', '#', '#' }), 3).c_str()
    );

    ASSERT_STREQ("", SpaceX::packet_descrambler(
        std::vector<int>({ 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0 }),
        std::vector<char>(
            { 'X', '#', 'Y', 'x', '#', 'Y', 'x', '#', 'Y', 'x', '#', 'Y', 'X', '#', 'Y', 'W', '#', 'Y' }), 6).c_str()
    );

    ASSERT_STREQ("", SpaceX::packet_descrambler(
        std::vector<int>({ 1, 1, 2, 2, 2, 4, 4 }),
        std::vector<char>({ '+', '+', 'A', 'A', 'B', '#', '#' }), 3).c_str()
    );

    ASSERT_STREQ("", SpaceX::packet_descrambler(
        std::vector<int>({ 0 }),
        std::vector<char>({ '#' }), 3).c_str()
    );

    ASSERT_STREQ("#", SpaceX::packet_descrambler(
        std::vector<int>({ 0, 0 }),
        std::vector<char>({ '#', '#' }), 3).c_str()
    );

    ASSERT_STREQ("???#", SpaceX::packet_descrambler(
        std::vector<int>({ 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3 }),
        std::vector<char>({ '#', '?', '?', '?', '?', '?', '?', '?', '#', '?', '#', '#' }), 3).c_str()
    );

    ASSERT_STREQ("", SpaceX::packet_descrambler(
        std::vector<int>({  }),
        std::vector<char>({  }), 3).c_str()
    );
}
