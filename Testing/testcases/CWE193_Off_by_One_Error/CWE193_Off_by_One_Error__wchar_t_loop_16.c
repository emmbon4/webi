/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE193_Off_by_One_Error__wchar_t_loop_16.c
Label Definition File: CWE193_Off_by_One_Error.label.xml
Template File: point-flaw-16.tmpl.c
*/
/*
 * @description
 * CWE: 193 Off by One Error
 * Sinks: loop
 *    GoodSink: Use a loop to perform a string copy without overflowing the destination buffer
 *    BadSink : Use a loop to perform a string copy, but overflow the destination buffer
 * Flow Variant: 16 Control flow: while(1) and while(0)
 *
 * */

#include "std_testcase.h"

#define DST_SZ 4
#define COPY_STR L"AAAAAAAAAAAAAAAAAAAAA" /* maintenance note: ensure this is > DST_SZ */

#ifndef OMITBAD

void CWE193_Off_by_One_Error__wchar_t_loop_16_bad()
{
    while(1)
    {
        {
            size_t i;
            wchar_t dst[DST_SZ];
            const wchar_t *src = COPY_STR;
            /* FLAW: did <= instead of < in copy (index is off-by-one)
             * INCIDENTAL CWE121 - Stack Based Buffer Overflow
             */
            for (i = 0; i <= DST_SZ; i++)
            {
                dst[i] = src[i];
            }
            dst[DST_SZ-1] = L'\0'; /* null terminate */
            printWLine(dst);
        }
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            size_t i;
            wchar_t dst[DST_SZ];
            const wchar_t *src = COPY_STR;
            /* FIX: use <, ensures we do not write out of bounds */
            for (i = 0; i < DST_SZ; i++)
            {
                dst[i] = src[i];
            }
            dst[DST_SZ-1] = L'\0'; /* null terminate */
            printWLine(dst);
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
            size_t i;
            wchar_t dst[DST_SZ];
            const wchar_t *src = COPY_STR;
            /* FLAW: did <= instead of < in copy (index is off-by-one)
             * INCIDENTAL CWE121 - Stack Based Buffer Overflow
             */
            for (i = 0; i <= DST_SZ; i++)
            {
                dst[i] = src[i];
            }
            dst[DST_SZ-1] = L'\0'; /* null terminate */
            printWLine(dst);
        }
        break;
    }
    while(1)
    {
        {
            size_t i;
            wchar_t dst[DST_SZ];
            const wchar_t *src = COPY_STR;
            /* FIX: use <, ensures we do not write out of bounds */
            for (i = 0; i < DST_SZ; i++)
            {
                dst[i] = src[i];
            }
            dst[DST_SZ-1] = L'\0'; /* null terminate */
            printWLine(dst);
        }
        break;
    }
}

void CWE193_Off_by_One_Error__wchar_t_loop_16_good()
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
    CWE193_Off_by_One_Error__wchar_t_loop_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE193_Off_by_One_Error__wchar_t_loop_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
