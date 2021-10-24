/*****************************************************************************
*
******************************************************************************
*           C++   M O D U L E   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Module Name:    socket.C
*
*   Project:        Web base data monitoring
*
*   Author:         Nithin HS
*
*   Description:    Creates socket based on the domain, service, protocal and   *                   port
*
*   Portability:    None
*
******************************************************************************
*
*   Public
*   Class:          CSocket
*
*   Public
*   Functions:      None
*
*   Public
*   Variables:      None
*
*   External
*   Functions:      socket()
*
*   External
*   Variables:      sockaddr_in
*
******************************************************************************
*
*   Revision History:
*
*   Date        Rev     By      Description of Revision
*
*   23-10-2021  1.00    NHS     First release
*
*****************************************************************************/

/************************/
/* System Include Files */
/************************/

#include <stdio.h> /* Header file for printf, putchar, etc.        */

/************************/
/* Project Include Files */
/************************/

#include "networking/listeningsocket.hpp"

/******************/
/* Module Defines */
/******************/

/* Module's private typedefs and defines go here. */

/********************/
/* Module Variables */
/********************/

/* Module's private (static) variables go here. */

/********************/
/* Module Constants */
/********************/

/* Module's private (static) const variables go here. */

/*************/
/* Functions */
/*************/
/*****************************************************************************
*           C++   F U N C T I O N   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Function:       CListeningSocket
*
*   Call:           CListeningSocket(int domain, int service, int protocal, int *                   port, u_long interface, int backlog)
*
*   Input(s):       domain -> domain in which the socket should be created
*                   service_type ->service ex:-SOCK_STREAM TCP
*                   protocal -> TCP = 0
*                   port -> port number
*
*   Output(s):      None
*
*   Description:    Function will create socket and updates socket fd
*
*   Calls:          StartListening, TestConnection
*
*****************************************************************************/

SOCKET::CListeningSocket::CListeningSocket(int domain, int service, int protocal, int port, u_long interface, int backlog) : CBindingSocket(domain, service, protocal, port, interface)
{
    iBackLog = backlog;
    StartListening();
    TestConnection(iListening);
}
/*****************************************************************************
*           C++   F U N C T I O N   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Function:       StartListening
*
*   Call:           StartListening()
*
*   Input(s):       None
*
*   Output(s):      None
*
*   Description:    listen to the socket
*
*   Calls:          listen
*
*****************************************************************************/
void SOCKET::CListeningSocket::StartListening()
{
    std::cout << "CListeningSocket\n";

    iListening = listen(GetSocketFd(), iBackLog);
}