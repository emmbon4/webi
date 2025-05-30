/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__int_02.c
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sink-02.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sink:
 *    BadSink : Print data
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE476_NULL_Pointer_Dereference__int_02_bad()
{
    int * data;
    /* Initialize data */
    data = NULL;
    if(1)
    {
        /* FLAW: Set data to NULL - it will be used in the sink */
        data = NULL;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Initialize data - it will be used in the sink */
        {
            int tmp = 5;
            data = &tmp;
        }
    }
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printIntLine(*data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the 1 to 0 */
static void goodG2B1()
{
    int * data;
    /* Initialize data */
    data = NULL;
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Set data to NULL - it will be used in the sink */
        data = NULL;
    }
    else
    {
        /* FIX: Initialize data - it will be used in the sink */
        {
            int tmp = 5;
            data = &tmp;
        }
    }
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printIntLine(*data);
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    int * data;
    /* Initialize data */
    data = NULL;
    if(1)
    {
        /* FIX: Initialize data - it will be used in the sink */
        {
            int tmp = 5;
            data = &tmp;
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Set data to NULL - it will be used in the sink */
        data = NULL;
    }
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printIntLine(*data);
}

void CWE476_NULL_Pointer_Dereference__int_02_good()
{
    goodG2B1();
    goodG2B2();
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
    CWE476_NULL_Pointer_Dereference__int_02_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE476_NULL_Pointer_Dereference__int_02_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
