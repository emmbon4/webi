/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Return_Value__char_putchar_18.c
Label Definition File: CWE253_Incorrect_Check_of_Return_Value.string.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: putchar
 *    GoodSink: Correctly check if putchar() failed
 *    BadSink : Incorrectly check if putchar() failed
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE253_Incorrect_Check_of_Return_Value__char_putchar_18_bad()
{
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        /* FIX: check for the correct return value */
        if (putchar((int)'A') == EOF)
        {
            printLine("putchar failed!");
        }
    }
sink:
    {
        /* FLAW: putchar() might fail, in which case the return value will be EOF (-1), but
         * we are checking to see if the return value is 0 */
        if (putchar((int)'A') == 0)
        {
            printLine("putchar failed!");
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() reverses the blocks on the goto statement */
static void good1()
{
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        /* FLAW: putchar() might fail, in which case the return value will be EOF (-1), but
         * we are checking to see if the return value is 0 */
        if (putchar((int)'A') == 0)
        {
            printLine("putchar failed!");
        }
    }
sink:
    {
        /* FIX: check for the correct return value */
        if (putchar((int)'A') == EOF)
        {
            printLine("putchar failed!");
        }
    }
}

void CWE253_Incorrect_Check_of_Return_Value__char_putchar_18_good()
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
    CWE253_Incorrect_Check_of_Return_Value__char_putchar_18_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE253_Incorrect_Check_of_Return_Value__char_putchar_18_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
