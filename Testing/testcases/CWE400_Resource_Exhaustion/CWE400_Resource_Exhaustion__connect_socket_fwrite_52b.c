/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__connect_socket_fwrite_52b.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Assign count to be a relatively small number
 * Sinks: fwrite
 *    GoodSink: Write to a file count number of times, but first validate count
 *    BadSink : Write to a file count number of times
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
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

#define SENTENCE "This is the sentence we are printing to the file. "

#ifndef OMITBAD

/* bad function declaration */
void CWE400_Resource_Exhaustion__connect_socket_fwrite_52c_bad_sink(int count);

void CWE400_Resource_Exhaustion__connect_socket_fwrite_52b_bad_sink(int count)
{
    CWE400_Resource_Exhaustion__connect_socket_fwrite_52c_bad_sink(count);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE400_Resource_Exhaustion__connect_socket_fwrite_52c_goodG2B_sink(int count);

void CWE400_Resource_Exhaustion__connect_socket_fwrite_52b_goodG2B_sink(int count)
{
    CWE400_Resource_Exhaustion__connect_socket_fwrite_52c_goodG2B_sink(count);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE400_Resource_Exhaustion__connect_socket_fwrite_52c_goodB2G_sink(int count);

void CWE400_Resource_Exhaustion__connect_socket_fwrite_52b_goodB2G_sink(int count)
{
    CWE400_Resource_Exhaustion__connect_socket_fwrite_52c_goodB2G_sink(count);
}

#endif /* OMITGOOD */
