/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE606_Unchecked_Loop_Condition__char_listen_socket_53c.c
Label Definition File: CWE606_Unchecked_Loop_Condition.label.xml
Template File: sources-sinks-53c.tmpl.c
*/
/*
 * @description
 * CWE: 606 Unchecked Input For Loop Condition
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Input a number less than MAX_LOOP
 * Sinks:
 *    GoodSink: Use data as the for loop variant after checking to see if it is less than MAX_LOOP
 *    BadSink : Use data as the for loop variant without checking its size
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#define MAX_LOOP 10000

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

/* bad function declaration */
void CWE606_Unchecked_Loop_Condition__char_listen_socket_53d_bad_sink(char * data);

void CWE606_Unchecked_Loop_Condition__char_listen_socket_53c_bad_sink(char * data)
{
    CWE606_Unchecked_Loop_Condition__char_listen_socket_53d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE606_Unchecked_Loop_Condition__char_listen_socket_53d_goodG2B_sink(char * data);

void CWE606_Unchecked_Loop_Condition__char_listen_socket_53c_goodG2B_sink(char * data)
{
    CWE606_Unchecked_Loop_Condition__char_listen_socket_53d_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE606_Unchecked_Loop_Condition__char_listen_socket_53d_goodB2G_sink(char * data);

void CWE606_Unchecked_Loop_Condition__char_listen_socket_53c_goodB2G_sink(char * data)
{
    CWE606_Unchecked_Loop_Condition__char_listen_socket_53d_goodB2G_sink(data);
}

#endif /* OMITGOOD */
