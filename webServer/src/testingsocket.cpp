
#include "testingsocket.hpp"
#include "files.hpp"
#include <string.h>
SOCKET::TestingServer::TestingServer() : CServer(AF_INET, SOCK_STREAM, 0, 8008, INADDR_ANY, 10)
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
    string html;
    char *img;
    Readimg readimg("/home/nithin/Everything/Linux_with_c++/webServer/test.jpg");
    File file("/home/nithin/Everything/Linux_with_c++/webServer/index.html");
    html = file.readEverything();
    img = readimg.readImg();
    string hello = "HTTP/1.1 200 Okay\r\nContent-Type: text/html;    //for html charset=ISO-8859-4 \r\n\r\n" + html;
    //write(iNewSocket, hello.c_str(), strlen(hello.c_str()));
    hello = "HTTP/1.1 200 Okay\r\nContent-Type: image/png\r\n\r\n"; //; Content-Transfer-Encoding: binary; charset=ISO-8859-4
    cout << "bytes1" << strlen(img) << "\n";

    write(iNewSocket, hello.c_str(), strlen(hello.c_str())); //strlen("hello")// + img
    write(iNewSocket, img, 80459);
    close(iNewSocket);
    delete img;
}
//        <img src="test.jpg">
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