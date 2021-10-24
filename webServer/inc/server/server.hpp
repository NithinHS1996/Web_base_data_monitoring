/***************************************/
/* FILENAME.H - FILENAME.C header file */
/***************************************/

/**********************************************/
/* FILENAME_H   - Prevents redundant includes */
/**********************************************/

/************************************************************************/
/* FILENAME_X   - Defined as null string if #included by FILENAME.C     */
/*              - Defined as extern if #included by any other module    */
/************************************************************************/

/******************/
/* Global Defines */
/******************/

/* Module's public typedefs and defines go here. */
#pragma once
#include <unistd.h>
#include "networking.hpp"
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
    class CServer
    {
    private:
        CListeningSocket *socket;
        virtual void accepter() = 0;
        virtual void handler() = 0;
        virtual void responder() = 0;

    public:
        CServer(int domain, int service, int protocal, int port, u_long interface, int backlog);
        virtual void launch() = 0;
        CListeningSocket *GetSocket();
    };
}
