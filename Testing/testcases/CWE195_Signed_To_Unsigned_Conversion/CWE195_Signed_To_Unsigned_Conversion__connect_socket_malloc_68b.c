/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_To_Unsigned_Conversion__connect_socket_malloc_68b.c
Label Definition File: CWE195_Signed_To_Unsigned_Conversion.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Positive integer
 * Sink: malloc
 *    BadSink : Allocate memory using malloc() with the size of data
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

extern int CWE195_Signed_To_Unsigned_Conversion__connect_socket_malloc_68_bad_data;
extern int CWE195_Signed_To_Unsigned_Conversion__connect_socket_malloc_68_goodG2B_data;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void CWE195_Signed_To_Unsigned_Conversion__connect_socket_malloc_68b_bad_sink()
{
    int data = CWE195_Signed_To_Unsigned_Conversion__connect_socket_malloc_68_bad_data;
    {
        /* Assume we want to allocate a relatively small buffer */
        if (data < 100)
        {
            /* POTENTIAL FLAW: malloc() takes a size_t (unsigned int) as input and therefore if it is negative,
             * the coversion will cause malloc() to allocate a very large amount of data or fail */
            char * data_buf = (char *)malloc(data);
            /* Do something with data_buf */
            memset(data_buf, 'A', data-1);
            data_buf[data-1] = '\0';
            printLine(data_buf);
            free(data_buf);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE195_Signed_To_Unsigned_Conversion__connect_socket_malloc_68b_goodG2B_sink()
{
    int data = CWE195_Signed_To_Unsigned_Conversion__connect_socket_malloc_68_goodG2B_data;
    {
        /* Assume we want to allocate a relatively small buffer */
        if (data < 100)
        {
            /* POTENTIAL FLAW: malloc() takes a size_t (unsigned int) as input and therefore if it is negative,
             * the coversion will cause malloc() to allocate a very large amount of data or fail */
            char * data_buf = (char *)malloc(data);
            /* Do something with data_buf */
            memset(data_buf, 'A', data-1);
            data_buf[data-1] = '\0';
            printLine(data_buf);
            free(data_buf);
        }
    }
}

#endif /* OMITGOOD */
