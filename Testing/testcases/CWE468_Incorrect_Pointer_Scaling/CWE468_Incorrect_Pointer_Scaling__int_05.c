/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE468_Incorrect_Pointer_Scaling__int_05.c
Label Definition File: CWE468_Incorrect_Pointer_Scaling.label.xml
Template File: point-flaw-05.tmpl.c
*/
/*
 * @description
 * CWE: 468 Incorrect Pointer Scaling
 * Sinks: int
 *    GoodSink: Do not include sizeof(int) since pointer arithmetic is automatically scaled
 *    BadSink : Included sizeof(int) which is unnecessary since pointer arithmetic is automatically scaled
 * Flow Variant: 05 Control flow: if(static_t) and if(static_f)
 *
 * */

#include "std_testcase.h"

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int static_t = 1; /* true */
static int static_f = 0; /* false */

#ifndef OMITBAD

void CWE468_Incorrect_Pointer_Scaling__int_05_bad()
{
    if(static_t)
    {
        {
            int array[5] = { 1, 2, 3, 4, 5 };
            int *pointer = array;
            /* get array[2] */
            /* FLAW: included *sizeof(int) which is unnecessary since pointer arithmetic is automatically scaled */
            int toPrint = *(pointer+(2*sizeof(int)));
            printIntLine(toPrint);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            int array[5] = { 1, 2, 3, 4, 5 };
            int *pointer = array;
            /* get array[2] */
            /* FIX: no sizeof() needed since pointer math is automatically scaled */
            int toPrint = *(pointer+2);
            printIntLine(toPrint);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(static_f) instead of if(static_t) */
static void good1()
{
    if(static_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            int array[5] = { 1, 2, 3, 4, 5 };
            int *pointer = array;
            /* get array[2] */
            /* FLAW: included *sizeof(int) which is unnecessary since pointer arithmetic is automatically scaled */
            int toPrint = *(pointer+(2*sizeof(int)));
            printIntLine(toPrint);
        }
    }
    else
    {
        {
            int array[5] = { 1, 2, 3, 4, 5 };
            int *pointer = array;
            /* get array[2] */
            /* FIX: no sizeof() needed since pointer math is automatically scaled */
            int toPrint = *(pointer+2);
            printIntLine(toPrint);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_t)
    {
        {
            int array[5] = { 1, 2, 3, 4, 5 };
            int *pointer = array;
            /* get array[2] */
            /* FIX: no sizeof() needed since pointer math is automatically scaled */
            int toPrint = *(pointer+2);
            printIntLine(toPrint);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            int array[5] = { 1, 2, 3, 4, 5 };
            int *pointer = array;
            /* get array[2] */
            /* FLAW: included *sizeof(int) which is unnecessary since pointer arithmetic is automatically scaled */
            int toPrint = *(pointer+(2*sizeof(int)));
            printIntLine(toPrint);
        }
    }
}

void CWE468_Incorrect_Pointer_Scaling__int_05_good()
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
    CWE468_Incorrect_Pointer_Scaling__int_05_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE468_Incorrect_Pointer_Scaling__int_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
