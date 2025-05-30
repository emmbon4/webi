/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE758_Undefined_Behavior__twoints_pointer_malloc_use_12.c
Label Definition File: CWE758_Undefined_Behavior.alloc.label.xml
Template File: point-flaw-12.tmpl.c
*/
/*
 * @description
 * CWE: 758 Undefined Behavior
 * Sinks: malloc_use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data from malloc without initialization
 * Flow Variant: 12 Control flow: if(global_returns_t_or_f())
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE758_Undefined_Behavior__twoints_pointer_malloc_use_12_bad()
{
    if(global_returns_t_or_f())
    {
        {
            twoints * * pointer = (twoints * *)malloc(sizeof(twoints *));
            twoints * data = *pointer; /* FLAW: the value pointed to by pointer is undefined */
            free(pointer);
            printIntLine(data->a);
            printIntLine(data->b);
        }
    }
    else
    {
        {
            twoints * data;
            twoints * * pointer = (twoints * *)malloc(sizeof(twoints *));
            /* initialize both the pointer and the data pointed to */
            data = (twoints *)malloc(sizeof(twoints));
            data->a = 5;
            data->b = 6;
            *pointer = data; /* FIX: Assign a value to the thing pointed to by pointer */
            {
                twoints * data = *pointer;
                printIntLine(data->a);
                printIntLine(data->b);
            }
            free(pointer);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses the GoodSink on both sides of the "if" statement */
static void good1()
{
    if(global_returns_t_or_f())
    {
        {
            twoints * data;
            twoints * * pointer = (twoints * *)malloc(sizeof(twoints *));
            /* initialize both the pointer and the data pointed to */
            data = (twoints *)malloc(sizeof(twoints));
            data->a = 5;
            data->b = 6;
            *pointer = data; /* FIX: Assign a value to the thing pointed to by pointer */
            {
                twoints * data = *pointer;
                printIntLine(data->a);
                printIntLine(data->b);
            }
            free(pointer);
        }
    }
    else
    {
        {
            twoints * data;
            twoints * * pointer = (twoints * *)malloc(sizeof(twoints *));
            /* initialize both the pointer and the data pointed to */
            data = (twoints *)malloc(sizeof(twoints));
            data->a = 5;
            data->b = 6;
            *pointer = data; /* FIX: Assign a value to the thing pointed to by pointer */
            {
                twoints * data = *pointer;
                printIntLine(data->a);
                printIntLine(data->b);
            }
            free(pointer);
        }
    }
}

void CWE758_Undefined_Behavior__twoints_pointer_malloc_use_12_good()
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
    CWE758_Undefined_Behavior__twoints_pointer_malloc_use_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE758_Undefined_Behavior__twoints_pointer_malloc_use_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
