/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_connect_socket_12.cpp
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__new.label.xml
Template File: sources-sinks-12.tmpl.cpp
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Small number greater than zero
 * Sinks:
 *    GoodSink: Allocate memory with new [] and check the size of the memory to be allocated
 *    BadSink : Allocate memory with new [], but incorrectly check the size of the memory to be allocated
 * Flow Variant: 12 Control flow: if(global_returns_t_or_f())
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

#define HELLO_STRING L"hello"

namespace CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_connect_socket_12
{

#ifndef OMITBAD

void bad()
{
    int data;
    /* Initialize data */
    data = -1;
    if(global_returns_t_or_f())
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
    }
    else
    {
        /* FIX: Use a relatively small number for memory allocation */
        data = 20;
    }
    if(global_returns_t_or_f())
    {
        {
            wchar_t * wchar_t_string;
            /* FLAW: No MAXIMUM limitation for memory allocation and no check to ensure data is large enough
             * for the wcscpy() function to not cause a buffer overflow */
            /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
            if (data > 0)
            {
                wchar_t_string = new wchar_t[data];
                /* Copy a small string into wchar_t_string$ */
                wcscpy(wchar_t_string, HELLO_STRING);
                printWLine(wchar_t_string);
                delete [] wchar_t_string;
            }
            else
            {
                printLine("Input is less than 0");
            }
        }
    }
    else
    {
        {
            wchar_t * wchar_t_string;
            /* FIX: Include a MAXIMUM limitation for memory allocation and a check to ensure data is large enough
             * for the wcscpy() function to not cause a buffer overflow */
            /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
            if ((size_t)data > wcslen(HELLO_STRING) && data < 100)
            {
                wchar_t_string = new wchar_t[data];
                /* Copy a small string into wchar_t_string$ */
                wcscpy(wchar_t_string, HELLO_STRING);
                printWLine(wchar_t_string);
                delete [] wchar_t_string;
            }
            else
            {
                printLine("Input is less than the length of the source string or too large");
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by changing the first "if" so that
   both branches use the BadSource and the second "if" so that both branches
   use the GoodSink */
static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    if(global_returns_t_or_f())
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
    }
    else
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
    }
    if(global_returns_t_or_f())
    {
        {
            wchar_t * wchar_t_string;
            /* FIX: Include a MAXIMUM limitation for memory allocation and a check to ensure data is large enough
             * for the wcscpy() function to not cause a buffer overflow */
            /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
            if ((size_t)data > wcslen(HELLO_STRING) && data < 100)
            {
                wchar_t_string = new wchar_t[data];
                /* Copy a small string into wchar_t_string$ */
                wcscpy(wchar_t_string, HELLO_STRING);
                printWLine(wchar_t_string);
                delete [] wchar_t_string;
            }
            else
            {
                printLine("Input is less than the length of the source string or too large");
            }
        }
    }
    else
    {
        {
            wchar_t * wchar_t_string;
            /* FIX: Include a MAXIMUM limitation for memory allocation and a check to ensure data is large enough
             * for the wcscpy() function to not cause a buffer overflow */
            /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
            if ((size_t)data > wcslen(HELLO_STRING) && data < 100)
            {
                wchar_t_string = new wchar_t[data];
                /* Copy a small string into wchar_t_string$ */
                wcscpy(wchar_t_string, HELLO_STRING);
                printWLine(wchar_t_string);
                delete [] wchar_t_string;
            }
            else
            {
                printLine("Input is less than the length of the source string or too large");
            }
        }
    }
}

/* goodG2B() - use goodsource and badsink by changing the first "if" so that
   both branches use the GoodSource and the second "if" so that both branches
   use the BadSink */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    if(global_returns_t_or_f())
    {
        /* FIX: Use a relatively small number for memory allocation */
        data = 20;
    }
    else
    {
        /* FIX: Use a relatively small number for memory allocation */
        data = 20;
    }
    if(global_returns_t_or_f())
    {
        {
            wchar_t * wchar_t_string;
            /* FLAW: No MAXIMUM limitation for memory allocation and no check to ensure data is large enough
             * for the wcscpy() function to not cause a buffer overflow */
            /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
            if (data > 0)
            {
                wchar_t_string = new wchar_t[data];
                /* Copy a small string into wchar_t_string$ */
                wcscpy(wchar_t_string, HELLO_STRING);
                printWLine(wchar_t_string);
                delete [] wchar_t_string;
            }
            else
            {
                printLine("Input is less than 0");
            }
        }
    }
    else
    {
        {
            wchar_t * wchar_t_string;
            /* FLAW: No MAXIMUM limitation for memory allocation and no check to ensure data is large enough
             * for the wcscpy() function to not cause a buffer overflow */
            /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
            if (data > 0)
            {
                wchar_t_string = new wchar_t[data];
                /* Copy a small string into wchar_t_string$ */
                wcscpy(wchar_t_string, HELLO_STRING);
                printWLine(wchar_t_string);
                delete [] wchar_t_string;
            }
            else
            {
                printLine("Input is less than 0");
            }
        }
    }
}

void good()
{
    goodB2G();
    goodG2B();
}

#endif /* OMITGOOD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE789_Uncontrolled_Mem_Alloc__new_wchar_t_connect_socket_12; // so that we can use good and bad easily

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
