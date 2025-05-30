/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE489_Leftover_Debug_Code__basic_19.c
Label Definition File: CWE489_Leftover_Debug_Code__basic.label.xml
Template File: point-flaw-19.tmpl.c
*/
/*
 * @description
 * CWE: 489 Leftover Debug Code
 * Sinks:
 *    GoodSink: No debug code
 *    BadSink : Debug code left in
 * Flow Variant: 19 Control flow: Dead code after a return
 *
 * */

#include "std_testcase.h"

#define INPUT_SZ 100

#ifndef OMITBAD

void CWE489_Leftover_Debug_Code__basic_19_bad()
{
    {
        char input[INPUT_SZ];
        if (fgets(input, INPUT_SZ, stdin) == NULL) return;
        /* FLAW: Left some debug code in */
        /* XXX: Remove from release -- if debug is in the string, activate debugging info */
        if (strstr(input, "debug") != NULL)
        {
            printLine("Log some debug info that is inappropriate for release.");
        }
        printLine("This is the actual functionality.");
    }
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char input[INPUT_SZ];
        if (fgets(input, INPUT_SZ, stdin) == NULL) return;
        /* FIX: Eliminate debug code prior to release */
        printLine("This is the actual functionality.");
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() reverses the GoodSinkBody and the BadSinkBody so that the BadSinkBody never runs */
static void good1()
{
    {
        char input[INPUT_SZ];
        if (fgets(input, INPUT_SZ, stdin) == NULL) return;
        /* FIX: Eliminate debug code prior to release */
        printLine("This is the actual functionality.");
    }
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char input[INPUT_SZ];
        if (fgets(input, INPUT_SZ, stdin) == NULL) return;
        /* FLAW: Left some debug code in */
        /* XXX: Remove from release -- if debug is in the string, activate debugging info */
        if (strstr(input, "debug") != NULL)
        {
            printLine("Log some debug info that is inappropriate for release.");
        }
        printLine("This is the actual functionality.");
    }
}

void CWE489_Leftover_Debug_Code__basic_19_good()
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
    CWE489_Leftover_Debug_Code__basic_19_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE489_Leftover_Debug_Code__basic_19_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
