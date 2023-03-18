#ifndef CHECKERS_TCPSERVER_H
#define CHECKERS_TCPSERVER_H

#include "Server.h"
#include <cstdint>
#include "boost/asio.hpp"

class TcpServer : public Server
{
public:
    explicit TcpServer(uint16_t port_);
    ~TcpServer();

    void waitForConnection();
    std::array<int, 2> waitForMessage();
    void send(const std::array<int, 2>& message);

private:
    uint16_t port;
    boost::asio::io_service ioservice;
    std::shared_ptr<boost::asio::ip::tcp::socket> socket;
    std::shared_ptr<boost::asio::ip::tcp::acceptor> acceptor;
};

#endif
