/***************************************/
/* bindingsocket.hpp - bindingsocket.cpp header file */
/***************************************/

/******************/
/* Global Defines */
/******************/

/* Module's public typedefs, includes and defines go here. */
#pragma once
#include "socket.hpp"
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
    class CBindingSocket : public CSocket
    {
    public:
        CBindingSocket(int domain, int service, int protocal, int port, u_long interface);
        int BindOrConnect(int socket_fd, struct sockaddr_in sock_addr);
    };
}