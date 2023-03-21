#ifndef CHECKERS_CLIENT_H
#define CHECKERS_CLIENT_H

#include <array>
#include <string>

class Client
{
public:
    Client() = default;
    virtual ~Client() = default;

    virtual bool connect() = 0;
    virtual std::array<int, 2> sendAndWaitForResponse(const std::array<int, 2>& message) = 0;

    virtual std::string getIpPort() const = 0;
};
#endif 
