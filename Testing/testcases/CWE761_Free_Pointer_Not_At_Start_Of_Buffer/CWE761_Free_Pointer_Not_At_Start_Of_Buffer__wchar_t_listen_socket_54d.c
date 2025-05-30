/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_listen_socket_54d.c
Label Definition File: CWE761_Free_Pointer_Not_At_Start_Of_Buffer.label.xml
Template File: source-sinks-54d.tmpl.c
*/
/*
 * @description
 * CWE: 761 Free Pointer Not At Start of Buffer
 * BadSource: listen_socket Read data using a listen socket (server side)
 * Sinks:
 *    GoodSink: free() memory correctly at the start of the buffer
 *    BadSink : free() memory not at the start of the buffer
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define SEARCH_CHAR L'S'
#define BAD_SRC_FIXED L"Fixed String" /* MAINTENANCE NOTE: This string must contain the SEARCH_CHAR */

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
void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_listen_socket_54e_bad_sink(wchar_t * data);

void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_listen_socket_54d_bad_sink(wchar_t * data)
{
    CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_listen_socket_54e_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_listen_socket_54e_goodB2G_sink(wchar_t * data);

void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_listen_socket_54d_goodB2G_sink(wchar_t * data)
{
    CWE761_Free_Pointer_Not_At_Start_Of_Buffer__wchar_t_listen_socket_54e_goodB2G_sink(data);
}

#endif /* OMITGOOD */
