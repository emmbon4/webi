/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__wchar_t_Environment_61a.c
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-61a.tmpl.c
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * BadSource: Environment Read input from an environment variable
 * GoodSource: Use a hardcoded path
 * Sinks:
 *    BadSink : Set the environment variable
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
# define NEW_PATH L"%SystemRoot%\\system32"
# define PUTENV _wputenv
#else
# define NEW_PATH L"/bin"
# define PUTENV wputenv
#endif

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
# define GETENV _wgetenv
#else
# define GETENV wgetenv
#endif

#ifndef OMITBAD

/* bad function declaration */
wchar_t * CWE427_Uncontrolled_Search_Path_Element__wchar_t_Environment_61b_bad_source(wchar_t * data);

void CWE427_Uncontrolled_Search_Path_Element__wchar_t_Environment_61_bad()
{
    wchar_t * data;
    wchar_t data_buf[250] = L"PATH=";
    data = data_buf;
    data = CWE427_Uncontrolled_Search_Path_Element__wchar_t_Environment_61b_bad_source(data);
    /* POTENTIAL FLAW: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
wchar_t * CWE427_Uncontrolled_Search_Path_Element__wchar_t_Environment_61b_goodG2B_source(wchar_t * data);

static void goodG2B()
{
    wchar_t * data;
    wchar_t data_buf[250] = L"PATH=";
    data = data_buf;
    data = CWE427_Uncontrolled_Search_Path_Element__wchar_t_Environment_61b_goodG2B_source(data);
    /* POTENTIAL FLAW: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}

void CWE427_Uncontrolled_Search_Path_Element__wchar_t_Environment_61_good()
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
    CWE427_Uncontrolled_Search_Path_Element__wchar_t_Environment_61_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE427_Uncontrolled_Search_Path_Element__wchar_t_Environment_61_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
