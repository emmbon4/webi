/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__short_listen_socket_67a.c
Label Definition File: CWE197_Numeric_Truncation_Error__short.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Less than CHAR_MAX
 * Sinks:
 *    BadSink : Convert data to a char
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
#else
# define INVALID_SOCKET -1
# define SOCKET_ERROR -1
# define CLOSE_SOCKET close
# define SOCKET int
#endif

#define TCP_PORT 27015
#define LISTEN_BACKLOG 5
/* Must be at least 8 for atoi() to work properly */
#define CHAR_ARRAY_SIZE 8

typedef struct _CWE197_Numeric_Truncation_Error__short_listen_socket_67_struct_type
{
    short a;
} CWE197_Numeric_Truncation_Error__short_listen_socket_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE197_Numeric_Truncation_Error__short_listen_socket_67b_bad_sink(CWE197_Numeric_Truncation_Error__short_listen_socket_67_struct_type my_struct);

void CWE197_Numeric_Truncation_Error__short_listen_socket_67_bad()
{
    short data;
    CWE197_Numeric_Truncation_Error__short_listen_socket_67_struct_type my_struct;
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
            /* POTENTIAL FLAW: Use a number input from the network */
            if (recv_rv == SOCKET_ERROR || recv_rv == 0) break;
            /* Convert to short */
            data = (short)atoi(input_buf);
        }
        while (0);
        if (listen_socket != INVALID_SOCKET) CLOSE_SOCKET(listen_socket);
        if (accept_socket != INVALID_SOCKET) CLOSE_SOCKET(accept_socket);
#ifdef _WIN32
        if (wsa_data_init) WSACleanup();
#endif
    }
    my_struct.a = data;
    CWE197_Numeric_Truncation_Error__short_listen_socket_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE197_Numeric_Truncation_Error__short_listen_socket_67b_goodG2B_sink(CWE197_Numeric_Truncation_Error__short_listen_socket_67_struct_type my_struct);

static void goodG2B()
{
    short data;
    CWE197_Numeric_Truncation_Error__short_listen_socket_67_struct_type my_struct;
    /* Initialize data */
    data = -1;
    /* FIX: Use a positive integer less than CHAR_MAX*/
    data = CHAR_MAX-5;
    my_struct.a = data;
    CWE197_Numeric_Truncation_Error__short_listen_socket_67b_goodG2B_sink(my_struct);
}

void CWE197_Numeric_Truncation_Error__short_listen_socket_67_good()
{
    goodG2B();
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
    CWE197_Numeric_Truncation_Error__short_listen_socket_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE197_Numeric_Truncation_Error__short_listen_socket_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
