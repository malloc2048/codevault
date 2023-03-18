#include "spacex.h"
#include <gtest/gtest.h>

TEST(SpaceXTest, LaunchSequenceChecker) {
    ASSERT_TRUE(spacex::launchSequenceChecker(
        std::vector<std::string>({ "stage_1", "stage_2", "dragon", "stage_1", "stage_2", "dragon" }),
        std::vector<int>({ 1, 10, 11, 2, 12, 111 }))
    );

    ASSERT_FALSE(spacex::launchSequenceChecker(
        std::vector<std::string>({ "stage_1", "stage_1", "stage_2", "dragon" }),
        std::vector<int>({ 2, 1, 12, 111 }))
    );

    ASSERT_FALSE(spacex::launchSequenceChecker(
        std::vector<std::string>({ "Falcon 9", "Falcon 9", "Falcon 9", "Falcon 9", "Falcon 9", "Falcon 9" }),
        std::vector<int>({ 1, 3, 5, 7, 7, 9 }))
    );

    ASSERT_TRUE(spacex::launchSequenceChecker(
        std::vector<std::string>({ "Dragon", "Dragon", "Dragon", "Dragon", "dragon", "Dragon", "dragon" }),
        std::vector<int>({ 1, 3, 5, 7, 7, 9, 8 }))
    );

    ASSERT_TRUE(spacex::launchSequenceChecker(
        std::vector<std::string>({ "Dragon" }),
        std::vector<int>({ 1000000000 }))
    );

    ASSERT_FALSE(spacex::launchSequenceChecker(
        std::vector<std::string>({ "CrewDragon", "CrewDragon" }),
        std::vector<int>({ 100, 23 }))
    );

    ASSERT_TRUE(spacex::launchSequenceChecker(
        std::vector<std::string>({ "CrewDragon", "Dragon", "SuperDraco", "Falcon 9" }),
        std::vector<int>({ 4, 3, 2, 1 }))
    );

    ASSERT_FALSE(spacex::launchSequenceChecker(
        std::vector<std::string>(
            { "Dragon", "Falcon 9", "Dragon", "Falcon 9", "Falcon 9", "Dragon", "Dragon", "Dragon", "Falcon 9" }
        ),
        std::vector<int>({ 1, 1, 3, 2, 4, 10, 20, 100, 4 }))
    );
}

TEST(SpaceXTest, PacketDescrambler) {
    ASSERT_STREQ("A+#", spacex::packetDescrambler(
        std::vector<int>({ 1, 1, 0, 0, 0, 2, 2, 2 }),
        std::vector<char>({ '+', '+', 'A', 'A', 'B', '#', '#', '#' }), 3).c_str()
    );

    ASSERT_STREQ("", spacex::packetDescrambler(
        std::vector<int>({ 1, 1, 0, 0, 0, 2, 2, 2 }),
        std::vector<char>({ '+', '+', 'A', 'A', 'B', '#', '#', '#' }), 4).c_str()
    );

    ASSERT_STREQ("", spacex::packetDescrambler(
        std::vector<int>({ 1, 1, 2, 2, 2, 0, 0, 0 }),
        std::vector<char>({ '+', '+', 'A', 'A', 'B', '#', '#', '#' }), 3).c_str()
    );

    ASSERT_STREQ("", spacex::packetDescrambler(
        std::vector<int>({ 1, 1, 2, 2, 2, 0, 0, 0, 4, 4 }),
        std::vector<char>({ '+', '+', 'A', 'A', 'B', '#', '#', '#', '#', '#' }), 3).c_str()
    );

    ASSERT_STREQ("", spacex::packetDescrambler(
        std::vector<int>({ 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2, 0 }),
        std::vector<char>(
            { 'X', '#', 'Y', 'x', '#', 'Y', 'x', '#', 'Y', 'x', '#', 'Y', 'X', '#', 'Y', 'W', '#', 'Y' }), 6).c_str()
    );

    ASSERT_STREQ("", spacex::packetDescrambler(
        std::vector<int>({ 1, 1, 2, 2, 2, 4, 4 }),
        std::vector<char>({ '+', '+', 'A', 'A', 'B', '#', '#' }), 3).c_str()
    );

    ASSERT_STREQ("", spacex::packetDescrambler(
        std::vector<int>({ 0 }),
        std::vector<char>({ '#' }), 3).c_str()
    );

    ASSERT_STREQ("#", spacex::packetDescrambler(
        std::vector<int>({ 0, 0 }),
        std::vector<char>({ '#', '#' }), 3).c_str()
    );

    ASSERT_STREQ("???#", spacex::packetDescrambler(
        std::vector<int>({ 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3 }),
        std::vector<char>({ '#', '?', '?', '?', '?', '?', '?', '?', '#', '?', '#', '#' }), 3).c_str()
    );

    ASSERT_STREQ("", spacex::packetDescrambler(
        std::vector<int>({  }),
        std::vector<char>({  }), 3).c_str()
    );
}
