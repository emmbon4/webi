/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE252_Unchecked_Return_Value__wchar_t_fputc_09.c
Label Definition File: CWE252_Unchecked_Return_Value.string.label.xml
Template File: point-flaw-09.tmpl.c
*/
/*
 * @description
 * CWE: 252 Unchecked Return Value
 * Sinks: fputc
 *    GoodSink: Check if fputwc() fails
 *    BadSink : Do not check if fputwc() fails
 * Flow Variant: 09 Control flow: if(global_const_t) and if(global_const_f)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE252_Unchecked_Return_Value__wchar_t_fputc_09_bad()
{
    if(global_const_t)
    {
        {
            /* FLAW: Do not check the return value */
            fputwc((wchar_t)L'A', stdout);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: check the return value */
            if (fputwc((wchar_t)L'A', stdout) == WEOF)
            {
                printLine("fputwc failed!");
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(global_const_f) instead of if(global_const_t) */
static void good1()
{
    if(global_const_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: Do not check the return value */
            fputwc((wchar_t)L'A', stdout);
        }
    }
    else
    {
        {
            /* FIX: check the return value */
            if (fputwc((wchar_t)L'A', stdout) == WEOF)
            {
                printLine("fputwc failed!");
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(global_const_t)
    {
        {
            /* FIX: check the return value */
            if (fputwc((wchar_t)L'A', stdout) == WEOF)
            {
                printLine("fputwc failed!");
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: Do not check the return value */
            fputwc((wchar_t)L'A', stdout);
        }
    }
}

void CWE252_Unchecked_Return_Value__wchar_t_fputc_09_good()
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
    CWE252_Unchecked_Return_Value__wchar_t_fputc_09_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE252_Unchecked_Return_Value__wchar_t_fputc_09_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
