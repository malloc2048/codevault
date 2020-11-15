#include "gtest/gtest.h"
#include "TcpServer.h"
#include "TcpClient.h"

#include <thread>

void serverThread()
{
    std::cout << "Starting Server" << std::endl;
    TcpServer server(42000);

    server.waitForConnection();

    std::array<int, 2> message = server.waitForMessage();
    std::cout << "From Client: " << message[0] << " " << message[1] << std::endl;
    server.send(message);
}

void clientThread()
{
    std::cout << "Starting Client" << std::endl;
    TcpClient client("127.0.0.1", "42000");

    client.connect();

    std::array<int, 2> message = {0, 9};
    std::array<int, 2> reply = client.sendAndWaitForResponse(message);
    std::cout << "From Server: " << reply[0] << " " << reply[1] << std::endl;
}

TEST(NetworkingTest, ServerExecution)
{
    try {
        std::thread server(serverThread);
        std::thread client(clientThread);

        server.join();
        client.join();
    }
    catch(std::exception& e){
        std::cout << "BAD: " << e.what() << std::endl;
    }
}
