#include "rpg_game.h"

bool RpgGame::reach_next_level(int experience, int threshold, int reward){
    return experience + reward >= threshold;
}
