#include "Game.h"
#include <thread>
#include <iostream>

void Game::runServer(std::shared_ptr<Server> server)
{
    std::cout << "Starting in server mode" << std::endl;
    server->waitForConnection();

    while(Cell::EMPTY == board.checkForWinner() && !board.checkStalemate(Cell::BLACK) && !board.checkStalemate(Cell::WHITE)) {
        std::array<int, 2> message = server->waitForMessage();
        if(abs(message[0] - message[1]) == 14 || abs(message[0] - message[1]) == 18){
            board.processJump(message[0], message[1]);
        }
        else{
            board.processMove(message[0], message[1]);
        }

        std::array<int, 2> reply = board.performNextAction(Cell::WHITE);
        server->send(reply);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    if(Cell::EMPTY != board.checkForWinner()){
        std::cout << "And the Winner is: " << (board.checkForWinner() == Cell::BLACK ? "BLACK" : "WHITE") << std::endl;
    }
    else if(board.checkStalemate(Cell::BLACK) && board.checkStalemate(Cell::WHITE)) {
        std::cout << "It's a Stalemate - No more legal moves" << std::endl;
    }
}

void Game::runClient(std::shared_ptr<Client> client)
{
    std::cout << "Starting in client mode" << std::endl;
    std::cout << "Connecting to server " << client->getIpPort() << " ..." << std::endl;
    while(!client->connect()){
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    while(Cell::EMPTY == board.checkForWinner() && !board.checkStalemate(Cell::BLACK) && !board.checkStalemate(Cell::WHITE)) {
        clearScreen();
        std::cout << "You are the Black pieces represented by X" << std::endl;
        std::cout << board.getBoardString() << std::endl;

        int fromPosition;
        int toPosition;

        std::cout << "What Piece to move: ";
        std::cin >> fromPosition;

        std::cout << "Where to move: ";
        std::cin >> toPosition;

        if(abs(fromPosition - toPosition) == 14 || abs(fromPosition - toPosition) == 18){
            board.processJump(fromPosition, toPosition);
        }
        else{
            board.processMove(fromPosition, toPosition);
        }

        std::array<int, 2> message = {fromPosition, toPosition};
        auto reply = client->sendAndWaitForResponse(message);

        if(abs(reply[0] - reply[1]) == 14 || abs(reply[0] - reply[1]) == 18){
            board.processJump(reply[0], reply[1]);
        }
        else{
            board.processMove(reply[0], reply[1]);
        }
    }
    clearScreen();
    std::cout << "Board Over: ";
    if(Cell::EMPTY != board.checkForWinner()){
        std::cout << "And the Winner is: " << (board.checkForWinner() == Cell::BLACK ? "BLACK" : "WHITE") << std::endl;
        std::cout << board.getBoardString() << std::endl;
    }
    else if(board.checkStalemate(Cell::BLACK) || board.checkStalemate(Cell::WHITE)) {
        std::cout << "It's a Stalemate - No more legal moves" << std::endl;
        std::cout << board.getBoardString() << std::endl;
    }
}

void Game::runClientAutomatic(std::shared_ptr<Client> client)
{
    std::cout << "Starting in client mode" << std::endl;
    std::cout << "Connecting to server " << client->getIpPort() << " ..." << std::endl;
    while(!client->connect()){
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    while(Cell::EMPTY == board.checkForWinner() && !board.checkStalemate(Cell::BLACK) && !board.checkStalemate(Cell::WHITE)) {
        clearScreen();
        std::cout << "You are the Black pieces represented by X" << std::endl;
        std::cout << board.getBoardString() << std::endl;

        std::array<int, 2> message = board.performNextAction(Cell::BLACK);
        std::array<int, 2> reply = client->sendAndWaitForResponse(message);
        if(abs(reply[0] - reply[1]) == 14 || abs(reply[0] - reply[1]) == 18){
            board.processJump(reply[0], reply[1]);
        }
        else{
            board.processMove(reply[0], reply[1]);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    clearScreen();
    std::cout << "Board Over: ";
    if(Cell::EMPTY != board.checkForWinner()){
        std::cout << "And the Winner is: " << (board.checkForWinner() == Cell::BLACK ? "BLACK" : "WHITE") << std::endl;
        std::cout << board.getBoardString() << std::endl;
    }
    else if(board.checkStalemate(Cell::BLACK) || board.checkStalemate(Cell::WHITE)) {
        std::cout << "It's a Stalemate - No more legal moves" << std::endl;
        std::cout << board.getBoardString() << std::endl;
    }
}

void Game::clearScreen()
{
    std::cout << "\033[2J\033[1;1H";
}
