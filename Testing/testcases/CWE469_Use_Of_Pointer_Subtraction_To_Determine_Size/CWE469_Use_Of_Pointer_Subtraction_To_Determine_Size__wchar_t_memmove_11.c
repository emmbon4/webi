/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__wchar_t_memmove_11.c
Label Definition File: CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size.label.xml
Template File: point-flaw-11.tmpl.c
*/
/*
 * @description
 * CWE: 469 Use Of Pointer Subtraction To Determine Size
 * Sinks: memmove
 *    GoodSink: using correct pointer subtraction to determine length in memmove()
 *    BadSink : Beginning and end pointers are switched leading to an incorrect length in memmove()
 * Flow Variant: 11 Control flow: if(global_returns_t()) and if(global_returns_f())
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define SRC_STR L"abc/opqrstu"

#ifndef OMITBAD

void CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__wchar_t_memmove_11_bad()
{
    if(global_returns_t())
    {
        {
            wchar_t * data = SRC_STR;
            wchar_t dst[100] = L"";
            wchar_t * end = wcschr(data, L'/');
            /* FLAW: switched the beginning and end pointers around */
            memmove(dst, data, sizeof(wchar_t)*(data - end));
            printWLine(dst);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t * data = SRC_STR;
            wchar_t dst[100] = L"";
            wchar_t * end = wcschr(data, L'/');
            /* FIX: use proper order in pointer subtraction */
            memmove(dst, data, sizeof(wchar_t)*(end - data));
            printWLine(dst);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(global_returns_f()) instead of if(global_returns_t()) */
static void good1()
{
    if(global_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t * data = SRC_STR;
            wchar_t dst[100] = L"";
            wchar_t * end = wcschr(data, L'/');
            /* FLAW: switched the beginning and end pointers around */
            memmove(dst, data, sizeof(wchar_t)*(data - end));
            printWLine(dst);
        }
    }
    else
    {
        {
            wchar_t * data = SRC_STR;
            wchar_t dst[100] = L"";
            wchar_t * end = wcschr(data, L'/');
            /* FIX: use proper order in pointer subtraction */
            memmove(dst, data, sizeof(wchar_t)*(end - data));
            printWLine(dst);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(global_returns_t())
    {
        {
            wchar_t * data = SRC_STR;
            wchar_t dst[100] = L"";
            wchar_t * end = wcschr(data, L'/');
            /* FIX: use proper order in pointer subtraction */
            memmove(dst, data, sizeof(wchar_t)*(end - data));
            printWLine(dst);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t * data = SRC_STR;
            wchar_t dst[100] = L"";
            wchar_t * end = wcschr(data, L'/');
            /* FLAW: switched the beginning and end pointers around */
            memmove(dst, data, sizeof(wchar_t)*(data - end));
            printWLine(dst);
        }
    }
}

void CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__wchar_t_memmove_11_good()
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
    CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__wchar_t_memmove_11_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__wchar_t_memmove_11_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
