/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__wchar_t_cat_17.c
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-17.tmpl.c
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sink: cat
 *    BadSink : Copy string to data using wcscat
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE665_Improper_Initialization__wchar_t_cat_17_bad()
{
    int h,i;
    wchar_t * data;
    wchar_t data_buf[100];
    data = data_buf;
    for(h = 0; h < 0; h++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Properly initialize data */
        data[0] = L'\0'; /* null terminate */
    }
    for(i = 0; i < 1; i++)
    {
        /* FLAW: Do not initialize data */
        ; /* empty statement needed for some flow variants */
    }
    {
        wchar_t src[100];
        wmemset(src, L'C', 100-1); /* fill with L'C's */
        src[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: If data is not initialized properly, wcscat() may not function correctly */
        wcscat(data, src);
        printWLine(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() - use goodsource and badsink by changing the conditions on the for statements */
static void goodG2B()
{
    int h,i;
    wchar_t * data;
    wchar_t data_buf[100];
    data = data_buf;
    for(h = 0; h < 1; h++)
    {
        /* FIX: Properly initialize data */
        data[0] = L'\0'; /* null terminate */
    }
    for(i = 0; i < 0; i++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Do not initialize data */
        ; /* empty statement needed for some flow variants */
    }
    {
        wchar_t src[100];
        wmemset(src, L'C', 100-1); /* fill with L'C's */
        src[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: If data is not initialized properly, wcscat() may not function correctly */
        wcscat(data, src);
        printWLine(data);
    }
}

void CWE665_Improper_Initialization__wchar_t_cat_17_good()
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
    CWE665_Improper_Initialization__wchar_t_cat_17_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE665_Improper_Initialization__wchar_t_cat_17_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
