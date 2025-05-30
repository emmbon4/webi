/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__char_ncpy_01.c
Label Definition File: CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 469 Use Of Pointer Subtraction To Determine Size
 * Sinks: ncpy
 *    GoodSink: using correct pointer subtraction to determine length in strncpy()
 *    BadSink : Beginning and end pointers are switched leading to an incorrect length in strncpy()
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define SRC_STR "abc/opqrstu"

#ifndef OMITBAD

void CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__char_ncpy_01_bad()
{
    {
        char * data = SRC_STR;
        char dst[100] = "";
        char * end = strchr(data, '/');
        /* FLAW: switched the beginning and end pointers around */
        strncpy(dst, data, data - end);
        printLine(dst);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    {
        char * data = SRC_STR;
        char dst[100] = "";
        char * end = strchr(data, '/');
        /* FIX: use proper order in pointer subtraction */
        strncpy(dst, data, end - data);
        printLine(dst);
    }
}

void CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__char_ncpy_01_good()
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
    CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__char_ncpy_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__char_ncpy_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
