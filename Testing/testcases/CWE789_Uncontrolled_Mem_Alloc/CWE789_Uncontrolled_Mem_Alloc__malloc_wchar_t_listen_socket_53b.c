/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_listen_socket_53b.c
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-53b.tmpl.c
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Small number greater than zero
 * Sinks:
 *    GoodSink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    BadSink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
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

#define HELLO_STRING L"hello"

#ifndef OMITBAD

/* bad function declaration */
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_listen_socket_53c_bad_sink(int data);

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_listen_socket_53b_bad_sink(int data)
{
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_listen_socket_53c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_listen_socket_53c_goodG2B_sink(int data);

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_listen_socket_53b_goodG2B_sink(int data)
{
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_listen_socket_53c_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_listen_socket_53c_goodB2G_sink(int data);

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_listen_socket_53b_goodB2G_sink(int data)
{
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_listen_socket_53c_goodB2G_sink(data);
}

#endif /* OMITGOOD */
