/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__char_connect_socket_fopen_53c.c
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-53c.tmpl.c
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Full path and file name
 * Sink: fopen
 *    BadSink :
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# include <winsock2.h>
# include <windows.h>
# include <direct.h>
# pragma comment(lib, "ws2_32") /* include ws2_32.lib when linking */
# define CLOSE_SOCKET closesocket
# define PATH_SZ FILENAME_MAX
#else /* NOT _WIN32 */
# define INVALID_SOCKET -1
# define SOCKET_ERROR -1
# define CLOSE_SOCKET close
# define SOCKET int
# define PATH_SZ PATH_MAX
#endif

#define TCP_PORT 27015

#ifdef _WIN32
# define FOPEN fopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE36_Absolute_Path_Traversal__char_connect_socket_fopen_53d_bad_sink(char * data);

void CWE36_Absolute_Path_Traversal__char_connect_socket_fopen_53c_bad_sink(char * data)
{
    CWE36_Absolute_Path_Traversal__char_connect_socket_fopen_53d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE36_Absolute_Path_Traversal__char_connect_socket_fopen_53d_goodG2B_sink(char * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE36_Absolute_Path_Traversal__char_connect_socket_fopen_53c_goodG2B_sink(char * data)
{
    CWE36_Absolute_Path_Traversal__char_connect_socket_fopen_53d_goodG2B_sink(data);
}

#endif /* OMITGOOD */
