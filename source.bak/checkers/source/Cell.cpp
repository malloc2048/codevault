#include "Cell.h"

Cell::Cell() : state(EMPTY)
{

}

Cell::STATE Cell::getState() const
{
    return state;
}

std::string Cell::getStateStr() const
{
    switch(state){
        case WHITE:
            return "O";
        case BLACK:
            return "X";
        case EMPTY:
        default:
            return ".";
    }
}

void Cell::setState(Cell::STATE newState)
{
    state = newState;
}


