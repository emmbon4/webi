/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_By_Zero__int_connect_socket_divide_68b.c
Label Definition File: CWE369_Divide_By_Zero__int.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide By Zero
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Non-zero
 * Sink: divide
 *    BadSink : Divide a constant by data
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

extern int CWE369_Divide_By_Zero__int_connect_socket_divide_68_bad_data;
extern int CWE369_Divide_By_Zero__int_connect_socket_divide_68_goodG2B_data;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void CWE369_Divide_By_Zero__int_connect_socket_divide_68b_bad_sink()
{
    int data = CWE369_Divide_By_Zero__int_connect_socket_divide_68_bad_data;
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 / data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE369_Divide_By_Zero__int_connect_socket_divide_68b_goodG2B_sink()
{
    int data = CWE369_Divide_By_Zero__int_connect_socket_divide_68_goodG2B_data;
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 / data);
}

#endif /* OMITGOOD */
