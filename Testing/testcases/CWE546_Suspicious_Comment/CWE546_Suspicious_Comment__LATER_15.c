/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE546_Suspicious_Comment__LATER_15.c
Label Definition File: CWE546_Suspicious_Comment.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 546 Suspicious Comment
 * Sinks: LATER
 *    GoodSink: Comments show no indications that the code is unfinished
 *    BadSink : Comment contains the word LATER
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE546_Suspicious_Comment__LATER_15_bad()
{
    switch(6)
    {
    case 6:
        /* FLAW: The following comment has the letters 'LATER' in it*/
        /* LATER: This comment has the letters 'LATER' in it, which is certainly
         * suspicious, because it could indicate this code is not finished.
         */
        printLine("Hello");
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Removed the suspicious comments */
        printLine("Hello");
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() changes the switch to switch(5) */
static void good1()
{
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: The following comment has the letters 'LATER' in it*/
        /* LATER: This comment has the letters 'LATER' in it, which is certainly
         * suspicious, because it could indicate this code is not finished.
         */
        printLine("Hello");
        break;
    default:
        /* FIX: Removed the suspicious comments */
        printLine("Hello");
    }
}

/* good2() reverses the blocks in the switch */
static void good2()
{
    switch(6)
    {
    case 6:
        /* FIX: Removed the suspicious comments */
        printLine("Hello");
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: The following comment has the letters 'LATER' in it*/
        /* LATER: This comment has the letters 'LATER' in it, which is certainly
         * suspicious, because it could indicate this code is not finished.
         */
        printLine("Hello");
    }
}

void CWE546_Suspicious_Comment__LATER_15_good()
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
    CWE546_Suspicious_Comment__LATER_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE546_Suspicious_Comment__LATER_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
