/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Return_Value__char_fprintf_03.c
Label Definition File: CWE253_Incorrect_Check_of_Return_Value.string.label.xml
Template File: point-flaw-03.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: fprintf
 *    GoodSink: Correctly check if fprintf() failed
 *    BadSink : Incorrectly check if fprintf() failed
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE253_Incorrect_Check_of_Return_Value__char_fprintf_03_bad()
{
    if(5==5)
    {
        {
            /* FLAW: fprintf() might fail, in which case the return value will be negative, but
             * we are checking to see if the return value is 0 */
            if (fprintf(stdout, "%s\n", "string") == 0)
            {
                printLine("fprintf failed!");
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: check for the correct return value */
            if (fprintf(stdout, "%s\n", "string") < 0)
            {
                printLine("fprintf failed!");
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(5!=5) instead of if(5==5) */
static void good1()
{
    if(5!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: fprintf() might fail, in which case the return value will be negative, but
             * we are checking to see if the return value is 0 */
            if (fprintf(stdout, "%s\n", "string") == 0)
            {
                printLine("fprintf failed!");
            }
        }
    }
    else
    {
        {
            /* FIX: check for the correct return value */
            if (fprintf(stdout, "%s\n", "string") < 0)
            {
                printLine("fprintf failed!");
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(5==5)
    {
        {
            /* FIX: check for the correct return value */
            if (fprintf(stdout, "%s\n", "string") < 0)
            {
                printLine("fprintf failed!");
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: fprintf() might fail, in which case the return value will be negative, but
             * we are checking to see if the return value is 0 */
            if (fprintf(stdout, "%s\n", "string") == 0)
            {
                printLine("fprintf failed!");
            }
        }
    }
}

void CWE253_Incorrect_Check_of_Return_Value__char_fprintf_03_good()
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
    CWE253_Incorrect_Check_of_Return_Value__char_fprintf_03_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE253_Incorrect_Check_of_Return_Value__char_fprintf_03_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
