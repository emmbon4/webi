/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int_listen_socket_67b.c
Label Definition File: CWE191_Integer_Underflow__int.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Greater than INT_MIN
 * Sinks:
 *    GoodSink: Ensure there is no underflow before performing the subtraction
 *    BadSink : Subtract 1 from data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
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

typedef struct _CWE191_Integer_Underflow__int_listen_socket_67_struct_type
{
    int a;
} CWE191_Integer_Underflow__int_listen_socket_67_struct_type;

#ifndef OMITBAD

void CWE191_Integer_Underflow__int_listen_socket_67b_bad_sink(CWE191_Integer_Underflow__int_listen_socket_67_struct_type my_struct)
{
    int data = my_struct.a;
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
        int result = data - 1;
        printIntLine(result);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE191_Integer_Underflow__int_listen_socket_67b_goodG2B_sink(CWE191_Integer_Underflow__int_listen_socket_67_struct_type my_struct)
{
    int data = my_struct.a;
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an integer underflow */
        int result = data - 1;
        printIntLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE191_Integer_Underflow__int_listen_socket_67b_goodB2G_sink(CWE191_Integer_Underflow__int_listen_socket_67_struct_type my_struct)
{
    int data = my_struct.a;
    {
        int result = 0;
        /* FIX: Add a check to prevent an underflow from occurring */
        if (data > INT_MIN)
        {
            result = data - 1;
            printIntLine(result);
        }
        else
        {
            printLine("Input value is too small to perform arithmetic safely.");
        }
    }
}

#endif /* OMITGOOD */
