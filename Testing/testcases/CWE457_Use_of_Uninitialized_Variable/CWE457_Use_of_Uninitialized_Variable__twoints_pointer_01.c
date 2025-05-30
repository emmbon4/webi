/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__twoints_pointer_01.c
Label Definition File: CWE457_Use_of_Uninitialized_Variable.c.label.xml
Template File: sources-sinks-01.tmpl.c
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

# include <wchar.h>

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__twoints_pointer_01_bad()
{
    twoints * data;
    /* Don't initialize data */
    ; /* empty statement needed for some flow variants */
    printIntLine(data->a);
    printIntLine(data->b);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    twoints * data;
    /* initialize both the pointer and the data pointed to */
    data = (twoints *)malloc(sizeof(twoints));
    data->a = 5;
    data->b = 6;
    printIntLine(data->a);
    printIntLine(data->b);
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    twoints * data;
    /* Don't initialize data */
    ; /* empty statement needed for some flow variants */
    /* initialize both the pointer and the data pointed to */
    data = (twoints *)malloc(sizeof(twoints));
    data->a = 5;
    data->b = 6;
    printIntLine(data->a);
    printIntLine(data->b);
}

void CWE457_Use_of_Uninitialized_Variable__twoints_pointer_01_good()
{
    goodG2B();
    goodB2G();
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
    CWE457_Use_of_Uninitialized_Variable__twoints_pointer_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__twoints_pointer_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
