/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_from_Return__int_calloc_14.c
Label Definition File: CWE690_NULL_Deref_from_Return.free.label.xml
Template File: source-sinks-14.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: calloc Allocate data using calloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 14 Control flow: if(global_five==5) and if(global_five!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE690_NULL_Deref_from_Return__int_calloc_14_bad()
{
    int * data;
    data = NULL; /* Initialize data */
    /* FLAW: Allocate memory without checking if the memeory allocation function failed */
    data = (int *)calloc(100, sizeof(int));
    if(global_five==5)
    {
        /* POTENTIAL FLAW: Initialize memory buffer without checking to see if the memory allocation function failed */
        data[0] = 5;
        printIntLine(data[0]);
        free(data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Check to see if the memory allocation function was successful before initializing the memory buffer */
        if (data != NULL)
        {
            data[0] = 5;
            printIntLine(data[0]);
            free(data);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing global_five==5 to global_five!=5 */
static void goodB2G1()
{
    int * data;
    data = NULL; /* Initialize data */
    /* FLAW: Allocate memory without checking if the memeory allocation function failed */
    data = (int *)calloc(100, sizeof(int));
    if(global_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Initialize memory buffer without checking to see if the memory allocation function failed */
        data[0] = 5;
        printIntLine(data[0]);
        free(data);
    }
    else
    {
        /* FIX: Check to see if the memory allocation function was successful before initializing the memory buffer */
        if (data != NULL)
        {
            data[0] = 5;
            printIntLine(data[0]);
            free(data);
        }
    }
}

/* goodB2G2() - use badsource and goodsink by reversing statements in if  */
static void goodB2G2()
{
    int * data;
    data = NULL; /* Initialize data */
    /* FLAW: Allocate memory without checking if the memeory allocation function failed */
    data = (int *)calloc(100, sizeof(int));
    if(global_five==5)
    {
        /* FIX: Check to see if the memory allocation function was successful before initializing the memory buffer */
        if (data != NULL)
        {
            data[0] = 5;
            printIntLine(data[0]);
            free(data);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Initialize memory buffer without checking to see if the memory allocation function failed */
        data[0] = 5;
        printIntLine(data[0]);
        free(data);
    }
}

void CWE690_NULL_Deref_from_Return__int_calloc_14_good()
{
    goodB2G1();
    goodB2G2();
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
    CWE690_NULL_Deref_from_Return__int_calloc_14_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE690_NULL_Deref_from_Return__int_calloc_14_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
