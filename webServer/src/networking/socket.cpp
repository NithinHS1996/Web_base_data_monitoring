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

#include "networking/socket.hpp"

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
*   Function:       CSocket
*
*   Call:           CSocket(int domain, int service_type, int protocal, int *                   port, u_long interface)
*
*   Input(s):       domain -> domain in which the socket should be created
*                   service_type ->service ex:-SOCK_STREAM TCP
*
*   Output(s):      None
*
*   Description:    Function will create socket and updates socket fd
*
*   Calls:          socket
*
*****************************************************************************/
SOCKET::CSocket::CSocket(int domain, int service_type, int protocal, int port, u_long interface)
{
    /*IP socket address struct data*/
    sSockAddres.sin_family = domain;
    sSockAddres.sin_port = htons(port);
    sSockAddres.sin_addr.s_addr = htonl(interface);
    iSocketFd = socket(domain, service_type, protocal); /*creates an unbound  
    socket in a communications domain*/
    std::cout << "isockfd" << iSocketFd << __func__ << "\n";
    TestConnection(iSocketFd);
}

/*****************************************************************************
*           C++   F U N C T I O N   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Function:       TestConnection
*
*   Call:           TestConnection(int item_to_test)
*
*   Input(s):       item_to_test -> item to be tested
*
*   Output(s):      None
*
*   Description:    Function checks the value for negative data
*
*   Calls:          perror
*
*****************************************************************************/
void SOCKET::CSocket::TestConnection(int item_to_test)
{
    /*to test the connection status*/
    if (item_to_test < 0)
    {
        perror("Failed to connect");
        exit(EXIT_FAILURE);
    }
}

/*****************************************************************************
*           C++   F U N C T I O N   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Function:       GetAddress
*
*   Call:           GetAddress()
*
*   Input(s):       None
*
*   Output(s):      struct sockaddr_in
*
*   Description:    Function returns struct sockaddr_in
*
*   Calls:          None
*
*****************************************************************************/
struct sockaddr_in SOCKET::CSocket::GetAddress()
{
    return sSockAddres;
};
/*****************************************************************************
*           C++   F U N C T I O N   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Function:       GetSocketFd
*
*   Call:           GetSocketFd()
*
*   Input(s):       None
*
*   Output(s):      int iSocketFd
*
*   Description:    Function returns int iSocketFd
*
*   Calls:          None
*
*****************************************************************************/
int SOCKET::CSocket::GetSocketFd()
{
    return iSocketFd;
}
/*****************************************************************************
*           C++   F U N C T I O N   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Function:       GetConnection
*
*   Call:           GetConnection()
*
*   Input(s):       None
*
*   Output(s):      int iConnection
*
*   Description:    Function returns int iConnection
*
*   Calls:          None
*
*****************************************************************************/
int SOCKET::CSocket::GetConnection()
{
    return iConnection;
}
/*****************************************************************************
*           C++   F U N C T I O N   S P E C I F I C A T I O N   B L O C K
******************************************************************************
*
*   Function:       SetConnection
*
*   Call:           SetConnection(int l_iConnection)
*
*   Input(s):       int l_iConnection
*
*   Output(s):      None
*
*   Description:    Function updates iConnection
*
*   Calls:          None
*
*****************************************************************************/
void SOCKET::CSocket::SetConnection(int l_iConnection)
{
    iConnection = l_iConnection;
}
