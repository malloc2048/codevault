#ifndef CODEVAULT_RPG_GAME_H
#define CODEVAULT_RPG_GAME_H

class RpgGame {
public:
    RpgGame() = default;
    ~RpgGame() = default;

    static bool reach_next_level(int experience, int threshold, int reward);

protected:
private:
};
#endif
