/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_connect_socket_multiply_16.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-16.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Small, non-zero
 * Sinks: multiply
 *    GoodSink: Ensure there is no overflow before performing the multiplication
 *    BadSink : Multiply data by 2
 * Flow Variant: 16 Control flow: while(1) and while(0)
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
#define CHAR_ARRAY_SIZE sizeof(data)*sizeof(data)

#ifndef OMITBAD

void CWE190_Integer_Overflow__int_connect_socket_multiply_16_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a small, non-zero value that will not cause an integer overflow in the sinks */
        data = 5;
        break;
    }
    while(1)
    {
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
                data = atoi(input_buf);
            }
            while (0);
            if (connect_socket != INVALID_SOCKET) CLOSE_SOCKET(connect_socket);
#ifdef _WIN32
            if (wsa_data_init) WSACleanup();
#endif
        }
        break;
    }
    while(1)
    {
        {
            /* POTENTIAL FLAW: Multiplying data by 2 could cause an integer overflow */
            int result = data * 2;
            printIntLine(result);
        }
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            int result = -1;
            /* FIX: Add a check to prevent an overflow from occurring */
            if (data <= (INT_MAX/2))
            {
                result = data * 2;
                printIntLine(result);
            }
            else
            {
                printLine("Input value is too large to perform arithmetic safely.");
            }
        }
        break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by changing the conditions on the third and fourth while statements */
static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use a small, non-zero value that will not cause an integer overflow in the sinks */
        data = 5;
        break;
    }
    while(1)
    {
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
                data = atoi(input_buf);
            }
            while (0);
            if (connect_socket != INVALID_SOCKET) CLOSE_SOCKET(connect_socket);
#ifdef _WIN32
            if (wsa_data_init) WSACleanup();
#endif
        }
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* POTENTIAL FLAW: Multiplying data by 2 could cause an integer overflow */
            int result = data * 2;
            printIntLine(result);
        }
        break;
    }
    while(1)
    {
        {
            int result = -1;
            /* FIX: Add a check to prevent an overflow from occurring */
            if (data <= (INT_MAX/2))
            {
                result = data * 2;
                printIntLine(result);
            }
            else
            {
                printLine("Input value is too large to perform arithmetic safely.");
            }
        }
        break;
    }
}

/* goodG2B() - use goodsource and badsink by changing the conditions on the first and second while statements */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    while(1)
    {
        /* FIX: Use a small, non-zero value that will not cause an integer overflow in the sinks */
        data = 5;
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
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
                data = atoi(input_buf);
            }
            while (0);
            if (connect_socket != INVALID_SOCKET) CLOSE_SOCKET(connect_socket);
#ifdef _WIN32
            if (wsa_data_init) WSACleanup();
#endif
        }
        break;
    }
    while(1)
    {
        {
            /* POTENTIAL FLAW: Multiplying data by 2 could cause an integer overflow */
            int result = data * 2;
            printIntLine(result);
        }
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            int result = -1;
            /* FIX: Add a check to prevent an overflow from occurring */
            if (data <= (INT_MAX/2))
            {
                result = data * 2;
                printIntLine(result);
            }
            else
            {
                printLine("Input value is too large to perform arithmetic safely.");
            }
        }
        break;
    }
}

void CWE190_Integer_Overflow__int_connect_socket_multiply_16_good()
{
    goodB2G();
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
    CWE190_Integer_Overflow__int_connect_socket_multiply_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int_connect_socket_multiply_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
