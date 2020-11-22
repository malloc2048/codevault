#ifndef CHECKERS_GAME_H
#define CHECKERS_GAME_H

#include <memory>
#include "client.h"
#include "server.h"
#include "board.h"

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
