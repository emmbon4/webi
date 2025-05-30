/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE193_Off_by_One_Error__wchar_t_memmove_18.c
Label Definition File: CWE193_Off_by_One_Error.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 193 Off by One Error
 * Sinks: memmove
 *    GoodSink: Use memmove() to perform a string copy correctly
 *    BadSink : Use memmove() to perform a string copy, but copy one too many characters
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#define DST_SZ 4
#define COPY_STR L"AAAAAAAAAAAAAAAAAAAAA" /* maintenance note: ensure this is > DST_SZ */

#ifndef OMITBAD

void CWE193_Off_by_One_Error__wchar_t_memmove_18_bad()
{
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        wchar_t dst[DST_SZ];
        /* FIX: memmove the correct amount */
        memmove(dst, COPY_STR, (DST_SZ-1)*sizeof(wchar_t));
        /* null terminate the string */
        dst[DST_SZ-1] = L'\0';
        printWLine(dst);
    }
sink:
    {
        wchar_t dst[DST_SZ];
        /* FLAW: Passed DST_SZ to memmove() */
        memmove(dst, COPY_STR, DST_SZ*sizeof(wchar_t));
        printWLine(dst);
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
        wchar_t dst[DST_SZ];
        /* FLAW: Passed DST_SZ to memmove() */
        memmove(dst, COPY_STR, DST_SZ*sizeof(wchar_t));
        printWLine(dst);
    }
sink:
    {
        wchar_t dst[DST_SZ];
        /* FIX: memmove the correct amount */
        memmove(dst, COPY_STR, (DST_SZ-1)*sizeof(wchar_t));
        /* null terminate the string */
        dst[DST_SZ-1] = L'\0';
        printWLine(dst);
    }
}

void CWE193_Off_by_One_Error__wchar_t_memmove_18_good()
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
    CWE193_Off_by_One_Error__wchar_t_memmove_18_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE193_Off_by_One_Error__wchar_t_memmove_18_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
