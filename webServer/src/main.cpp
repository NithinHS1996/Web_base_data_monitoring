#include "networking.hpp"
#include "testingsocket.hpp"
int main()
{
    std::cout << "starting\n";
    // SOCKET::CBindingSocket BindingSock = SOCKET::CBindingSocket(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY);
    // std::cout << "BindingSock done\n";

    // SOCKET::CListeningSocket ListeningSock = SOCKET::CListeningSocket(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY, 10);
    // std::cout << "ListeningSock done\n";
    SOCKET::TestingServer test;
}