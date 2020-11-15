#include "TcpServer.h"
#include <thread>
#include <iostream>

TcpServer::TcpServer(uint16_t port_) :
    port(port_),
    socket(new boost::asio::ip::tcp::socket(ioservice)),
    acceptor(new boost::asio::ip::tcp::acceptor(
        ioservice, boost::asio::ip::tcp::endpoint(
            boost::asio::ip::tcp::v4(), port)))
{}

void TcpServer::send(const std::array<int, 2>& message)
{
    try{
        socket->write_some(boost::asio::buffer(message));
    }
    catch(std::exception& e){
        std::cout << "TcpServer::send: " << e.what() << std::endl;
    }
}

std::array<int, 2> TcpServer::waitForMessage()
{
    std::array<int, 2> foo = {-1, -1};
    if(socket->is_open()){
        boost::system::error_code error;
        socket->read_some(boost::asio::buffer(foo), error);
    }
    return foo;
}

void TcpServer::waitForConnection()
{
    std::cout << "Waiting for client" << std::endl;
    if(socket) {
        acceptor->accept(*socket);
    }
    std::cout << "Client connected" << std::endl;
}

TcpServer::~TcpServer()
{
    socket->close();
}
