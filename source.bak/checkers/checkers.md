# Blizzard Checkers
Write a program that can play a game of Checkers Lite with another remote player.

Checkers Lite is the same as American Checkers (also known as English draughts) except there is no promotion to king by
moving a piece to the last rank (therefore stalemate is possible). <br>
Pieces move along diagonals; when available, jumps must be taken in preference to normal moves; and the board is 8 x 8.<br>
See http://en.wikipedia.org/wiki/Checkers if you need a refresher on the rules.

The players are not allowed to make illegal moves. Your program should show the game board after each move. <br>
If there are no legal moves, or one side is eliminated, the game is over. <br>
Suggested board output format as ASCII - use a dot(.) for empty square, X for black, O for white. <br>
The initial board layout might look like this:

    ---------------------------------
    | . | X | . | X | . | X | . | X |
    --------------------------------- 
    | X | . | X | . | X | . | X | . |
    --------------------------------- 
    | . | X | . | X | . | X | . | X |
    ---------------------------------
    | . | . | . | . | . | . | . | . |
    ---------------------------------
    | . | . | . | . | . | . | . | . |
    ---------------------------------
    | O | . | O | . | O | . | O | . |
    ---------------------------------
    | . | O | . | O | . | O | . | O |
    ---------------------------------
    | O | . | O | . | O | . | O | . |
    ---------------------------------

The connection between players should be established with a simple IP:port. We will assume the players are on the same network with no firewall. <br>
This should take you between 1 and 4 hours to complete. <br>
Please present a working program along with the amount of time you spent on the program. <br>
The program should be command line. It can be a Linux or a Windows program.

Note: Windows program is merely a suggestion to fit the 4 hours timeframe. If you can get more done in time, it is <br>
certainly extra credit to exceed the minimum requirements and provide a Linux version.
You must use C++ to complete your task. You are also free to use 3rd party libraries. <br>
Just make sure we can build what you deliver and it is written in C++. <br>
We recommend you include a working binary in your submission but a ready-to-build VS2015 solution will be easiest for us to review.

# Building
Clone this git repo
```
git clone https://github.com/james-maroulis/checkers.git
```
Run the following commands to build
```
cd checkers/build
cmake ..
make
```
## Built Artifacts
### Linux
* build/linux/checkers - this is the built program
* build/linux/checkers_ut - this is the unit test build using google test

### Windows MinGW
* build/mingw/checkers - this is the built program
* build/mingw/checkers_ut - this is the unit test build using google test

## Requirements
* boost asio found in libboost_system
* gtest for unit tests
  Note: The needed libraries are included in the lib folder and headers are in the include folder.
  Note: This was built on both Linux using gcc and Windows using mingw.

# Running the program
* Server - To start the AI server opponent run the program with no arguments (port 42000 will be used)
```
./checkers
```

* Client - To start the client run the program and provide the server IP address
  The port number is currently set in the code and not configurable)
```
./checkers 127.0.0.1
```
* Automatic Client - To start the automatic client that will play against the server with no user imput run the program
  with the server IP adress as the first argument and -a as the second argument
```
./checkers 127.0.0.1 -a
```
# Project Structure
## Cell
This class holds the data related to a single cell on the game board.

## Board
This class contains the logic for managing the checkers board.
The game board constists of a map Cells indexed by position.

## Client
Interface class for clients - implemented by TcpClient

## TcpClient
Implementation of the Client interface using boost::asio to communicate with a server.

## Server
Interface class for servers - implemented by TcpServer

## TcpServer
Implementation of the Server interface using boost::asio to make a TCP server

## Game
Contains the main game logic for running the server or client player

## main
Application entry point 
