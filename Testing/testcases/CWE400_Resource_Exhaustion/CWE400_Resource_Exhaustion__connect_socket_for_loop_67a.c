/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__connect_socket_for_loop_67a.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Assign count to be a relatively small number
 * Sinks: for_loop
 *    GoodSink: Validate count before using it as the loop variant in a for loop
 *    BadSink : Use count as the loop variant in a for loop
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# include <winsock2.h>
# include <windows.h>
# include <direct.h>
# pragma comment(lib, "ws2_32") /* include ws2_32.lib when linking */
# define CLOSE_SOCKET closesocket
#else /* NOT _WIN32 */
# define INVALID_SOCKET -1
# define SOCKET_ERROR -1
# define CLOSE_SOCKET close
# define SOCKET int
#endif

#define TCP_PORT 27015
#define CHAR_ARRAY_SIZE sizeof(count)*sizeof(count)

typedef struct _CWE400_Resource_Exhaustion__connect_socket_for_loop_67_struct_type
{
    int a;
} CWE400_Resource_Exhaustion__connect_socket_for_loop_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE400_Resource_Exhaustion__connect_socket_for_loop_67b_bad_sink(CWE400_Resource_Exhaustion__connect_socket_for_loop_67_struct_type my_struct);

void CWE400_Resource_Exhaustion__connect_socket_for_loop_67_bad()
{
    int count;
    CWE400_Resource_Exhaustion__connect_socket_for_loop_67_struct_type my_struct;
    /* Initialize count */
    count = -1;
    {
#ifdef _WIN32
        WSADATA wsa_data;
        int wsa_data_init = 0;
#endif
        int recv_rv;
        struct sockaddr_in s_in;
        SOCKET connect_socket = INVALID_SOCKET;
        char input_buf[CHAR_ARRAY_SIZE];
        do
        {
#ifdef _WIN32
            if (WSAStartup(MAKEWORD(2,2), &wsa_data) != NO_ERROR) break;
            wsa_data_init = 1;
#endif
            connect_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            if (connect_socket == INVALID_SOCKET) break;
            memset(&s_in, 0, sizeof(s_in));
            s_in.sin_family = AF_INET;
            s_in.sin_addr.s_addr = inet_addr("127.0.0.1");
            s_in.sin_port = htons(TCP_PORT);
            if (connect(connect_socket, (struct sockaddr*)&s_in, sizeof(s_in)) == SOCKET_ERROR) break;
            /* Abort on error or the connection was closed, make sure to recv one
             * less char than is in the recv_buf in order to append a terminator */
            recv_rv = recv(connect_socket, input_buf, CHAR_ARRAY_SIZE, 0);
            if (recv_rv == SOCKET_ERROR || recv_rv == 0) break;
            /* Convert to int */
            count = atoi(input_buf);
        }
        while (0);
        if (connect_socket != INVALID_SOCKET) CLOSE_SOCKET(connect_socket);
#ifdef _WIN32
        if (wsa_data_init) WSACleanup();
#endif
    }
    my_struct.a = count;
    CWE400_Resource_Exhaustion__connect_socket_for_loop_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE400_Resource_Exhaustion__connect_socket_for_loop_67b_goodG2B_sink(CWE400_Resource_Exhaustion__connect_socket_for_loop_67_struct_type my_struct);

static void goodG2B()
{
    int count;
    CWE400_Resource_Exhaustion__connect_socket_for_loop_67_struct_type my_struct;
    /* Initialize count */
    count = -1;
    /* FIX: Use a relatively small number */
    count = 20;
    my_struct.a = count;
    CWE400_Resource_Exhaustion__connect_socket_for_loop_67b_goodG2B_sink(my_struct);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE400_Resource_Exhaustion__connect_socket_for_loop_67b_goodB2G_sink(CWE400_Resource_Exhaustion__connect_socket_for_loop_67_struct_type my_struct);

static void goodB2G()
{
    int count;
    CWE400_Resource_Exhaustion__connect_socket_for_loop_67_struct_type my_struct;
    /* Initialize count */
    count = -1;
    {
#ifdef _WIN32
        WSADATA wsa_data;
        int wsa_data_init = 0;
#endif
        int recv_rv;
        struct sockaddr_in s_in;
        SOCKET connect_socket = INVALID_SOCKET;
        char input_buf[CHAR_ARRAY_SIZE];
        do
        {
#ifdef _WIN32
            if (WSAStartup(MAKEWORD(2,2), &wsa_data) != NO_ERROR) break;
            wsa_data_init = 1;
#endif
            connect_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            if (connect_socket == INVALID_SOCKET) break;
            memset(&s_in, 0, sizeof(s_in));
            s_in.sin_family = AF_INET;
            s_in.sin_addr.s_addr = inet_addr("127.0.0.1");
            s_in.sin_port = htons(TCP_PORT);
            if (connect(connect_socket, (struct sockaddr*)&s_in, sizeof(s_in)) == SOCKET_ERROR) break;
            /* Abort on error or the connection was closed, make sure to recv one
             * less char than is in the recv_buf in order to append a terminator */
            recv_rv = recv(connect_socket, input_buf, CHAR_ARRAY_SIZE, 0);
            if (recv_rv == SOCKET_ERROR || recv_rv == 0) break;
            /* Convert to int */
            count = atoi(input_buf);
        }
        while (0);
        if (connect_socket != INVALID_SOCKET) CLOSE_SOCKET(connect_socket);
#ifdef _WIN32
        if (wsa_data_init) WSACleanup();
#endif
    }
    my_struct.a = count;
    CWE400_Resource_Exhaustion__connect_socket_for_loop_67b_goodB2G_sink(my_struct);
}

void CWE400_Resource_Exhaustion__connect_socket_for_loop_67_good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE400_Resource_Exhaustion__connect_socket_for_loop_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE400_Resource_Exhaustion__connect_socket_for_loop_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
