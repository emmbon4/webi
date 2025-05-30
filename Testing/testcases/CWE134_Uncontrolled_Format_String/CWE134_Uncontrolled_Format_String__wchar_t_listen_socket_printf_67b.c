/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_printf_67b.c
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Copy a fixed string into data
 * Sinks: printf
 *    GoodSink: wprintf with "%s" as the first argument and data as the second
 *    BadSink : wprintf with only data as an argument
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

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

typedef struct _CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_printf_67_struct_type
{
    wchar_t * a;
} CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_printf_67_struct_type;

#ifndef OMITBAD

void CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_printf_67b_bad_sink(CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_printf_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
    /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
    wprintf(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_printf_67b_goodG2B_sink(CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_printf_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
    /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
    wprintf(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_printf_67b_goodB2G_sink(CWE134_Uncontrolled_Format_String__wchar_t_listen_socket_printf_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
    /* FIX: Specify the format disallowing a format string vulnerability */
    wprintf(L"%s\n", data);
}

#endif /* OMITGOOD */
