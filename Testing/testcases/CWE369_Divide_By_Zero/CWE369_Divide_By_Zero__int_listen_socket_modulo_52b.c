/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_By_Zero__int_listen_socket_modulo_52b.c
Label Definition File: CWE369_Divide_By_Zero__int.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide By Zero
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Non-zero
 * Sink: modulo
 *    BadSink : Modulo a constant with data
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

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE369_Divide_By_Zero__int_listen_socket_modulo_52c_bad_sink(int data);

void CWE369_Divide_By_Zero__int_listen_socket_modulo_52b_bad_sink(int data)
{
    CWE369_Divide_By_Zero__int_listen_socket_modulo_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE369_Divide_By_Zero__int_listen_socket_modulo_52c_goodG2B_sink(int data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE369_Divide_By_Zero__int_listen_socket_modulo_52b_goodG2B_sink(int data)
{
    CWE369_Divide_By_Zero__int_listen_socket_modulo_52c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
