/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_listen_socket_vfprintf_54b.c
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-54b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Copy a fixed string into data
 * Sinks: vfprintf
 *    GoodSink: vfprintf with a format string
 *    BadSink : vfprintf without a format string
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include <stdarg.h>
#include "std_testcase.h"

#ifdef _WIN32
# include <winsock2.h>
# include <windows.h>
# include <direct.h>
# define PATH_SZ 100
# pragma comment(lib, "ws2_32") /* include ws2_32.lib when linking */
# define CLOSE_SOCKET closesocket
#else
# define PATH_SZ PATH_MAX
# define INVALID_SOCKET -1
# define SOCKET_ERROR -1
# define CLOSE_SOCKET close
# define SOCKET int
#endif

#define TCP_PORT 27015
#define LISTEN_BACKLOG 5

#ifndef OMITBAD

/* bad function declaration */
void CWE134_Uncontrolled_Format_String__char_listen_socket_vfprintf_54c_bad_sink(char * data);

void CWE134_Uncontrolled_Format_String__char_listen_socket_vfprintf_54b_bad_sink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_listen_socket_vfprintf_54c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE134_Uncontrolled_Format_String__char_listen_socket_vfprintf_54c_goodG2B_sink(char * data);

void CWE134_Uncontrolled_Format_String__char_listen_socket_vfprintf_54b_goodG2B_sink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_listen_socket_vfprintf_54c_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE134_Uncontrolled_Format_String__char_listen_socket_vfprintf_54c_goodB2G_sink(char * data);

void CWE134_Uncontrolled_Format_String__char_listen_socket_vfprintf_54b_goodB2G_sink(char * data)
{
    CWE134_Uncontrolled_Format_String__char_listen_socket_vfprintf_54c_goodB2G_sink(data);
}

#endif /* OMITGOOD */
