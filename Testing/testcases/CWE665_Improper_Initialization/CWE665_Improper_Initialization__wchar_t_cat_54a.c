/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__wchar_t_cat_54a.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-54a.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sink: cat
 *    BadSink : Copy string to data using wcscat
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE665_Improper_Initialization__wchar_t_cat_54b_bad_sink(wchar_t * data);

void CWE665_Improper_Initialization__wchar_t_cat_54_bad()
{
    wchar_t * data;
    wchar_t data_buf[100];
    data = data_buf;
    /* FLAW: Do not initialize data */
    ; /* empty statement needed for some flow variants */
    CWE665_Improper_Initialization__wchar_t_cat_54b_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE665_Improper_Initialization__wchar_t_cat_54b_goodG2B_sink(wchar_t * data);

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    wchar_t data_buf[100];
    data = data_buf;
    /* FIX: Properly initialize data */
    data[0] = L'\0'; /* null terminate */
    CWE665_Improper_Initialization__wchar_t_cat_54b_goodG2B_sink(data);
}

void CWE665_Improper_Initialization__wchar_t_cat_54_good()
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
    CWE665_Improper_Initialization__wchar_t_cat_54_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE665_Improper_Initialization__wchar_t_cat_54_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
