/***************************************/
/* socket.hpp - socket.cpp header file */
/***************************************/

/******************/
/* Global Defines */
/******************/

/* Module's public typedefs and defines go here. */
#pragma once
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
/********************/
/* Global Variables */
/********************/

/* Module's public variables go here. */

/********************/
/* Global Constants */
/********************/

/* Module's public const variables go here. */

/********************/
/* Global Functions */
/********************/

/* Module's public function prototypes go here. */

namespace SOCKET
{
    class CSocket
    {
    private:
        struct sockaddr_in sSockAddres; /*IP socket address struct data*/
        int iSocketFd;                  /*server fd by socket*/
        int iConnection;                /*success check*/

    public:
        /*
    1. AF_NET is used to mention the domain like is it ip4 or ip6 etc
    2. service is used to specify the dgram or stream etc...
    3. if different protocal per service is available we can use but tcp/ip has none
    */
        /*Constructor to make the socket connection*/
        CSocket(int domain, int service_type, int protocal, int port, u_long interface);
        virtual int BindOrConnect(int socket_fd, struct sockaddr_in sock_addr) = 0;
        void TestConnection(int);
        struct sockaddr_in GetAddress();
        int GetSocketFd();
        int GetConnection();
        void SetConnection(int l_iConnection);
    };
}