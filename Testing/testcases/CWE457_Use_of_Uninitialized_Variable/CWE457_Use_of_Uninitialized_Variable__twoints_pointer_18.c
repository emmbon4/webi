/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__twoints_pointer_18.c
Label Definition File: CWE457_Use_of_Uninitialized_Variable.c.label.xml
Template File: sources-sinks-18.tmpl.c
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

# include <wchar.h>

#ifndef OMITBAD

void CWE457_Use_of_Uninitialized_Variable__twoints_pointer_18_bad()
{
    twoints * data;
    goto source;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* initialize both the pointer and the data pointed to */
    data = (twoints *)malloc(sizeof(twoints));
    data->a = 5;
    data->b = 6;
source:
    /* Don't initialize data */
    ; /* empty statement needed for some flow variants */
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* initialize both the pointer and the data pointed to */
    data = (twoints *)malloc(sizeof(twoints));
    data->a = 5;
    data->b = 6;
    printIntLine(data->a);
    printIntLine(data->b);
sink:
    printIntLine(data->a);
    printIntLine(data->b);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by reversing the blocks on the second goto statement */
static void goodB2G()
{
    twoints * data;
    goto source;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* initialize both the pointer and the data pointed to */
    data = (twoints *)malloc(sizeof(twoints));
    data->a = 5;
    data->b = 6;
source:
    /* Don't initialize data */
    ; /* empty statement needed for some flow variants */
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    printIntLine(data->a);
    printIntLine(data->b);
sink:
    /* initialize both the pointer and the data pointed to */
    data = (twoints *)malloc(sizeof(twoints));
    data->a = 5;
    data->b = 6;
    printIntLine(data->a);
    printIntLine(data->b);
}

/* goodG2B() - use goodsource and badsink by reversing the blocks on the first goto statement */
static void goodG2B()
{
    twoints * data;
    goto source;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* Don't initialize data */
    ; /* empty statement needed for some flow variants */
source:
    /* initialize both the pointer and the data pointed to */
    data = (twoints *)malloc(sizeof(twoints));
    data->a = 5;
    data->b = 6;
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* initialize both the pointer and the data pointed to */
    data = (twoints *)malloc(sizeof(twoints));
    data->a = 5;
    data->b = 6;
    printIntLine(data->a);
    printIntLine(data->b);
sink:
    printIntLine(data->a);
    printIntLine(data->b);
}

void CWE457_Use_of_Uninitialized_Variable__twoints_pointer_18_good()
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
    CWE457_Use_of_Uninitialized_Variable__twoints_pointer_18_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__twoints_pointer_18_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
