/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_To_Unsigned_Conversion__listen_socket_malloc_53c.c
Label Definition File: CWE195_Signed_To_Unsigned_Conversion.label.xml
Template File: sources-sink-53c.tmpl.c
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Positive integer
 * Sink: malloc
 *    BadSink : Allocate memory using malloc() with the size of data
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
#else
# define INVALID_SOCKET -1
# define SOCKET_ERROR -1
# define CLOSE_SOCKET close
# define SOCKET int
#endif

#define TCP_PORT 27015
#define LISTEN_BACKLOG 5
#define CHAR_ARRAY_SIZE sizeof(data)*sizeof(data)

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE195_Signed_To_Unsigned_Conversion__listen_socket_malloc_53d_bad_sink(int data);

void CWE195_Signed_To_Unsigned_Conversion__listen_socket_malloc_53c_bad_sink(int data)
{
    CWE195_Signed_To_Unsigned_Conversion__listen_socket_malloc_53d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE195_Signed_To_Unsigned_Conversion__listen_socket_malloc_53d_goodG2B_sink(int data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE195_Signed_To_Unsigned_Conversion__listen_socket_malloc_53c_goodG2B_sink(int data)
{
    CWE195_Signed_To_Unsigned_Conversion__listen_socket_malloc_53d_goodG2B_sink(data);
}

#endif /* OMITGOOD */
