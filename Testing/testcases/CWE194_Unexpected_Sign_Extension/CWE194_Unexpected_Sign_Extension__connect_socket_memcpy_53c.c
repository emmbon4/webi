/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE194_Unexpected_Sign_Extension__connect_socket_memcpy_53c.c
Label Definition File: CWE194_Unexpected_Sign_Extension.label.xml
Template File: sources-sink-53c.tmpl.c
*/
/*
 * @description
 * CWE: 194 Unexpected Sign Extension
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Positive integer
 * Sink: memcpy
 *    BadSink : Copy strings using memcpy() with the length of data
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
#else /* NOT _WIN32 */
# define INVALID_SOCKET -1
# define SOCKET_ERROR -1
# define CLOSE_SOCKET close
# define SOCKET int
#endif

#define TCP_PORT 27015
/* Must be at least 8 for atoi() to work properly */
#define CHAR_ARRAY_SIZE 8

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE194_Unexpected_Sign_Extension__connect_socket_memcpy_53d_bad_sink(short data);

void CWE194_Unexpected_Sign_Extension__connect_socket_memcpy_53c_bad_sink(short data)
{
    CWE194_Unexpected_Sign_Extension__connect_socket_memcpy_53d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE194_Unexpected_Sign_Extension__connect_socket_memcpy_53d_goodG2B_sink(short data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE194_Unexpected_Sign_Extension__connect_socket_memcpy_53c_goodG2B_sink(short data)
{
    CWE194_Unexpected_Sign_Extension__connect_socket_memcpy_53d_goodG2B_sink(data);
}

#endif /* OMITGOOD */
