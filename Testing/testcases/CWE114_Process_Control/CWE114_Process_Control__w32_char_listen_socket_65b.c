/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_char_listen_socket_65b.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-65b.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Hard code the full pathname to the library
 * Sinks:
 *    BadSink : Load a dynamic link library
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

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

#include <windows.h>

#ifndef OMITBAD

void CWE114_Process_Control__w32_char_listen_socket_65b_bad_sink(char * data)
{
#ifdef _WIN32
    {
        HMODULE hModule;

        /* POTENTIAL FLAW: If the path to the library is not specified, an attacker may be able to
         * replace his own file with the intended library */
        hModule = LoadLibraryA(data);

        if (hModule != NULL)
        {
            FreeLibrary(hModule);
            printLine("Library loaded and freed successfully");
        }
        else {
            printLine("Unable to load library");
        }
    }
#endif
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE114_Process_Control__w32_char_listen_socket_65b_goodG2B_sink(char * data)
{
#ifdef _WIN32
    {
        HMODULE hModule;

        /* POTENTIAL FLAW: If the path to the library is not specified, an attacker may be able to
         * replace his own file with the intended library */
        hModule = LoadLibraryA(data);

        if (hModule != NULL)
        {
            FreeLibrary(hModule);
            printLine("Library loaded and freed successfully");
        }
        else {
            printLine("Unable to load library");
        }
    }
#endif
}

#endif /* OMITGOOD */
