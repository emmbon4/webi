/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE193_Off_by_One_Error__char_memmove_15.c
Label Definition File: CWE193_Off_by_One_Error.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 193 Off by One Error
 * Sinks: memmove
 *    GoodSink: Use memmove() to perform a string copy correctly
 *    BadSink : Use memmove() to perform a string copy, but copy one too many characters
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#define DST_SZ 4
#define COPY_STR "AAAAAAAAAAAAAAAAAAAAA" /* maintenance note: ensure this is > DST_SZ */

#ifndef OMITBAD

void CWE193_Off_by_One_Error__char_memmove_15_bad()
{
    switch(6)
    {
    case 6:
    {
        char dst[DST_SZ];
        /* FLAW: Passed DST_SZ to memmove() */
        memmove(dst, COPY_STR, DST_SZ*sizeof(char));
        printLine(dst);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char dst[DST_SZ];
        /* FIX: memmove the correct amount */
        memmove(dst, COPY_STR, (DST_SZ-1)*sizeof(char));
        /* null terminate the string */
        dst[DST_SZ-1] = '\0';
        printLine(dst);
    }
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
    {
        char dst[DST_SZ];
        /* FLAW: Passed DST_SZ to memmove() */
        memmove(dst, COPY_STR, DST_SZ*sizeof(char));
        printLine(dst);
    }
    break;
    default:
    {
        char dst[DST_SZ];
        /* FIX: memmove the correct amount */
        memmove(dst, COPY_STR, (DST_SZ-1)*sizeof(char));
        /* null terminate the string */
        dst[DST_SZ-1] = '\0';
        printLine(dst);
    }
    }
}

/* good2() reverses the blocks in the switch */
static void good2()
{
    switch(6)
    {
    case 6:
    {
        char dst[DST_SZ];
        /* FIX: memmove the correct amount */
        memmove(dst, COPY_STR, (DST_SZ-1)*sizeof(char));
        /* null terminate the string */
        dst[DST_SZ-1] = '\0';
        printLine(dst);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char dst[DST_SZ];
        /* FLAW: Passed DST_SZ to memmove() */
        memmove(dst, COPY_STR, DST_SZ*sizeof(char));
        printLine(dst);
    }
    }
}

void CWE193_Off_by_One_Error__char_memmove_15_good()
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
    CWE193_Off_by_One_Error__char_memmove_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE193_Off_by_One_Error__char_memmove_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
