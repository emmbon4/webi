/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_connect_socket_fprintf_45.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Copy a fixed string into data
 * Sinks: fprintf
 *    GoodSink: fprintf with "%s" as the second argument and data as the third
 *    BadSink : fprintf with data as the second argument
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# include <winsock2.h>
# include <windows.h>
# include <direct.h>
# pragma comment(lib, "ws2_32") /* include ws2_32.lib when linking */
# define CLOSE_SOCKET closesocket
# define PATH_SZ 100
#else /* NOT _WIN32 */
# define INVALID_SOCKET -1
# define SOCKET_ERROR -1
# define CLOSE_SOCKET close
# define SOCKET int
# define PATH_SZ PATH_MAX
#endif

#define TCP_PORT 27015

static char * CWE134_Uncontrolled_Format_String__char_connect_socket_fprintf_45_bad_data;
static char * CWE134_Uncontrolled_Format_String__char_connect_socket_fprintf_45_goodG2B_data;
static char * CWE134_Uncontrolled_Format_String__char_connect_socket_fprintf_45_goodB2G_data;

#ifndef OMITBAD

static void bad_sink()
{
    char * data = CWE134_Uncontrolled_Format_String__char_connect_socket_fprintf_45_bad_data;
    /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
    fprintf(stdout, data);
}

void CWE134_Uncontrolled_Format_String__char_connect_socket_fprintf_45_bad()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    {
#ifdef _WIN32
        WSADATA wsa_data;
        int wsa_data_init = 0;
#endif
        int recv_rv;
        struct sockaddr_in s_in;
        char *replace;
        SOCKET connect_socket = INVALID_SOCKET;
        size_t data_len = strlen(data);
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
            recv_rv = recv(connect_socket, (char *)data+data_len, (int)(100-data_len-1), 0);
            if (recv_rv == SOCKET_ERROR || recv_rv == 0) break;
            /* Append null terminator */
            data[recv_rv] = '\0';
            /* Eliminate CRLF */
            replace = strchr(data, '\r');
            if (replace) *replace = '\0';
            replace = strchr(data, '\n');
            if (replace) *replace = '\0';
        }
        while (0);
        if (connect_socket != INVALID_SOCKET) CLOSE_SOCKET(connect_socket);
#ifdef _WIN32
        if (wsa_data_init) WSACleanup();
#endif
    }
    CWE134_Uncontrolled_Format_String__char_connect_socket_fprintf_45_bad_data = data;
    bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B_sink()
{
    char * data = CWE134_Uncontrolled_Format_String__char_connect_socket_fprintf_45_goodG2B_data;
    /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
    fprintf(stdout, data);
}

static void goodG2B()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    /* FIX: Use a fixed string that does not contain a format specifier */
    strcpy(data, "fixedstringtest");
    CWE134_Uncontrolled_Format_String__char_connect_socket_fprintf_45_goodG2B_data = data;
    goodG2B_sink();
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G_sink()
{
    char * data = CWE134_Uncontrolled_Format_String__char_connect_socket_fprintf_45_goodB2G_data;
    /* FIX: Specify the format disallowing a format string vulnerability */
    fprintf(stdout, "%s\n", data);
}

static void goodB2G()
{
    char * data;
    char data_buf[100] = "";
    data = data_buf;
    {
#ifdef _WIN32
        WSADATA wsa_data;
        int wsa_data_init = 0;
#endif
        int recv_rv;
        struct sockaddr_in s_in;
        char *replace;
        SOCKET connect_socket = INVALID_SOCKET;
        size_t data_len = strlen(data);
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
            recv_rv = recv(connect_socket, (char *)data+data_len, (int)(100-data_len-1), 0);
            if (recv_rv == SOCKET_ERROR || recv_rv == 0) break;
            /* Append null terminator */
            data[recv_rv] = '\0';
            /* Eliminate CRLF */
            replace = strchr(data, '\r');
            if (replace) *replace = '\0';
            replace = strchr(data, '\n');
            if (replace) *replace = '\0';
        }
        while (0);
        if (connect_socket != INVALID_SOCKET) CLOSE_SOCKET(connect_socket);
#ifdef _WIN32
        if (wsa_data_init) WSACleanup();
#endif
    }
    CWE134_Uncontrolled_Format_String__char_connect_socket_fprintf_45_goodB2G_data = data;
    goodB2G_sink();
}

void CWE134_Uncontrolled_Format_String__char_connect_socket_fprintf_45_good()
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
    CWE134_Uncontrolled_Format_String__char_connect_socket_fprintf_45_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE134_Uncontrolled_Format_String__char_connect_socket_fprintf_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
