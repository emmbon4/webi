/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE390_Error_Without_Action__wchar_t_putchar_16.c
Label Definition File: CWE390_Error_Without_Action.string.label.xml
Template File: point-flaw-16.tmpl.c
*/
/*
 * @description
 * CWE: 390 Detection of Error Condition Without Action
 * Sinks: putchar
 *    GoodSink: Check if putwchar() failed and handle errors properly
 *    BadSink : Check to see if putwchar() failed, but do nothing about it
 * Flow Variant: 16 Control flow: while(1) and while(0)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE390_Error_Without_Action__wchar_t_putchar_16_bad()
{
    while(1)
    {
        {
            /* FLAW: check the return value, but do nothing if there is an error */
            if (putwchar((wchar_t)L'A') == WEOF)
            {
                /* do nothing */
            }
        }
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: check the return value and handle errors properly */
            if (putwchar((wchar_t)L'A') == WEOF)
            {
                printLine("putwchar failed!");
                exit(1);
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
            /* FLAW: check the return value, but do nothing if there is an error */
            if (putwchar((wchar_t)L'A') == WEOF)
            {
                /* do nothing */
            }
        }
        break;
    }
    while(1)
    {
        {
            /* FIX: check the return value and handle errors properly */
            if (putwchar((wchar_t)L'A') == WEOF)
            {
                printLine("putwchar failed!");
                exit(1);
            }
        }
        break;
    }
}

void CWE390_Error_Without_Action__wchar_t_putchar_16_good()
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
    CWE390_Error_Without_Action__wchar_t_putchar_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE390_Error_Without_Action__wchar_t_putchar_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
