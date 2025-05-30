/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE242_Use_of_Inherently_Dangerous_Function__basic_19.c
Label Definition File: CWE242_Use_of_Inherently_Dangerous_Function__basic.label.xml
Template File: point-flaw-19.tmpl.c
*/
/*
 * @description
 * CWE: 242 Use of Inherently Dangerous Function
 * Sinks:
 *    GoodSink: Use fgets() for bounded user input
 *    BadSink : Use gets() for user input
 * Flow Variant: 19 Control flow: Dead code after a return
 *
 * */

#include "std_testcase.h"

#define DST_SZ 10

#ifndef OMITBAD

void CWE242_Use_of_Inherently_Dangerous_Function__basic_19_bad()
{
    {
        char dst[DST_SZ];
        char *result;
        /* FLAW: gets is inherently dangerous and cannot be used safely. */
        /* INCIDENTAL CWE120 Buffer Overflow since gets is inherently dangerous and is
         * an unbounded copy. */
        result = gets(dst);
        /* Verify return value */
        if( NULL == result )
        {
            /* error condition */
            printLine("Error Condition: alter control flow to indicate action taken");
            exit(1);
        }
        dst[DST_SZ-1] = '\0';
        printLine(dst);
    }
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char dst[DST_SZ];
        char *result;
        /* FIX: use fgets for bounded read from stdin*/
        result = fgets(dst, DST_SZ, stdin);
        /* Verify return value */
        if( NULL == result )
        {
            /* error condition */
            printLine("Error Condition: alter control flow to indicate action taken");
            exit(1);
        }
        dst[DST_SZ-1] = '\0';
        printLine(dst);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() reverses the GoodSinkBody and the BadSinkBody so that the BadSinkBody never runs */
static void good1()
{
    {
        char dst[DST_SZ];
        char *result;
        /* FIX: use fgets for bounded read from stdin*/
        result = fgets(dst, DST_SZ, stdin);
        /* Verify return value */
        if( NULL == result )
        {
            /* error condition */
            printLine("Error Condition: alter control flow to indicate action taken");
            exit(1);
        }
        dst[DST_SZ-1] = '\0';
        printLine(dst);
    }
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char dst[DST_SZ];
        char *result;
        /* FLAW: gets is inherently dangerous and cannot be used safely. */
        /* INCIDENTAL CWE120 Buffer Overflow since gets is inherently dangerous and is
         * an unbounded copy. */
        result = gets(dst);
        /* Verify return value */
        if( NULL == result )
        {
            /* error condition */
            printLine("Error Condition: alter control flow to indicate action taken");
            exit(1);
        }
        dst[DST_SZ-1] = '\0';
        printLine(dst);
    }
}

void CWE242_Use_of_Inherently_Dangerous_Function__basic_19_good()
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
    CWE242_Use_of_Inherently_Dangerous_Function__basic_19_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE242_Use_of_Inherently_Dangerous_Function__basic_19_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
