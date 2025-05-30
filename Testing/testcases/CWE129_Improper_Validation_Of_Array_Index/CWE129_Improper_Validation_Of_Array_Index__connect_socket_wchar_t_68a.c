/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE129_Improper_Validation_Of_Array_Index__connect_socket_wchar_t_68a.c
Label Definition File: CWE129_Improper_Validation_Of_Array_Index.label.xml
Template File: sources-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 129 Improper Validation of Array Index
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Larger than zero but less than 10
 * Sinks: wchar_t
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
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

int CWE129_Improper_Validation_Of_Array_Index__connect_socket_wchar_t_68_bad_data;
int CWE129_Improper_Validation_Of_Array_Index__connect_socket_wchar_t_68_goodG2B_data;
int CWE129_Improper_Validation_Of_Array_Index__connect_socket_wchar_t_68_goodB2G_data;

#ifndef OMITBAD

/* bad function declaration */
void CWE129_Improper_Validation_Of_Array_Index__connect_socket_wchar_t_68b_bad_sink();

void CWE129_Improper_Validation_Of_Array_Index__connect_socket_wchar_t_68_bad()
{
    int data;
    data = -1; /* Initialize data */
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
    CWE129_Improper_Validation_Of_Array_Index__connect_socket_wchar_t_68_bad_data = data;
    CWE129_Improper_Validation_Of_Array_Index__connect_socket_wchar_t_68b_bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE129_Improper_Validation_Of_Array_Index__connect_socket_wchar_t_68b_goodG2B_sink();
void CWE129_Improper_Validation_Of_Array_Index__connect_socket_wchar_t_68b_goodB2G_sink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    data = -1; /* Initialize data */
    /* FIX: Use a value greater than 0, but less than 10 to avoid attempting to
     * access an index of the array in the sink that is out-of-bounds */
    data = 7;
    CWE129_Improper_Validation_Of_Array_Index__connect_socket_wchar_t_68_goodG2B_data = data;
    CWE129_Improper_Validation_Of_Array_Index__connect_socket_wchar_t_68b_goodG2B_sink();
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    int data;
    data = -1; /* Initialize data */
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
    CWE129_Improper_Validation_Of_Array_Index__connect_socket_wchar_t_68_goodB2G_data = data;
    CWE129_Improper_Validation_Of_Array_Index__connect_socket_wchar_t_68b_goodB2G_sink();
}

void CWE129_Improper_Validation_Of_Array_Index__connect_socket_wchar_t_68_good()
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
    CWE129_Improper_Validation_Of_Array_Index__connect_socket_wchar_t_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE129_Improper_Validation_Of_Array_Index__connect_socket_wchar_t_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
