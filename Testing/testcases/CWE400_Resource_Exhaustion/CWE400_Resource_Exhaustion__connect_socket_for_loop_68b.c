/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__connect_socket_for_loop_68b.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Assign count to be a relatively small number
 * Sinks: for_loop
 *    GoodSink: Validate count before using it as the loop variant in a for loop
 *    BadSink : Use count as the loop variant in a for loop
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
#define CHAR_ARRAY_SIZE sizeof(count)*sizeof(count)

extern int CWE400_Resource_Exhaustion__connect_socket_for_loop_68_bad_data;
extern int CWE400_Resource_Exhaustion__connect_socket_for_loop_68_goodG2B_data;
extern int CWE400_Resource_Exhaustion__connect_socket_for_loop_68_goodB2G_data;

#ifndef OMITBAD

void CWE400_Resource_Exhaustion__connect_socket_for_loop_68b_bad_sink()
{
    int count = CWE400_Resource_Exhaustion__connect_socket_for_loop_68_bad_data;
    {
        size_t i = 0;
        /* FLAW: For loop using count as the loop variant and no validation */
        for (i = 0; i < (size_t)count; i++)
        {
            printLine("Hello");
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE400_Resource_Exhaustion__connect_socket_for_loop_68b_goodG2B_sink()
{
    int count = CWE400_Resource_Exhaustion__connect_socket_for_loop_68_goodG2B_data;
    {
        size_t i = 0;
        /* FLAW: For loop using count as the loop variant and no validation */
        for (i = 0; i < (size_t)count; i++)
        {
            printLine("Hello");
        }
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE400_Resource_Exhaustion__connect_socket_for_loop_68b_goodB2G_sink()
{
    int count = CWE400_Resource_Exhaustion__connect_socket_for_loop_68_goodB2G_data;
    {
        size_t i = 0;
        /* FIX: Validate $Data% before using it as the for loop variant */
        if (count > 0 && count <= 20)
        {
            for (i = 0; i < (size_t)count; i++)
            {
                printLine("Hello");
            }
        }
    }
}

#endif /* OMITGOOD */
