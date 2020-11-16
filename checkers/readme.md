# Description
A CPP Networked Checkers Game


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
