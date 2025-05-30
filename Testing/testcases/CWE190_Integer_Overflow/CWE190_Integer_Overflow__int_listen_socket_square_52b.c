/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_listen_socket_square_52b.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Small, non-zero
 * Sinks: square
 *    GoodSink: Ensure there is no overflow before performing the square root
 *    BadSink : Square data
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
#else
# define INVALID_SOCKET -1
# define SOCKET_ERROR -1
# define CLOSE_SOCKET close
# define SOCKET int
#endif

#define TCP_PORT 27015
#define LISTEN_BACKLOG 5
#define CHAR_ARRAY_SIZE sizeof(data)*sizeof(data)

#include <math.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE190_Integer_Overflow__int_listen_socket_square_52c_bad_sink(int data);

void CWE190_Integer_Overflow__int_listen_socket_square_52b_bad_sink(int data)
{
    CWE190_Integer_Overflow__int_listen_socket_square_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__int_listen_socket_square_52c_goodG2B_sink(int data);

void CWE190_Integer_Overflow__int_listen_socket_square_52b_goodG2B_sink(int data)
{
    CWE190_Integer_Overflow__int_listen_socket_square_52c_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__int_listen_socket_square_52c_goodB2G_sink(int data);

void CWE190_Integer_Overflow__int_listen_socket_square_52b_goodB2G_sink(int data)
{
    CWE190_Integer_Overflow__int_listen_socket_square_52c_goodB2G_sink(data);
}

#endif /* OMITGOOD */
