/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_To_Buffer_Overflow__new_connect_socket_64b.cpp
Label Definition File: CWE680_Integer_Overflow_To_Buffer_Overflow__new.label.xml
Template File: sources-sink-64b.tmpl.cpp
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Small number greater than zero that will not cause an integer overflow in the sink
 * Sinks:
 *    BadSink : Attempt to allocate array using length value from source
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
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

namespace CWE680_Integer_Overflow_To_Buffer_Overflow__new_connect_socket_64
{

#ifndef OMITBAD

void bad_sink(void * void_data_ptr)
{
    /* cast void pointer to a pointer of the appropriate type */
    int * data_ptr = (int *)void_data_ptr;
    /* dereference data_ptr into data */
    int data = (*data_ptr);
    {
        size_t a,i;
        int *b;
        /* POTENTIAL FLAW: a may overflow to a small value */
        a = data * sizeof(int); /* sizeof array in bytes */
        b = (int*)new char[a];
        for (i = 0; i < (size_t)data; i++)
        {
            b[i] = 0; /* may write beyond limit of b if integer overflow occured above */
        }
        printIntLine(b[0]);
        delete [] b;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink(void * void_data_ptr)
{
    /* cast void pointer to a pointer of the appropriate type */
    int * data_ptr = (int *)void_data_ptr;
    /* dereference data_ptr into data */
    int data = (*data_ptr);
    {
        size_t a,i;
        int *b;
        /* POTENTIAL FLAW: a may overflow to a small value */
        a = data * sizeof(int); /* sizeof array in bytes */
        b = (int*)new char[a];
        for (i = 0; i < (size_t)data; i++)
        {
            b[i] = 0; /* may write beyond limit of b if integer overflow occured above */
        }
        printIntLine(b[0]);
        delete [] b;
    }
}

#endif /* OMITGOOD */

} // close namespace
