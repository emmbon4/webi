/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__wchar_t_listen_socket_fopen_64a.c
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-64a.tmpl.c
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: File name without a period or slash
 * Sinks: fopen
 *    BadSink :
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define BASEPATH L"c:\\temp\\"
#else
#define BASEPATH L"/tmp/"
#endif

#ifdef _WIN32
# include <winsock2.h>
# include <windows.h>
# include <direct.h>
# define PATH_SZ FILENAME_MAX
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

#ifdef _WIN32
# define FOPEN _wfopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE23_Relative_Path_Traversal__wchar_t_listen_socket_fopen_64b_bad_sink(void * void_data_ptr);

void CWE23_Relative_Path_Traversal__wchar_t_listen_socket_fopen_64_bad()
{
    wchar_t * data;
    wchar_t data_buf[FILENAME_MAX] = BASEPATH;
    data = data_buf;
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
            recv_rv = recv(accept_socket, (char *)data+data_len, (int)(FILENAME_MAX-data_len-1), 0);
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
    CWE23_Relative_Path_Traversal__wchar_t_listen_socket_fopen_64b_bad_sink(&data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE23_Relative_Path_Traversal__wchar_t_listen_socket_fopen_64b_goodG2B_sink(void * void_data_ptr);

static void goodG2B()
{
    wchar_t * data;
    wchar_t data_buf[FILENAME_MAX] = BASEPATH;
    data = data_buf;
    /* FIX: File name does not contain a period or slash */
    wcscat(data, L"file.txt");
    CWE23_Relative_Path_Traversal__wchar_t_listen_socket_fopen_64b_goodG2B_sink(&data);
}

void CWE23_Relative_Path_Traversal__wchar_t_listen_socket_fopen_64_good()
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
    CWE23_Relative_Path_Traversal__wchar_t_listen_socket_fopen_64_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE23_Relative_Path_Traversal__wchar_t_listen_socket_fopen_64_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
