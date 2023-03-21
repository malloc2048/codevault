#ifndef CHECKERS_SERVER_H
#define CHECKERS_SERVER_H

#include <array>

class Server
{
public:
    Server() = default;
    virtual ~Server() = default;

    virtual void waitForConnection() = 0;
    virtual std::array<int, 2> waitForMessage() = 0;
    virtual void send(const std::array<int, 2>& message) = 0;
};
#endif 
