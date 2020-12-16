#include "TcpClient.h"
#include <iostream>

TcpClient::TcpClient(const std::string& server_, const std::string& port_) :
    port(port_), server(server_),
    socket(ioservice)
{}

bool TcpClient::connect()
{
    try {
        boost::asio::ip::tcp::resolver resolver(ioservice);
        boost::asio::ip::tcp::resolver::query query(boost::asio::ip::tcp::v4(), server, port);
        boost::asio::ip::tcp::resolver::iterator itr = resolver.resolve(query);

        boost::asio::connect(socket, itr);
        return true;
    }
    catch(std::exception& e){
        //std::cout << e.what() << std::endl;
        return false;
    }
}

std::array<int, 2> TcpClient::sendAndWaitForResponse(const std::array<int, 2>& message)
{
    std::array<int, 2> reply = {-1, -1};
    try{
        socket.write_some(boost::asio::buffer(message));
        socket.read_some(boost::asio::buffer(reply));
    }
    catch(std::exception& e){
        std::cout << "TcpClient::send: " << e.what() << std::endl;
    }
    return reply;
}

TcpClient::~TcpClient()
{
    socket.close();
}

std::string TcpClient::getIpPort() const
{
    return server + ":" + port;
}
