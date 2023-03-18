#ifndef BLIZZARD_GAMESQUARE_H
#define BLIZZARD_GAMESQUARE_H

#include <string>

class Cell
{
public:
    enum STATE{
        WHITE,
        BLACK,
        EMPTY
    };

    Cell();
    ~Cell() = default;

    STATE getState() const;
    std::string getStateStr() const;
    void setState(STATE newState);

private:
    STATE state;
};
#endif