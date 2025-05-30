/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__connect_socket_54c.c
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-54c.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Number greater than ASSERT_VALUE
 * Sink:
 *    BadSink : Assert if n is less than ASSERT_VALUE
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <assert.h>

#define ASSERT_VALUE 5

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

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE617_Reachable_Assertion__connect_socket_54d_bad_sink(int data);

void CWE617_Reachable_Assertion__connect_socket_54c_bad_sink(int data)
{
    CWE617_Reachable_Assertion__connect_socket_54d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE617_Reachable_Assertion__connect_socket_54d_goodG2B_sink(int data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE617_Reachable_Assertion__connect_socket_54c_goodG2B_sink(int data)
{
    CWE617_Reachable_Assertion__connect_socket_54d_goodG2B_sink(data);
}

#endif /* OMITGOOD */
