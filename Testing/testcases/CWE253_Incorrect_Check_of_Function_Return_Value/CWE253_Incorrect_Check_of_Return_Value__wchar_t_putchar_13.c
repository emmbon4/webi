/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Return_Value__wchar_t_putchar_13.c
Label Definition File: CWE253_Incorrect_Check_of_Return_Value.string.label.xml
Template File: point-flaw-13.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: putchar
 *    GoodSink: Correctly check if putwchar() failed
 *    BadSink : Incorrectly check if putwchar() failed
 * Flow Variant: 13 Control flow: if(global_const_five==5) and if(global_const_five!=5)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE253_Incorrect_Check_of_Return_Value__wchar_t_putchar_13_bad()
{
    if(global_const_five==5)
    {
        {
            /* FLAW: putwchar() might fail, in which case the return value will be WEOF (-1), but
             * we are checking to see if the return value is 0 */
            if (putwchar((wchar_t)L'A') == 0)
            {
                printLine("putwchar failed!");
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: check for the correct return value */
            if (putwchar((wchar_t)L'A') == WEOF)
            {
                printLine("putwchar failed!");
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(global_const_five!=5) instead of if(global_const_five==5) */
static void good1()
{
    if(global_const_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: putwchar() might fail, in which case the return value will be WEOF (-1), but
             * we are checking to see if the return value is 0 */
            if (putwchar((wchar_t)L'A') == 0)
            {
                printLine("putwchar failed!");
            }
        }
    }
    else
    {
        {
            /* FIX: check for the correct return value */
            if (putwchar((wchar_t)L'A') == WEOF)
            {
                printLine("putwchar failed!");
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(global_const_five==5)
    {
        {
            /* FIX: check for the correct return value */
            if (putwchar((wchar_t)L'A') == WEOF)
            {
                printLine("putwchar failed!");
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: putwchar() might fail, in which case the return value will be WEOF (-1), but
             * we are checking to see if the return value is 0 */
            if (putwchar((wchar_t)L'A') == 0)
            {
                printLine("putwchar failed!");
            }
        }
    }
}

void CWE253_Incorrect_Check_of_Return_Value__wchar_t_putchar_13_good()
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
    CWE253_Incorrect_Check_of_Return_Value__wchar_t_putchar_13_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE253_Incorrect_Check_of_Return_Value__wchar_t_putchar_13_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
