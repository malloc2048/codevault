#include "Game.h"
#include "TcpClient.h"
#include "TcpServer.h"

int main(int argc, char** argv)
{
    Game game;
    if(argc == 3){
        auto client = std::make_shared<TcpClient>(argv[1], "42000");
        game.runClientAutomatic(client);
    }
    else if(argc == 2){
        auto client = std::make_shared<TcpClient>(argv[1], "42000");
        game.runClient(client);
    }
    else {
        auto server = std::make_shared<TcpServer>(42000);
        game.runServer(server);
    }

    return 0;
}
