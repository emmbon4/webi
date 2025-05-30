/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__char_Environment_open_54c.c
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-54c.tmpl.c
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

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
# define GETENV getenv
#else
# define GETENV getenv
#endif

#ifdef _WIN32
# define OPEN _open
# define CLOSE _close
#else
# define OPEN open
# define CLOSE close
#endif

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE36_Absolute_Path_Traversal__char_Environment_open_54d_bad_sink(char * data);

void CWE36_Absolute_Path_Traversal__char_Environment_open_54c_bad_sink(char * data)
{
    CWE36_Absolute_Path_Traversal__char_Environment_open_54d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE36_Absolute_Path_Traversal__char_Environment_open_54d_goodG2B_sink(char * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE36_Absolute_Path_Traversal__char_Environment_open_54c_goodG2B_sink(char * data)
{
    CWE36_Absolute_Path_Traversal__char_Environment_open_54d_goodG2B_sink(data);
}

#endif /* OMITGOOD */
