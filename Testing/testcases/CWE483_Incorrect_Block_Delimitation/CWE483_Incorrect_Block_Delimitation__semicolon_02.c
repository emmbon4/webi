/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE483_Incorrect_Block_Delimitation__semicolon_02.c
Label Definition File: CWE483_Incorrect_Block_Delimitation.label.xml
Template File: point-flaw-02.tmpl.c
*/
/*
 * @description
 * CWE: 483 Incorrect Block Delimitation
 * Sinks: semicolon
 *    GoodSink: Absence of suspicious semicolon
 *    BadSink : Suspicious semicolon before the if statement brace
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE483_Incorrect_Block_Delimitation__semicolon_02_bad()
{
    if(1)
    {
        {
            int x;
            int y;
            x = (rand() % 3);
            y = 0;
            /* FLAW: Suspicious semicolon before the if statement brace */
            if (x == 0);
            {
                printLine("x == 0");
                y = 1;
            }
            if (y) printLine("x was 0\n");
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            int x;
            int y;
            x = (rand() % 3);
            y = 0;
            /* FIX: Suspicious semicolon before the if statement brace */
            if (x == 0)
            {
                printLine("x == 0");
                y = 1;
            }
            if (y) printLine("x was 0\n");
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
            int x;
            int y;
            x = (rand() % 3);
            y = 0;
            /* FLAW: Suspicious semicolon before the if statement brace */
            if (x == 0);
            {
                printLine("x == 0");
                y = 1;
            }
            if (y) printLine("x was 0\n");
        }
    }
    else
    {
        {
            int x;
            int y;
            x = (rand() % 3);
            y = 0;
            /* FIX: Suspicious semicolon before the if statement brace */
            if (x == 0)
            {
                printLine("x == 0");
                y = 1;
            }
            if (y) printLine("x was 0\n");
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(1)
    {
        {
            int x;
            int y;
            x = (rand() % 3);
            y = 0;
            /* FIX: Suspicious semicolon before the if statement brace */
            if (x == 0)
            {
                printLine("x == 0");
                y = 1;
            }
            if (y) printLine("x was 0\n");
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            int x;
            int y;
            x = (rand() % 3);
            y = 0;
            /* FLAW: Suspicious semicolon before the if statement brace */
            if (x == 0);
            {
                printLine("x == 0");
                y = 1;
            }
            if (y) printLine("x was 0\n");
        }
    }
}

void CWE483_Incorrect_Block_Delimitation__semicolon_02_good()
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
    CWE483_Incorrect_Block_Delimitation__semicolon_02_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE483_Incorrect_Block_Delimitation__semicolon_02_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
