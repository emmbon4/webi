/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Return_Value__char_puts_14.c
Label Definition File: CWE253_Incorrect_Check_of_Return_Value.string.label.xml
Template File: point-flaw-14.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: puts
 *    GoodSink: Correctly check if puts() failed
 *    BadSink : Incorrectly check if puts() failed
 * Flow Variant: 14 Control flow: if(global_five==5) and if(global_five!=5)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE253_Incorrect_Check_of_Return_Value__char_puts_14_bad()
{
    if(global_five==5)
    {
        {
            /* FLAW: puts() might fail, in which case the return value will be EOF (-1), but
             * we are checking to see if the return value is 0 */
            if (puts("string") == 0)
            {
                printLine("puts failed!");
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: check for the correct return value */
            if (puts("string") == EOF)
            {
                printLine("puts failed!");
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(global_five!=5) instead of if(global_five==5) */
static void good1()
{
    if(global_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: puts() might fail, in which case the return value will be EOF (-1), but
             * we are checking to see if the return value is 0 */
            if (puts("string") == 0)
            {
                printLine("puts failed!");
            }
        }
    }
    else
    {
        {
            /* FIX: check for the correct return value */
            if (puts("string") == EOF)
            {
                printLine("puts failed!");
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(global_five==5)
    {
        {
            /* FIX: check for the correct return value */
            if (puts("string") == EOF)
            {
                printLine("puts failed!");
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: puts() might fail, in which case the return value will be EOF (-1), but
             * we are checking to see if the return value is 0 */
            if (puts("string") == 0)
            {
                printLine("puts failed!");
            }
        }
    }
}

void CWE253_Incorrect_Check_of_Return_Value__char_puts_14_good()
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
    CWE253_Incorrect_Check_of_Return_Value__char_puts_14_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE253_Incorrect_Check_of_Return_Value__char_puts_14_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
