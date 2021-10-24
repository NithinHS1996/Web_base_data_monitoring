
#include "testingsocket.hpp"
#include <string.h>
SOCKET::TestingServer::TestingServer() : CServer(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY, 10)
{
    std::cout << "*******TestingServer*********\n";
    launch();
}

void SOCKET::TestingServer::accepter()
{
    struct sockaddr_in address = GetSocket()->GetAddress();
    int addrlen = sizeof(address);
    iNewSocket = accept(GetSocket()->GetSocketFd(), (struct sockaddr *)&address, (socklen_t *)&addrlen);
    read(iNewSocket, buffer, 30000);
}

void SOCKET::TestingServer::handler()
{
    std::cout << buffer << "\n";
}

void SOCKET::TestingServer::responder()
{
    char *hello = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";
    write(iNewSocket, hello, strlen(hello)); //strlen("hello")
    close(iNewSocket);
}

void SOCKET::TestingServer::launch()
{
    while (true)
    {
        std::cout << "*******Waiting*********\n";
        accepter();
        handler();
        responder();
        std::cout << "**************Done************\n";
    }
}