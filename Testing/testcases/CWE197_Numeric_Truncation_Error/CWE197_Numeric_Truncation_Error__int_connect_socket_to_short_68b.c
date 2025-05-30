/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__int_connect_socket_to_short_68b.c
Label Definition File: CWE197_Numeric_Truncation_Error__int.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Less than CHAR_MAX
 * Sink: to_short
 *    BadSink : Convert data to a short
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

extern int CWE197_Numeric_Truncation_Error__int_connect_socket_to_short_68_bad_data;
extern int CWE197_Numeric_Truncation_Error__int_connect_socket_to_short_68_goodG2B_data;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void CWE197_Numeric_Truncation_Error__int_connect_socket_to_short_68b_bad_sink()
{
    int data = CWE197_Numeric_Truncation_Error__int_connect_socket_to_short_68_bad_data;
    {
        /* POTENTIAL FLAW: Convert data to a short, possibly causing a truncation error */
        short s = (short)data;
        printf("%hd\n", s);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE197_Numeric_Truncation_Error__int_connect_socket_to_short_68b_goodG2B_sink()
{
    int data = CWE197_Numeric_Truncation_Error__int_connect_socket_to_short_68_goodG2B_data;
    {
        /* POTENTIAL FLAW: Convert data to a short, possibly causing a truncation error */
        short s = (short)data;
        printf("%hd\n", s);
    }
}

#endif /* OMITGOOD */
