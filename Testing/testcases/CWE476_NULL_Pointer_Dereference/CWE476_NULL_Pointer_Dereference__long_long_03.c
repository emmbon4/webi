/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__long_long_03.c
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sink-03.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sink:
 *    BadSink : Print data
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE476_NULL_Pointer_Dereference__long_long_03_bad()
{
    long long * data;
    /* Initialize data */
    data = NULL;
    if(5==5)
    {
        /* FLAW: Set data to NULL - it will be used in the sink */
        data = NULL;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Initialize data - it will be used in the sink */
        {
            long long tmp = 5L;
            data = &tmp;
        }
    }
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printLongLongLine(*data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the 5==5 to 5!=5 */
static void goodG2B1()
{
    long long * data;
    /* Initialize data */
    data = NULL;
    if(5!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Set data to NULL - it will be used in the sink */
        data = NULL;
    }
    else
    {
        /* FIX: Initialize data - it will be used in the sink */
        {
            long long tmp = 5L;
            data = &tmp;
        }
    }
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printLongLongLine(*data);
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    long long * data;
    /* Initialize data */
    data = NULL;
    if(5==5)
    {
        /* FIX: Initialize data - it will be used in the sink */
        {
            long long tmp = 5L;
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
    printLongLongLine(*data);
}

void CWE476_NULL_Pointer_Dereference__long_long_03_good()
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
    CWE476_NULL_Pointer_Dereference__long_long_03_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE476_NULL_Pointer_Dereference__long_long_03_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
