/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__char_fromConsole_68b.c
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * BadSource: fromConsole Read input from the console
 * GoodSource: Use a hardcoded path
 * Sink:
 *    BadSink : Set the environment variable
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
# define NEW_PATH "%SystemRoot%\\system32"
# define PUTENV _putenv
#else
# define NEW_PATH "/bin"
# define PUTENV putenv
#endif

extern char * CWE427_Uncontrolled_Search_Path_Element__char_fromConsole_68_bad_data;
extern char * CWE427_Uncontrolled_Search_Path_Element__char_fromConsole_68_goodG2B_data;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void CWE427_Uncontrolled_Search_Path_Element__char_fromConsole_68b_bad_sink()
{
    char * data = CWE427_Uncontrolled_Search_Path_Element__char_fromConsole_68_bad_data;
    /* POTENTIAL FLAW: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE427_Uncontrolled_Search_Path_Element__char_fromConsole_68b_goodG2B_sink()
{
    char * data = CWE427_Uncontrolled_Search_Path_Element__char_fromConsole_68_goodG2B_data;
    /* POTENTIAL FLAW: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}

#endif /* OMITGOOD */
