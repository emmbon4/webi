/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__new_char_listen_socket_54a.cpp
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__new.label.xml
Template File: sources-sinks-54a.tmpl.cpp
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Small number greater than zero
 * Sinks:
 *    GoodSink: Allocate memory with new [] and check the size of the memory to be allocated
 *    BadSink : Allocate memory with new [], but incorrectly check the size of the memory to be allocated
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# include <winsock2.h>
# include <windows.h>
# include <direct.h>
# pragma comment(lib, "ws2_32") /* include ws2_32.lib when linking */
# define CLOSE_SOCKET closesocket
#else
# define INVALID_SOCKET -1
# define SOCKET_ERROR -1
# define CLOSE_SOCKET close
# define SOCKET int
#endif

#define TCP_PORT 27015
#define LISTEN_BACKLOG 5
#define CHAR_ARRAY_SIZE sizeof(data)*sizeof(data)

#define HELLO_STRING "hello"

namespace CWE789_Uncontrolled_Mem_Alloc__new_char_listen_socket_54
{

#ifndef OMITBAD

/* bad function declaration */
void bad_sink_b(int data);

void bad()
{
    int data;
    /* Initialize data */
    data = -1;
    {
#ifdef _WIN32
        WSADATA wsa_data;
        int wsa_data_init = 0;
#endif
        int recv_rv;
        struct sockaddr_in s_in;
        SOCKET listen_socket = INVALID_SOCKET;
        SOCKET accept_socket = INVALID_SOCKET;
        char input_buf[CHAR_ARRAY_SIZE];
        do
        {
#ifdef _WIN32
            if (WSAStartup(MAKEWORD(2,2), &wsa_data) != NO_ERROR) break;
            wsa_data_init = 1;
#endif
            listen_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            if (listen_socket == INVALID_SOCKET) break;
            memset(&s_in, 0, sizeof(s_in));
            s_in.sin_family = AF_INET;
            s_in.sin_addr.s_addr = INADDR_ANY;
            s_in.sin_port = htons(TCP_PORT);
            if (bind(listen_socket, (struct sockaddr*)&s_in, sizeof(s_in)) == SOCKET_ERROR) break;
            if (listen(listen_socket, LISTEN_BACKLOG) == SOCKET_ERROR) break;
            accept_socket = accept(listen_socket, NULL, NULL);
            if (accept_socket == SOCKET_ERROR) break;
            /* Abort on error or the connection was closed */
            recv_rv = recv(accept_socket, input_buf, CHAR_ARRAY_SIZE, 0);
            if (recv_rv == SOCKET_ERROR || recv_rv == 0) break;
            /* Convert to int */
            data = atoi(input_buf);
        }
        while (0);
        if (listen_socket != INVALID_SOCKET) CLOSE_SOCKET(listen_socket);
        if (accept_socket != INVALID_SOCKET) CLOSE_SOCKET(accept_socket);
#ifdef _WIN32
        if (wsa_data_init) WSACleanup();
#endif
    }
    bad_sink_b(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink_b(int data);

static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a relatively small number for memory allocation */
    data = 20;
    goodG2B_sink_b(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2G_sink_b(int data);

static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    {
#ifdef _WIN32
        WSADATA wsa_data;
        int wsa_data_init = 0;
#endif
        int recv_rv;
        struct sockaddr_in s_in;
        SOCKET listen_socket = INVALID_SOCKET;
        SOCKET accept_socket = INVALID_SOCKET;
        char input_buf[CHAR_ARRAY_SIZE];
        do
        {
#ifdef _WIN32
            if (WSAStartup(MAKEWORD(2,2), &wsa_data) != NO_ERROR) break;
            wsa_data_init = 1;
#endif
            listen_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            if (listen_socket == INVALID_SOCKET) break;
            memset(&s_in, 0, sizeof(s_in));
            s_in.sin_family = AF_INET;
            s_in.sin_addr.s_addr = INADDR_ANY;
            s_in.sin_port = htons(TCP_PORT);
            if (bind(listen_socket, (struct sockaddr*)&s_in, sizeof(s_in)) == SOCKET_ERROR) break;
            if (listen(listen_socket, LISTEN_BACKLOG) == SOCKET_ERROR) break;
            accept_socket = accept(listen_socket, NULL, NULL);
            if (accept_socket == SOCKET_ERROR) break;
            /* Abort on error or the connection was closed */
            recv_rv = recv(accept_socket, input_buf, CHAR_ARRAY_SIZE, 0);
            if (recv_rv == SOCKET_ERROR || recv_rv == 0) break;
            /* Convert to int */
            data = atoi(input_buf);
        }
        while (0);
        if (listen_socket != INVALID_SOCKET) CLOSE_SOCKET(listen_socket);
        if (accept_socket != INVALID_SOCKET) CLOSE_SOCKET(accept_socket);
#ifdef _WIN32
        if (wsa_data_init) WSACleanup();
#endif
    }
    goodB2G_sink_b(data);
}

void good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE789_Uncontrolled_Mem_Alloc__new_char_listen_socket_54; // so that we can use good and bad easily

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
