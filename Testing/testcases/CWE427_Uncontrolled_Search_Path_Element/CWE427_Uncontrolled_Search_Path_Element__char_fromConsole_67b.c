/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__char_fromConsole_67b.c
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * BadSource: fromConsole Read input from the console
 * GoodSource: Use a hardcoded path
 * Sinks:
 *    BadSink : Set the environment variable
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
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

typedef struct _CWE427_Uncontrolled_Search_Path_Element__char_fromConsole_67_struct_type
{
    char * a;
} CWE427_Uncontrolled_Search_Path_Element__char_fromConsole_67_struct_type;

#ifndef OMITBAD

void CWE427_Uncontrolled_Search_Path_Element__char_fromConsole_67b_bad_sink(CWE427_Uncontrolled_Search_Path_Element__char_fromConsole_67_struct_type my_struct)
{
    char * data = my_struct.a;
    /* POTENTIAL FLAW: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE427_Uncontrolled_Search_Path_Element__char_fromConsole_67b_goodG2B_sink(CWE427_Uncontrolled_Search_Path_Element__char_fromConsole_67_struct_type my_struct)
{
    char * data = my_struct.a;
    /* POTENTIAL FLAW: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}

#endif /* OMITGOOD */
