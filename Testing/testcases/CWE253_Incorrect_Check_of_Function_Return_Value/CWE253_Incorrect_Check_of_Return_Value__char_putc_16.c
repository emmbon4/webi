/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Return_Value__char_putc_16.c
Label Definition File: CWE253_Incorrect_Check_of_Return_Value.string.label.xml
Template File: point-flaw-16.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: putc
 *    GoodSink: Correctly check if putc() failed
 *    BadSink : Incorrectly check if putc() failed
 * Flow Variant: 16 Control flow: while(1) and while(0)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE253_Incorrect_Check_of_Return_Value__char_putc_16_bad()
{
    while(1)
    {
        {
            /* FLAW: putc() might fail, in which case the return value will be EOF (-1), but
             * we are checking to see if the return value is 0 */
            if (putc((int)'A', stdout) == 0)
            {
                printLine("putc failed!");
            }
        }
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: check for the correct return value */
            if (putc((int)'A', stdout) == EOF)
            {
                printLine("putc failed!");
            }
        }
        break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() changes the conditions on the while statements */
static void good1()
{
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FLAW: putc() might fail, in which case the return value will be EOF (-1), but
             * we are checking to see if the return value is 0 */
            if (putc((int)'A', stdout) == 0)
            {
                printLine("putc failed!");
            }
        }
        break;
    }
    while(1)
    {
        {
            /* FIX: check for the correct return value */
            if (putc((int)'A', stdout) == EOF)
            {
                printLine("putc failed!");
            }
        }
        break;
    }
}

void CWE253_Incorrect_Check_of_Return_Value__char_putc_16_good()
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
    CWE253_Incorrect_Check_of_Return_Value__char_putc_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE253_Incorrect_Check_of_Return_Value__char_putc_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
