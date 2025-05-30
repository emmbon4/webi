/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE758_Undefined_Behavior__long_long_alloca_use_16.c
Label Definition File: CWE758_Undefined_Behavior.alloc.label.xml
Template File: point-flaw-16.tmpl.c
*/
/*
 * @description
 * CWE: 758 Undefined Behavior
 * Sinks: alloca_use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data from alloca without initialization
 * Flow Variant: 16 Control flow: while(1) and while(0)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE758_Undefined_Behavior__long_long_alloca_use_16_bad()
{
    while(1)
    {
        {
            long long * pointer = (long long *)ALLOCA(sizeof(long long));
            long long data = *pointer; /* FLAW: the value pointed to by pointer is undefined */
            printLongLongLine(data);
        }
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            long long data;
            long long * pointer = (long long *)ALLOCA(sizeof(long long));
            data = 5L;
            *pointer = data; /* FIX: Assign a value to the thing pointed to by pointer */
            {
                long long data = *pointer;
                printLongLongLine(data);
            }
        }
        break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() changes the conditions on the while statements */
static void good1()
{
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            long long * pointer = (long long *)ALLOCA(sizeof(long long));
            long long data = *pointer; /* FLAW: the value pointed to by pointer is undefined */
            printLongLongLine(data);
        }
        break;
    }
    while(1)
    {
        {
            long long data;
            long long * pointer = (long long *)ALLOCA(sizeof(long long));
            data = 5L;
            *pointer = data; /* FIX: Assign a value to the thing pointed to by pointer */
            {
                long long data = *pointer;
                printLongLongLine(data);
            }
        }
        break;
    }
}

void CWE758_Undefined_Behavior__long_long_alloca_use_16_good()
{
    good1();
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
    CWE758_Undefined_Behavior__long_long_alloca_use_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE758_Undefined_Behavior__long_long_alloca_use_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
