/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE193_Off_by_One_Error__wchar_t_ncpy_03.c
Label Definition File: CWE193_Off_by_One_Error.label.xml
Template File: point-flaw-03.tmpl.c
*/
/*
 * @description
 * CWE: 193 Off by One Error
 * Sinks: ncpy
 *    GoodSink: Use wcsncpy() to perform a string copy correctly
 *    BadSink : Use wcsncpy() to perform a string copy, but copy one too many characters
 * Flow Variant: 03 Control flow: if(5==5) and if(5!=5)
 *
 * */

#include "std_testcase.h"

#define DST_SZ 4
#define COPY_STR L"AAAAAAAAAAAAAAAAAAAAA" /* maintenance note: ensure this is > DST_SZ */

#ifndef OMITBAD

void CWE193_Off_by_One_Error__wchar_t_ncpy_03_bad()
{
    if(5==5)
    {
        {
            wchar_t dst[DST_SZ];
            /* FLAW: Passed DST_SZ to wcsncpy */
            wcsncpy(dst, COPY_STR, DST_SZ);
            printWLine(dst);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t dst[DST_SZ];
            /* FIX: strncpy the correct amount */
            wcsncpy(dst, COPY_STR, DST_SZ-1);
            /* null terminate the string to make tools happy, even though it is unnecessary here */
            dst[DST_SZ-1] = L'\0';
            printWLine(dst);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(5!=5) instead of if(5==5) */
static void good1()
{
    if(5!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t dst[DST_SZ];
            /* FLAW: Passed DST_SZ to wcsncpy */
            wcsncpy(dst, COPY_STR, DST_SZ);
            printWLine(dst);
        }
    }
    else
    {
        {
            wchar_t dst[DST_SZ];
            /* FIX: strncpy the correct amount */
            wcsncpy(dst, COPY_STR, DST_SZ-1);
            /* null terminate the string to make tools happy, even though it is unnecessary here */
            dst[DST_SZ-1] = L'\0';
            printWLine(dst);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(5==5)
    {
        {
            wchar_t dst[DST_SZ];
            /* FIX: strncpy the correct amount */
            wcsncpy(dst, COPY_STR, DST_SZ-1);
            /* null terminate the string to make tools happy, even though it is unnecessary here */
            dst[DST_SZ-1] = L'\0';
            printWLine(dst);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t dst[DST_SZ];
            /* FLAW: Passed DST_SZ to wcsncpy */
            wcsncpy(dst, COPY_STR, DST_SZ);
            printWLine(dst);
        }
    }
}

void CWE193_Off_by_One_Error__wchar_t_ncpy_03_good()
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
    CWE193_Off_by_One_Error__wchar_t_ncpy_03_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE193_Off_by_One_Error__wchar_t_ncpy_03_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
