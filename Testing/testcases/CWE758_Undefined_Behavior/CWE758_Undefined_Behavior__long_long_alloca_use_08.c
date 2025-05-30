/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE758_Undefined_Behavior__long_long_alloca_use_08.c
Label Definition File: CWE758_Undefined_Behavior.alloc.label.xml
Template File: point-flaw-08.tmpl.c
*/
/*
 * @description
 * CWE: 758 Undefined Behavior
 * Sinks: alloca_use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data from alloca without initialization
 * Flow Variant: 08 Control flow: if(static_returns_t()) and if(static_returns_f())
 *
 * */

#include "std_testcase.h"

/* The two function below always return the same value, so a tool
   should be able to identify that calls to the functions will always
   return a fixed value. */
static int static_returns_t()
{
    return 1;
}

static int static_returns_f()
{
    return 0;
}

#ifndef OMITBAD

void CWE758_Undefined_Behavior__long_long_alloca_use_08_bad()
{
    if(static_returns_t())
    {
        {
            long long * pointer = (long long *)ALLOCA(sizeof(long long));
            long long data = *pointer; /* FLAW: the value pointed to by pointer is undefined */
            printLongLongLine(data);
        }
    }
    else
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
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(static_returns_f()) instead of if(static_returns_t()) */
static void good1()
{
    if(static_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            long long * pointer = (long long *)ALLOCA(sizeof(long long));
            long long data = *pointer; /* FLAW: the value pointed to by pointer is undefined */
            printLongLongLine(data);
        }
    }
    else
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
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_returns_t())
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
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            long long * pointer = (long long *)ALLOCA(sizeof(long long));
            long long data = *pointer; /* FLAW: the value pointed to by pointer is undefined */
            printLongLongLine(data);
        }
    }
}

void CWE758_Undefined_Behavior__long_long_alloca_use_08_good()
{
    good1();
    good2();
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
    CWE758_Undefined_Behavior__long_long_alloca_use_08_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE758_Undefined_Behavior__long_long_alloca_use_08_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
