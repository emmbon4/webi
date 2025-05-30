/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__wchar_t_listen_socket_fopen_61a.c
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-61a.tmpl.c
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Full path and file name
 * Sinks: fopen
 *    BadSink :
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# include <winsock2.h>
# include <windows.h>
# include <direct.h>
# define PATH_SZ FILENAME_MAX
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
# define FOPEN _wfopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

#ifndef OMITBAD

/* bad function declaration */
wchar_t * CWE36_Absolute_Path_Traversal__wchar_t_listen_socket_fopen_61b_bad_source(wchar_t * data);

void CWE36_Absolute_Path_Traversal__wchar_t_listen_socket_fopen_61_bad()
{
    wchar_t * data;
    wchar_t data_buf[FILENAME_MAX] = L"";
    data = data_buf;
    data = CWE36_Absolute_Path_Traversal__wchar_t_listen_socket_fopen_61b_bad_source(data);
    {
        FILE *file = NULL;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        file = FOPEN(data, L"wb+");
        if (file != NULL) fclose(file);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
wchar_t * CWE36_Absolute_Path_Traversal__wchar_t_listen_socket_fopen_61b_goodG2B_source(wchar_t * data);

static void goodG2B()
{
    wchar_t * data;
    wchar_t data_buf[FILENAME_MAX] = L"";
    data = data_buf;
    data = CWE36_Absolute_Path_Traversal__wchar_t_listen_socket_fopen_61b_goodG2B_source(data);
    {
        FILE *file = NULL;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        file = FOPEN(data, L"wb+");
        if (file != NULL) fclose(file);
    }
}

void CWE36_Absolute_Path_Traversal__wchar_t_listen_socket_fopen_61_good()
{
    goodG2B();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE36_Absolute_Path_Traversal__wchar_t_listen_socket_fopen_61_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE36_Absolute_Path_Traversal__wchar_t_listen_socket_fopen_61_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
