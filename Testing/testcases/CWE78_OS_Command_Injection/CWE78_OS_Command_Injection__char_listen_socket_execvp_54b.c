/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_listen_socket_execvp_54b.c
Label Definition File: CWE78_OS_Command_Injection.no_path.label.xml
Template File: sources-sink-54b.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Benign input
 * Sink: execvp
 *    BadSink : execute command with execvp
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
# define COMMAND_INT_PATH "%WINDIR%\\system32\\cmd.exe"
# define COMMAND_INT "cmd.exe"
# define COMMAND_ARG1 "/c"
# define COMMAND_ARG2 "dir"
# define COMMAND_ARG3 data
#else /* NOT _WIN32 */
# define COMMAND_INT "sh"
# define COMMAND_ARG1 "ls"
# define COMMAND_ARG2 data
# define COMMAND_ARG3 NULL
#endif

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

#ifdef _WIN32
#include <process.h>
# define EXECVP _execvp
#else /* NOT _WIN32 */
# define EXECVP execvp
#endif

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE78_OS_Command_Injection__char_listen_socket_execvp_54c_bad_sink(char * data);

void CWE78_OS_Command_Injection__char_listen_socket_execvp_54b_bad_sink(char * data)
{
    CWE78_OS_Command_Injection__char_listen_socket_execvp_54c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE78_OS_Command_Injection__char_listen_socket_execvp_54c_goodG2B_sink(char * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE78_OS_Command_Injection__char_listen_socket_execvp_54b_goodG2B_sink(char * data)
{
    CWE78_OS_Command_Injection__char_listen_socket_execvp_54c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
