/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE187_Partial_Comparison__wchar_t_listen_socket_ncmp_correct_pw_15.c
Label Definition File: CWE187_Partial_Comparison.label.xml
Template File: sources-sinks-15.tmpl.c
*/
/*
 * @description
 * CWE: 187 Partial Comparison
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Provide a matching password
 * Sinks: ncmp_correct_pw
 *    GoodSink: Compare the 2 passwords correctly
 *    BadSink : use wcsncmp() to do password match, but use the length of the correct password
 * Flow Variant: 15 Control flow: switch(6) and switch(7)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define PASSWORD L"Password1234"
/* PASSWORD_SZ must equal the length of PASSWORD */
#define PASSWORD_SZ wcslen(PASSWORD)

#ifdef _WIN32
# include <winsock2.h>
# include <windows.h>
# include <direct.h>
# define PATH_SZ 100
# pragma comment(lib, "ws2_32") /* include ws2_32.lib when linking */
# define CLOSE_SOCKET closesocket
#else
# define PATH_SZ PATH_MAX
# define INVALID_SOCKET -1
# define SOCKET_ERROR -1
# define CLOSE_SOCKET close
# define SOCKET int
#endif

#define TCP_PORT 27015
#define LISTEN_BACKLOG 5

#ifndef OMITBAD

void CWE187_Partial_Comparison__wchar_t_listen_socket_ncmp_correct_pw_15_bad()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    switch(6)
    {
    case 6:
    {
#ifdef _WIN32
        WSADATA wsa_data;
        int wsa_data_init = 0;
#endif
        int recv_rv;
        struct sockaddr_in s_in;
        wchar_t *replace;
        SOCKET listen_socket = INVALID_SOCKET;
        SOCKET accept_socket = INVALID_SOCKET;
        size_t data_len = wcslen(data);
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
            recv_rv = recv(accept_socket, (char *)data+data_len, (int)(100-data_len-1), 0);
            if (recv_rv == SOCKET_ERROR || recv_rv == 0) break;
            /* Append null terminator */
            data[recv_rv] = L'\0';
            /* Eliminate CRLF */
            replace = wcschr(data, L'\r');
            if (replace) *replace = L'\0';
            replace = wcschr(data, L'\n');
            if (replace) *replace = L'\0';
        }
        while (0);
        if (listen_socket != INVALID_SOCKET) CLOSE_SOCKET(listen_socket);
        if (accept_socket != INVALID_SOCKET) CLOSE_SOCKET(accept_socket);
#ifdef _WIN32
        if (wsa_data_init) WSACleanup();
#endif
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use the matching string */
        data = PASSWORD;
        break;
    }
    switch(7)
    {
    case 7:
        /* By using the strlen() of the correct password, you are able to create a partial comparison */
        /* For example if PASSWORD=PASSWORD1234, a user supplied password of PASSWORD123456 will allow access */
        /* POTENTIAL FLAW: Possibly partially compare the two passwords */
        if (wcsncmp(PASSWORD, data, wcslen(PASSWORD)) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* Ideally, we would want to do a check to see if the passwords are of equal length */
        /* FIX: Compare the two passwords completely and correctly */
        if (wcscmp(PASSWORD, data) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
        break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second switch to switch(8) */
static void goodB2G1()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    switch(6)
    {
    case 6:
    {
#ifdef _WIN32
        WSADATA wsa_data;
        int wsa_data_init = 0;
#endif
        int recv_rv;
        struct sockaddr_in s_in;
        wchar_t *replace;
        SOCKET listen_socket = INVALID_SOCKET;
        SOCKET accept_socket = INVALID_SOCKET;
        size_t data_len = wcslen(data);
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
            recv_rv = recv(accept_socket, (char *)data+data_len, (int)(100-data_len-1), 0);
            if (recv_rv == SOCKET_ERROR || recv_rv == 0) break;
            /* Append null terminator */
            data[recv_rv] = L'\0';
            /* Eliminate CRLF */
            replace = wcschr(data, L'\r');
            if (replace) *replace = L'\0';
            replace = wcschr(data, L'\n');
            if (replace) *replace = L'\0';
        }
        while (0);
        if (listen_socket != INVALID_SOCKET) CLOSE_SOCKET(listen_socket);
        if (accept_socket != INVALID_SOCKET) CLOSE_SOCKET(accept_socket);
#ifdef _WIN32
        if (wsa_data_init) WSACleanup();
#endif
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use the matching string */
        data = PASSWORD;
        break;
    }
    switch(8)
    {
    case 7:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* By using the strlen() of the correct password, you are able to create a partial comparison */
        /* For example if PASSWORD=PASSWORD1234, a user supplied password of PASSWORD123456 will allow access */
        /* POTENTIAL FLAW: Possibly partially compare the two passwords */
        if (wcsncmp(PASSWORD, data, wcslen(PASSWORD)) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
        break;
    default:
        /* Ideally, we would want to do a check to see if the passwords are of equal length */
        /* FIX: Compare the two passwords completely and correctly */
        if (wcscmp(PASSWORD, data) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
        break;
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second switch */
static void goodB2G2()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    switch(6)
    {
    case 6:
    {
#ifdef _WIN32
        WSADATA wsa_data;
        int wsa_data_init = 0;
#endif
        int recv_rv;
        struct sockaddr_in s_in;
        wchar_t *replace;
        SOCKET listen_socket = INVALID_SOCKET;
        SOCKET accept_socket = INVALID_SOCKET;
        size_t data_len = wcslen(data);
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
            recv_rv = recv(accept_socket, (char *)data+data_len, (int)(100-data_len-1), 0);
            if (recv_rv == SOCKET_ERROR || recv_rv == 0) break;
            /* Append null terminator */
            data[recv_rv] = L'\0';
            /* Eliminate CRLF */
            replace = wcschr(data, L'\r');
            if (replace) *replace = L'\0';
            replace = wcschr(data, L'\n');
            if (replace) *replace = L'\0';
        }
        while (0);
        if (listen_socket != INVALID_SOCKET) CLOSE_SOCKET(listen_socket);
        if (accept_socket != INVALID_SOCKET) CLOSE_SOCKET(accept_socket);
#ifdef _WIN32
        if (wsa_data_init) WSACleanup();
#endif
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Use the matching string */
        data = PASSWORD;
        break;
    }
    switch(7)
    {
    case 7:
        /* Ideally, we would want to do a check to see if the passwords are of equal length */
        /* FIX: Compare the two passwords completely and correctly */
        if (wcscmp(PASSWORD, data) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* By using the strlen() of the correct password, you are able to create a partial comparison */
        /* For example if PASSWORD=PASSWORD1234, a user supplied password of PASSWORD123456 will allow access */
        /* POTENTIAL FLAW: Possibly partially compare the two passwords */
        if (wcsncmp(PASSWORD, data, wcslen(PASSWORD)) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
        break;
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first switch to switch(5) */
static void goodG2B1()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
#ifdef _WIN32
        WSADATA wsa_data;
        int wsa_data_init = 0;
#endif
        int recv_rv;
        struct sockaddr_in s_in;
        wchar_t *replace;
        SOCKET listen_socket = INVALID_SOCKET;
        SOCKET accept_socket = INVALID_SOCKET;
        size_t data_len = wcslen(data);
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
            recv_rv = recv(accept_socket, (char *)data+data_len, (int)(100-data_len-1), 0);
            if (recv_rv == SOCKET_ERROR || recv_rv == 0) break;
            /* Append null terminator */
            data[recv_rv] = L'\0';
            /* Eliminate CRLF */
            replace = wcschr(data, L'\r');
            if (replace) *replace = L'\0';
            replace = wcschr(data, L'\n');
            if (replace) *replace = L'\0';
        }
        while (0);
        if (listen_socket != INVALID_SOCKET) CLOSE_SOCKET(listen_socket);
        if (accept_socket != INVALID_SOCKET) CLOSE_SOCKET(accept_socket);
#ifdef _WIN32
        if (wsa_data_init) WSACleanup();
#endif
    }
    break;
    default:
        /* FIX: Use the matching string */
        data = PASSWORD;
        break;
    }
    switch(7)
    {
    case 7:
        /* By using the strlen() of the correct password, you are able to create a partial comparison */
        /* For example if PASSWORD=PASSWORD1234, a user supplied password of PASSWORD123456 will allow access */
        /* POTENTIAL FLAW: Possibly partially compare the two passwords */
        if (wcsncmp(PASSWORD, data, wcslen(PASSWORD)) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* Ideally, we would want to do a check to see if the passwords are of equal length */
        /* FIX: Compare the two passwords completely and correctly */
        if (wcscmp(PASSWORD, data) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
        break;
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first switch */
static void goodG2B2()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    switch(6)
    {
    case 6:
        /* FIX: Use the matching string */
        data = PASSWORD;
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
#ifdef _WIN32
        WSADATA wsa_data;
        int wsa_data_init = 0;
#endif
        int recv_rv;
        struct sockaddr_in s_in;
        wchar_t *replace;
        SOCKET listen_socket = INVALID_SOCKET;
        SOCKET accept_socket = INVALID_SOCKET;
        size_t data_len = wcslen(data);
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
            recv_rv = recv(accept_socket, (char *)data+data_len, (int)(100-data_len-1), 0);
            if (recv_rv == SOCKET_ERROR || recv_rv == 0) break;
            /* Append null terminator */
            data[recv_rv] = L'\0';
            /* Eliminate CRLF */
            replace = wcschr(data, L'\r');
            if (replace) *replace = L'\0';
            replace = wcschr(data, L'\n');
            if (replace) *replace = L'\0';
        }
        while (0);
        if (listen_socket != INVALID_SOCKET) CLOSE_SOCKET(listen_socket);
        if (accept_socket != INVALID_SOCKET) CLOSE_SOCKET(accept_socket);
#ifdef _WIN32
        if (wsa_data_init) WSACleanup();
#endif
    }
    break;
    }
    switch(7)
    {
    case 7:
        /* By using the strlen() of the correct password, you are able to create a partial comparison */
        /* For example if PASSWORD=PASSWORD1234, a user supplied password of PASSWORD123456 will allow access */
        /* POTENTIAL FLAW: Possibly partially compare the two passwords */
        if (wcsncmp(PASSWORD, data, wcslen(PASSWORD)) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* Ideally, we would want to do a check to see if the passwords are of equal length */
        /* FIX: Compare the two passwords completely and correctly */
        if (wcscmp(PASSWORD, data) == 0)
            printLine("Access granted");
        else
            printLine("Access denied!");
        break;
    }
}

void CWE187_Partial_Comparison__wchar_t_listen_socket_ncmp_correct_pw_15_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
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
    CWE187_Partial_Comparison__wchar_t_listen_socket_ncmp_correct_pw_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE187_Partial_Comparison__wchar_t_listen_socket_ncmp_correct_pw_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
