#include "gtest/gtest.h"

#include "Board.h"


class GameTest : public testing::Test
{
public:
    void SetupInitBoardExpected()
    {
        EXPECTED_BOARD_STR
            << "\t|-------------------------------|" << std::endl
            << "0\t| . | O | . | O | . | O | . | O |" << std::endl
            << "\t|-------------------------------|" << std::endl
            << "8\t| O | . | O | . | O | . | O | . |" << std::endl
            << "\t|-------------------------------|" << std::endl
            << "16\t| . | O | . | O | . | O | . | O |" << std::endl
            << "\t|-------------------------------|" << std::endl
            << "24\t| . | . | . | . | . | . | . | . |" << std::endl
            << "\t|-------------------------------|" << std::endl
            << "32\t| . | . | . | . | . | . | . | . |" << std::endl
            << "\t|-------------------------------|" << std::endl
            << "40\t| X | . | X | . | X | . | X | . |" << std::endl
            << "\t|-------------------------------|" << std::endl
            << "48\t| . | X | . | X | . | X | . | X |" << std::endl
            << "\t|-------------------------------|" << std::endl
            << "56\t| X | . | X | . | X | . | X | . |" << std::endl
            << "\t|-------------------------------|" << std::endl;
    }

    void SetupMoveBoardExpected()
    {
        EXPECTED_BOARD_STR
            << "\t|-------------------------------|" << std::endl
            << "0\t| . | O | . | O | . | O | . | O |" << std::endl
            << "\t|-------------------------------|" << std::endl
            << "8\t| O | . | O | . | O | . | O | . |" << std::endl
            << "\t|-------------------------------|" << std::endl
            << "16\t| . | . | . | O | . | O | . | O |" << std::endl
            << "\t|-------------------------------|" << std::endl
            << "24\t| O | . | . | . | . | . | . | . |" << std::endl
            << "\t|-------------------------------|" << std::endl
            << "32\t| . | . | . | . | . | . | . | . |" << std::endl
            << "\t|-------------------------------|" << std::endl
            << "40\t| X | . | X | . | X | . | X | . |" << std::endl
            << "\t|-------------------------------|" << std::endl
            << "48\t| . | X | . | X | . | X | . | X |" << std::endl
            << "\t|-------------------------------|" << std::endl
            << "56\t| X | . | X | . | X | . | X | . |" << std::endl
            << "\t|-------------------------------|" << std::endl;
    }

    void SetupBlackJumpRed_BoardExpected()
    {
        EXPECTED_BOARD_STR
            << "\t|-------------------------------|" << std::endl
            << "0\t| . | O | . | O | . | O | . | O |" << std::endl
            << "\t|-------------------------------|" << std::endl
            << "8\t| O | . | O | . | O | . | O | . |" << std::endl
            << "\t|-------------------------------|" << std::endl
            << "16\t| . | O | . | X | . | O | . | O |" << std::endl
            << "\t|-------------------------------|" << std::endl
            << "24\t| . | . | . | . | . | . | . | . |" << std::endl
            << "\t|-------------------------------|" << std::endl
            << "32\t| . | . | . | . | . | . | . | . |" << std::endl
            << "\t|-------------------------------|" << std::endl
            << "40\t| . | . | X | . | X | . | X | . |" << std::endl
            << "\t|-------------------------------|" << std::endl
            << "48\t| . | X | . | X | . | X | . | X |" << std::endl
            << "\t|-------------------------------|" << std::endl
            << "56\t| X | . | X | . | X | . | X | . |" << std::endl
            << "\t|-------------------------------|" << std::endl;
    }

    void SetupBlackWinner_BoardExpected()
    {
        EXPECTED_BOARD_STR
            << "\t|-------------------------------|" << std::endl
            << "0\t| . | O | . | O | . | O | . | O |" << std::endl
            << "\t|-------------------------------|" << std::endl
            << "8\t| O | . | O | . | O | . | O | . |" << std::endl
            << "\t|-------------------------------|" << std::endl
            << "16\t| . | O | . | X | . | O | . | O |" << std::endl
            << "\t|-------------------------------|" << std::endl
            << "24\t| . | . | . | . | . | . | . | . |" << std::endl
            << "\t|-------------------------------|" << std::endl
            << "32\t| . | . | . | . | . | . | . | . |" << std::endl
            << "\t|-------------------------------|" << std::endl
            << "40\t| . | . | X | . | X | . | X | . |" << std::endl
            << "\t|-------------------------------|" << std::endl
            << "48\t| . | X | . | X | . | X | . | X |" << std::endl
            << "\t|-------------------------------|" << std::endl
            << "56\t| X | . | X | . | X | . | X | . |" << std::endl
            << "\t|-------------------------------|" << std::endl;
    }

protected:
    Board game;
    std::stringstream EXPECTED_BOARD_STR;
};

TEST_F(GameTest, GameInit)
{
    SetupInitBoardExpected();
    ASSERT_STREQ(EXPECTED_BOARD_STR.str().c_str(), game.getBoardString().c_str());
}

TEST_F(GameTest, ProcessMove)
{
    SetupMoveBoardExpected();
    game.processMove(17, 24);
    ASSERT_STREQ(EXPECTED_BOARD_STR.str().c_str(), game.getBoardString().c_str());
}

TEST_F(GameTest, BlackJumpRed)
{
    SetupBlackJumpRed_BoardExpected();

    game.processMove(19, 26);
    game.processMove(40, 33);
    game.processJump(33, 19);
    ASSERT_STREQ(EXPECTED_BOARD_STR.str().c_str(), game.getBoardString().c_str());
}

TEST_F(GameTest, IllegalMove_BoardUnchanged)
{
    SetupInitBoardExpected();

    game.processJump(1, 0);
    game.processMove(22, 4);
    game.processMove(8, 16);

    ASSERT_STREQ(EXPECTED_BOARD_STR.str().c_str(), game.getBoardString().c_str());
}

TEST_F(GameTest, FindMoveBlack)
{
    auto movePositions = game.findMove(Cell::BLACK);
    ASSERT_EQ(40, movePositions.first);
    ASSERT_EQ(33, movePositions.second);
}

TEST_F(GameTest, FindMoveWhite)
{
    auto movePositions = game.findMove(Cell::WHITE);
    ASSERT_EQ(17, movePositions.first);
    ASSERT_EQ(24, movePositions.second);
}

TEST_F(GameTest, FindJump_None)
{
    auto whiteJump = game.findJump(Cell::WHITE);
    ASSERT_EQ(-1, whiteJump.first);
    ASSERT_EQ(-1, whiteJump.second);

    auto blackJump = game.findJump(Cell::BLACK);
    ASSERT_EQ(-1, blackJump.first);
    ASSERT_EQ(-1, blackJump.second);
}
