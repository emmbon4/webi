/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Return_Value__char_fputc_09.c
Label Definition File: CWE253_Incorrect_Check_of_Return_Value.string.label.xml
Template File: point-flaw-09.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: fputc
 *    GoodSink: Correctly check if fputc() failed
 *    BadSink : Incorrectly check if fputc() failed
 * Flow Variant: 09 Control flow: if(global_const_t) and if(global_const_f)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE253_Incorrect_Check_of_Return_Value__char_fputc_09_bad()
{
    if(global_const_t)
    {
        {
            /* FLAW: fputc() might fail, in which case the return value will be EOF (-1), but
             * we are checking to see if the return value is 0 */
            if (fputc((int)'A', stdout) == 0)
            {
                printLine("fputc failed!");
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: check for the correct return value */
            if (fputc((int)'A', stdout) == EOF)
            {
                printLine("fputc failed!");
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
            /* FLAW: fputc() might fail, in which case the return value will be EOF (-1), but
             * we are checking to see if the return value is 0 */
            if (fputc((int)'A', stdout) == 0)
            {
                printLine("fputc failed!");
            }
        }
    }
    else
    {
        {
            /* FIX: check for the correct return value */
            if (fputc((int)'A', stdout) == EOF)
            {
                printLine("fputc failed!");
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
            /* FIX: check for the correct return value */
            if (fputc((int)'A', stdout) == EOF)
            {
                printLine("fputc failed!");
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: fputc() might fail, in which case the return value will be EOF (-1), but
             * we are checking to see if the return value is 0 */
            if (fputc((int)'A', stdout) == 0)
            {
                printLine("fputc failed!");
            }
        }
    }
}

void CWE253_Incorrect_Check_of_Return_Value__char_fputc_09_good()
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
    CWE253_Incorrect_Check_of_Return_Value__char_fputc_09_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE253_Incorrect_Check_of_Return_Value__char_fputc_09_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
