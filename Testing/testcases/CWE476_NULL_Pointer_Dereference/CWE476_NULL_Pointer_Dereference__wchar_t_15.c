/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__wchar_t_15.c
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sink-15.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sink:
 *    BadSink : Print data
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE476_NULL_Pointer_Dereference__wchar_t_15_bad()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    switch(6)
    {
    case 6:
        /* FLAW: Set data to NULL - it will be used in the sink */
        data = NULL;
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Initialize data - it will be used in the sink */
        data = L"Good";
        break;
    }
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    /* printWLine() checks for NULL, so we cannot use it here */
    wprintf(L"%s\n", data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the switch to switch(5) */
static void goodG2B1()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Set data to NULL - it will be used in the sink */
        data = NULL;
        break;
    default:
        /* FIX: Initialize data - it will be used in the sink */
        data = L"Good";
        break;
    }
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    /* printWLine() checks for NULL, so we cannot use it here */
    wprintf(L"%s\n", data);
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the switch */
static void goodG2B2()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    switch(6)
    {
    case 6:
        /* FIX: Initialize data - it will be used in the sink */
        data = L"Good";
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Set data to NULL - it will be used in the sink */
        data = NULL;
        break;
    }
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    /* printWLine() checks for NULL, so we cannot use it here */
    wprintf(L"%s\n", data);
}

void CWE476_NULL_Pointer_Dereference__wchar_t_15_good()
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
    CWE476_NULL_Pointer_Dereference__wchar_t_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE476_NULL_Pointer_Dereference__wchar_t_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
