#include "game.h"
#include <thread>
#include <iostream>

void Game::runServer(std::shared_ptr<Server> server)
{
    std::cout << "Starting in server mode" << std::endl;
    server->waitForConnection();

    while(Cell::EMPTY == board.check_for_winner() && !board.check_stalemate(Cell::BLACK) && !board.check_stalemate(
        Cell::WHITE)) {
        std::array<int, 2> message = server->waitForMessage();
        if(abs(message[0] - message[1]) == 14 || abs(message[0] - message[1]) == 18){
            board.process_jump(message[0], message[1]);
        }
        else{
            board.process_move(message[0], message[1]);
        }

        std::array<int, 2> reply = board.perform_next_action(Cell::WHITE);
        server->send(reply);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    if(Cell::EMPTY != board.check_for_winner()){
        std::cout << "And the Winner is: " << (board.check_for_winner() == Cell::BLACK ? "BLACK" : "WHITE") << std::endl;
    }
    else if(board.check_stalemate(Cell::BLACK) && board.check_stalemate(Cell::WHITE)) {
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

    while(Cell::EMPTY == board.check_for_winner() && !board.check_stalemate(Cell::BLACK) && !board.check_stalemate(
        Cell::WHITE)) {
        clearScreen();
        std::cout << "You are the Black pieces represented by X" << std::endl;
        std::cout << board.get_board_string() << std::endl;

        int fromPosition;
        int toPosition;

        std::cout << "What Piece to move: ";
        std::cin >> fromPosition;

        std::cout << "Where to move: ";
        std::cin >> toPosition;

        if(abs(fromPosition - toPosition) == 14 || abs(fromPosition - toPosition) == 18){
            board.process_jump(fromPosition, toPosition);
        }
        else{
            board.process_move(fromPosition, toPosition);
        }

        std::array<int, 2> message = {fromPosition, toPosition};
        auto reply = client->sendAndWaitForResponse(message);

        if(abs(reply[0] - reply[1]) == 14 || abs(reply[0] - reply[1]) == 18){
            board.process_jump(reply[0], reply[1]);
        }
        else{
            board.process_move(reply[0], reply[1]);
        }
    }
    clearScreen();
    std::cout << "Board Over: ";
    if(Cell::EMPTY != board.check_for_winner()){
        std::cout << "And the Winner is: " << (board.check_for_winner() == Cell::BLACK ? "BLACK" : "WHITE") << std::endl;
        std::cout << board.get_board_string() << std::endl;
    }
    else if(board.check_stalemate(Cell::BLACK) || board.check_stalemate(Cell::WHITE)) {
        std::cout << "It's a Stalemate - No more legal moves" << std::endl;
        std::cout << board.get_board_string() << std::endl;
    }
}

void Game::runClientAutomatic(std::shared_ptr<Client> client)
{
    std::cout << "Starting in client mode" << std::endl;
    std::cout << "Connecting to server " << client->getIpPort() << " ..." << std::endl;
    while(!client->connect()){
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    while(Cell::EMPTY == board.check_for_winner() && !board.check_stalemate(Cell::BLACK) && !board.check_stalemate(
        Cell::WHITE)) {
        clearScreen();
        std::cout << "You are the Black pieces represented by X" << std::endl;
        std::cout << board.get_board_string() << std::endl;

        std::array<int, 2> message = board.perform_next_action(Cell::BLACK);
        std::array<int, 2> reply = client->sendAndWaitForResponse(message);
        if(abs(reply[0] - reply[1]) == 14 || abs(reply[0] - reply[1]) == 18){
            board.process_jump(reply[0], reply[1]);
        }
        else{
            board.process_move(reply[0], reply[1]);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    clearScreen();
    std::cout << "Board Over: ";
    if(Cell::EMPTY != board.check_for_winner()){
        std::cout << "And the Winner is: " << (board.check_for_winner() == Cell::BLACK ? "BLACK" : "WHITE") << std::endl;
        std::cout << board.get_board_string() << std::endl;
    }
    else if(board.check_stalemate(Cell::BLACK) || board.check_stalemate(Cell::WHITE)) {
        std::cout << "It's a Stalemate - No more legal moves" << std::endl;
        std::cout << board.get_board_string() << std::endl;
    }
}

void Game::clearScreen()
{
    std::cout << "\033[2J\033[1;1H";
}
