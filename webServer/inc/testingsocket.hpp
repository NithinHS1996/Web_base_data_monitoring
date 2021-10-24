/***************************************/
/* socket.hpp - socket.cpp header file */
/***************************************/

/******************/
/* Global Defines */
/******************/

/* Module's public typedefs and defines go here. */
#pragma once
#include "server/server.hpp"

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
    class TestingServer : public CServer
    {
    private:
        char buffer[300000] = {0};
        int iNewSocket;

        void accepter();
        void handler();
        void responder();

    public:
        TestingServer();
        void launch();
    };
}
