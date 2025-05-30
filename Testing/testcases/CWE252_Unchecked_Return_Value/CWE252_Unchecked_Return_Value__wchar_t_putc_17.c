/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE252_Unchecked_Return_Value__wchar_t_putc_17.c
Label Definition File: CWE252_Unchecked_Return_Value.string.label.xml
Template File: point-flaw-17.tmpl.c
*/
/*
 * @description
 * CWE: 252 Unchecked Return Value
 * Sinks: putc
 *    GoodSink: Check if putwc() fails
 *    BadSink : Do not check if putwc() fails
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE252_Unchecked_Return_Value__wchar_t_putc_17_bad()
{
    int j,k;
    for(j = 0; j < 1; j++)
    {
        {
            /* FLAW: Do not check the return value */
            putwc((wchar_t)L'A', stdout);
        }
    }
    for(k = 0; k < 0; k++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: check the return value */
            if (putwc((wchar_t)L'A', stdout) == WEOF)
            {
                printLine("putwc failed!");
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() changes the conditions on the for statements */
static void good1()
{
    int j,k;
    for(j = 0; j < 0; j++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: Do not check the return value */
            putwc((wchar_t)L'A', stdout);
        }
    }
    for(k = 0; k < 1; k++)
    {
        {
            /* FIX: check the return value */
            if (putwc((wchar_t)L'A', stdout) == WEOF)
            {
                printLine("putwc failed!");
            }
        }
    }
}

void CWE252_Unchecked_Return_Value__wchar_t_putc_17_good()
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
    CWE252_Unchecked_Return_Value__wchar_t_putc_17_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE252_Unchecked_Return_Value__wchar_t_putc_17_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
