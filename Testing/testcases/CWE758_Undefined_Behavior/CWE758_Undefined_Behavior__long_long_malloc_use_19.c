/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE758_Undefined_Behavior__long_long_malloc_use_19.c
Label Definition File: CWE758_Undefined_Behavior.alloc.label.xml
Template File: point-flaw-19.tmpl.c
*/
/*
 * @description
 * CWE: 758 Undefined Behavior
 * Sinks: malloc_use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data from malloc without initialization
 * Flow Variant: 19 Control flow: Dead code after a return
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE758_Undefined_Behavior__long_long_malloc_use_19_bad()
{
    {
        long long * pointer = (long long *)malloc(sizeof(long long));
        long long data = *pointer; /* FLAW: the value pointed to by pointer is undefined */
        free(pointer);
        printLongLongLine(data);
    }
    return;
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

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() reverses the GoodSinkBody and the BadSinkBody so that the BadSinkBody never runs */
static void good1()
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
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        long long * pointer = (long long *)malloc(sizeof(long long));
        long long data = *pointer; /* FLAW: the value pointed to by pointer is undefined */
        free(pointer);
        printLongLongLine(data);
    }
}

void CWE758_Undefined_Behavior__long_long_malloc_use_19_good()
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
    CWE758_Undefined_Behavior__long_long_malloc_use_19_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE758_Undefined_Behavior__long_long_malloc_use_19_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
