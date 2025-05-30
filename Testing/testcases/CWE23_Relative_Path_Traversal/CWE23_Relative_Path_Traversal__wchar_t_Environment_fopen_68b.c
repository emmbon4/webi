/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__wchar_t_Environment_fopen_68b.c
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: Environment Read input from an environment variable
 * GoodSource: File name without a period or slash
 * Sink: fopen
 *    BadSink :
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define BASEPATH L"c:\\temp\\"
#else
#define BASEPATH L"/tmp/"
#endif

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
# define GETENV _wgetenv
#else
# define GETENV wgetenv
#endif

#ifdef _WIN32
# define FOPEN _wfopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

extern wchar_t * CWE23_Relative_Path_Traversal__wchar_t_Environment_fopen_68_bad_data;
extern wchar_t * CWE23_Relative_Path_Traversal__wchar_t_Environment_fopen_68_goodG2B_data;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void CWE23_Relative_Path_Traversal__wchar_t_Environment_fopen_68b_bad_sink()
{
    wchar_t * data = CWE23_Relative_Path_Traversal__wchar_t_Environment_fopen_68_bad_data;
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
void CWE23_Relative_Path_Traversal__wchar_t_Environment_fopen_68b_goodG2B_sink()
{
    wchar_t * data = CWE23_Relative_Path_Traversal__wchar_t_Environment_fopen_68_goodG2B_data;
    {
        FILE *file = NULL;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        file = FOPEN(data, L"wb+");
        if (file != NULL) fclose(file);
    }
}

#endif /* OMITGOOD */
