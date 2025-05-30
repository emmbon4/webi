/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__wchar_t_cat_68a.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sink: cat
 *    BadSink : Copy string to data using wcscat
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

wchar_t * CWE665_Improper_Initialization__wchar_t_cat_68_bad_data;
wchar_t * CWE665_Improper_Initialization__wchar_t_cat_68_goodG2B_data;

#ifndef OMITBAD

/* bad function declaration */
void CWE665_Improper_Initialization__wchar_t_cat_68b_bad_sink();

void CWE665_Improper_Initialization__wchar_t_cat_68_bad()
{
    wchar_t * data;
    wchar_t data_buf[100];
    data = data_buf;
    /* FLAW: Do not initialize data */
    ; /* empty statement needed for some flow variants */
    CWE665_Improper_Initialization__wchar_t_cat_68_bad_data = data;
    CWE665_Improper_Initialization__wchar_t_cat_68b_bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE665_Improper_Initialization__wchar_t_cat_68b_goodG2B_sink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    wchar_t data_buf[100];
    data = data_buf;
    /* FIX: Properly initialize data */
    data[0] = L'\0'; /* null terminate */
    CWE665_Improper_Initialization__wchar_t_cat_68_goodG2B_data = data;
    CWE665_Improper_Initialization__wchar_t_cat_68b_goodG2B_sink();
}

void CWE665_Improper_Initialization__wchar_t_cat_68_good()
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
    CWE665_Improper_Initialization__wchar_t_cat_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE665_Improper_Initialization__wchar_t_cat_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
