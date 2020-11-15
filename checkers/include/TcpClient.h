#ifndef CHECKERS_TCPCLIENT_H
#define CHECKERS_TCPCLIENT_H

#include "Client.h"
#include <string>
#include "boost/asio.hpp"

class TcpClient : public Client
{
public:
    TcpClient(const std::string& server_, const std::string& port_);
    ~TcpClient() override;

    bool connect() override;
    std::array<int, 2> sendAndWaitForResponse(const std::array<int, 2>& message) override;

    std::string getIpPort() const override;

private:
    std::string port;
    std::string server;

    boost::asio::io_service ioservice;
    boost::asio::ip::tcp::socket socket;
};
#endif
