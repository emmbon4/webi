/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Return_Value__char_fputs_02.c
Label Definition File: CWE253_Incorrect_Check_of_Return_Value.string.label.xml
Template File: point-flaw-02.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: fputs
 *    GoodSink: Correctly check if fputs() failed
 *    BadSink : Incorrectly check if fputs() failed
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE253_Incorrect_Check_of_Return_Value__char_fputs_02_bad()
{
    if(1)
    {
        {
            /* FLAW: fputs() might fail, in which case the return value will be EOF (-1), but
             * we are checking to see if the return value is 0 */
            if (fputs("string", stdout) == 0)
            {
                printLine("fputs failed!");
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: check for the correct return value */
            if (fputs("string", stdout) == EOF)
            {
                printLine("fputs failed!");
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(0) instead of if(1) */
static void good1()
{
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: fputs() might fail, in which case the return value will be EOF (-1), but
             * we are checking to see if the return value is 0 */
            if (fputs("string", stdout) == 0)
            {
                printLine("fputs failed!");
            }
        }
    }
    else
    {
        {
            /* FIX: check for the correct return value */
            if (fputs("string", stdout) == EOF)
            {
                printLine("fputs failed!");
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(1)
    {
        {
            /* FIX: check for the correct return value */
            if (fputs("string", stdout) == EOF)
            {
                printLine("fputs failed!");
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: fputs() might fail, in which case the return value will be EOF (-1), but
             * we are checking to see if the return value is 0 */
            if (fputs("string", stdout) == 0)
            {
                printLine("fputs failed!");
            }
        }
    }
}

void CWE253_Incorrect_Check_of_Return_Value__char_fputs_02_good()
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
    CWE253_Incorrect_Check_of_Return_Value__char_fputs_02_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE253_Incorrect_Check_of_Return_Value__char_fputs_02_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
