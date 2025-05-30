/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__double_pointer_17.c
Label Definition File: CWE457_Use_of_Uninitialized_Variable.c.label.xml
Template File: sources-sinks-17.tmpl.c
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

# include <wchar.h>

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__double_pointer_17_bad()
{
    int h,i,j,k;
    double * data;
    for(h = 0; h < 0; h++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* initialize both the pointer and the data pointed to */
        data = (double *)malloc(sizeof(double));
        *data = 5.0;
    }
    for(i = 0; i < 1; i++)
    {
        /* Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }
    for(j = 0; j < 1; j++)
    {
        printDoubleLine(*data);
    }
    for(k = 0; k < 0; k++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* initialize both the pointer and the data pointed to */
        data = (double *)malloc(sizeof(double));
        *data = 5.0;
        printDoubleLine(*data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by changing the conditions on the third and fourth for statements */
static void goodB2G()
{
    int h,i,j,k;
    double * data;
    for(h = 0; h < 0; h++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* initialize both the pointer and the data pointed to */
        data = (double *)malloc(sizeof(double));
        *data = 5.0;
    }
    for(i = 0; i < 1; i++)
    {
        /* Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }
    for(j = 0; j < 0; j++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printDoubleLine(*data);
    }
    for(k = 0; k < 1; k++)
    {
        /* initialize both the pointer and the data pointed to */
        data = (double *)malloc(sizeof(double));
        *data = 5.0;
        printDoubleLine(*data);
    }
}

/* goodG2B() - use goodsource and badsink by changing the conditions on the first and second for statements */
static void goodG2B()
{
    int h,i,j,k;
    double * data;
    for(h = 0; h < 1; h++)
    {
        /* initialize both the pointer and the data pointed to */
        data = (double *)malloc(sizeof(double));
        *data = 5.0;
    }
    for(i = 0; i < 0; i++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }
    for(j = 0; j < 1; j++)
    {
        printDoubleLine(*data);
    }
    for(k = 0; k < 0; k++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* initialize both the pointer and the data pointed to */
        data = (double *)malloc(sizeof(double));
        *data = 5.0;
        printDoubleLine(*data);
    }
}

void CWE457_Use_of_Uninitialized_Variable__double_pointer_17_good()
{
    goodB2G();
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
    CWE457_Use_of_Uninitialized_Variable__double_pointer_17_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__double_pointer_17_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
