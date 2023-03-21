#ifndef CHECKERS_GAME_H
#define CHECKERS_GAME_H

#include <memory>
#include "Client.h"
#include "Server.h"
#include "Board.h"

class Game
{
public:
    Game() = default;
    ~Game() = default;

    void runServer(std::shared_ptr<Server> server);
    void runClient(std::shared_ptr<Client> client);
    void runClientAutomatic(std::shared_ptr<Client> client);

protected:
    void clearScreen();

private:
    Board board;
};

#endif
