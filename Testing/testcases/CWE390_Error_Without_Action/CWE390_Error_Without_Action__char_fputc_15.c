/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE390_Error_Without_Action__char_fputc_15.c
Label Definition File: CWE390_Error_Without_Action.string.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 390 Detection of Error Condition Without Action
 * Sinks: fputc
 *    GoodSink: Check if fputc() failed and handle errors properly
 *    BadSink : Check to see if fputc() failed, but do nothing about it
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE390_Error_Without_Action__char_fputc_15_bad()
{
    switch(6)
    {
    case 6:
    {
        /* FLAW: check the return value, but do nothing if there is an error */
        if (fputc((int)'A', stdout) == EOF)
        {
            /* do nothing */
        }
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        /* FIX: check the return value and handle errors properly */
        if (fputc((int)'A', stdout) == EOF)
        {
            printLine("fputc failed!");
            exit(1);
        }
    }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() changes the switch to switch(5) */
static void good1()
{
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        /* FLAW: check the return value, but do nothing if there is an error */
        if (fputc((int)'A', stdout) == EOF)
        {
            /* do nothing */
        }
    }
    break;
    default:
    {
        /* FIX: check the return value and handle errors properly */
        if (fputc((int)'A', stdout) == EOF)
        {
            printLine("fputc failed!");
            exit(1);
        }
    }
    }
}

/* good2() reverses the blocks in the switch */
static void good2()
{
    switch(6)
    {
    case 6:
    {
        /* FIX: check the return value and handle errors properly */
        if (fputc((int)'A', stdout) == EOF)
        {
            printLine("fputc failed!");
            exit(1);
        }
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        /* FLAW: check the return value, but do nothing if there is an error */
        if (fputc((int)'A', stdout) == EOF)
        {
            /* do nothing */
        }
    }
    }
}

void CWE390_Error_Without_Action__char_fputc_15_good()
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
    CWE390_Error_Without_Action__char_fputc_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE390_Error_Without_Action__char_fputc_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
