/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE758_Undefined_Behavior__long_long_malloc_use_04.c
Label Definition File: CWE758_Undefined_Behavior.alloc.label.xml
Template File: point-flaw-04.tmpl.c
*/
/*
 * @description
 * CWE: 758 Undefined Behavior
 * Sinks: malloc_use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data from malloc without initialization
 * Flow Variant: 04 Control flow: if(static_const_t) and if(static_const_f)
 *
 * */

#include "std_testcase.h"

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int static_const_t = 1; /* true */
static const int static_const_f = 0; /* false */

#ifndef OMITBAD

void CWE758_Undefined_Behavior__long_long_malloc_use_04_bad()
{
    if(static_const_t)
    {
        {
            long long * pointer = (long long *)malloc(sizeof(long long));
            long long data = *pointer; /* FLAW: the value pointed to by pointer is undefined */
            free(pointer);
            printLongLongLine(data);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            long long data;
            long long * pointer = (long long *)malloc(sizeof(long long));
            data = 5L;
            *pointer = data; /* FIX: Assign a value to the thing pointed to by pointer */
            {
                long long data = *pointer;
                printLongLongLine(data);
            }
            free(pointer);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(static_const_f) instead of if(static_const_t) */
static void good1()
{
    if(static_const_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            long long * pointer = (long long *)malloc(sizeof(long long));
            long long data = *pointer; /* FLAW: the value pointed to by pointer is undefined */
            free(pointer);
            printLongLongLine(data);
        }
    }
    else
    {
        {
            long long data;
            long long * pointer = (long long *)malloc(sizeof(long long));
            data = 5L;
            *pointer = data; /* FIX: Assign a value to the thing pointed to by pointer */
            {
                long long data = *pointer;
                printLongLongLine(data);
            }
            free(pointer);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_const_t)
    {
        {
            long long data;
            long long * pointer = (long long *)malloc(sizeof(long long));
            data = 5L;
            *pointer = data; /* FIX: Assign a value to the thing pointed to by pointer */
            {
                long long data = *pointer;
                printLongLongLine(data);
            }
            free(pointer);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            long long * pointer = (long long *)malloc(sizeof(long long));
            long long data = *pointer; /* FLAW: the value pointed to by pointer is undefined */
            free(pointer);
            printLongLongLine(data);
        }
    }
}

void CWE758_Undefined_Behavior__long_long_malloc_use_04_good()
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
    CWE758_Undefined_Behavior__long_long_malloc_use_04_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE758_Undefined_Behavior__long_long_malloc_use_04_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
