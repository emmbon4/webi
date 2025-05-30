/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__wchar_t_Environment_open_54b.c
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-54b.tmpl.c
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: Environment Read input from an environment variable
 * GoodSource: Full path and file name
 * Sink: open
 *    BadSink :
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
# define GETENV _wgetenv
#else
# define GETENV wgetenv
#endif

#ifdef _WIN32
# define OPEN _wopen
# define CLOSE _close
#else
# define OPEN wopen
# define CLOSE close
#endif

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE36_Absolute_Path_Traversal__wchar_t_Environment_open_54c_bad_sink(wchar_t * data);

void CWE36_Absolute_Path_Traversal__wchar_t_Environment_open_54b_bad_sink(wchar_t * data)
{
    CWE36_Absolute_Path_Traversal__wchar_t_Environment_open_54c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE36_Absolute_Path_Traversal__wchar_t_Environment_open_54c_goodG2B_sink(wchar_t * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE36_Absolute_Path_Traversal__wchar_t_Environment_open_54b_goodG2B_sink(wchar_t * data)
{
    CWE36_Absolute_Path_Traversal__wchar_t_Environment_open_54c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
