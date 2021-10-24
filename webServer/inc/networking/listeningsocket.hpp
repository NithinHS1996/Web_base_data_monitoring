/***************************************/
/* listeningsocket.hpp - listeningsocket.cpp header file */
/***************************************/

/******************/
/* Global Defines */
/******************/

/* Module's public typedefs and defines go here. */
#pragma once
#include "bindingsocket.hpp"
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
    class CListeningSocket : public CBindingSocket
    {
    private:
        int iBackLog;
        int iListening;

    public:
        CListeningSocket(int domain, int service, int protocal, int port, u_long interface, int backlog);
        void StartListening();
    };
}