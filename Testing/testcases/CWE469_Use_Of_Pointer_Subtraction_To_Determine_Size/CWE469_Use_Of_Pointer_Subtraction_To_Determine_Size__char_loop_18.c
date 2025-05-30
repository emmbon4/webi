/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__char_loop_18.c
Label Definition File: CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 469 Use Of Pointer Subtraction To Determine Size
 * Sinks: loop
 *    GoodSink: using correct pointer subtraction to determine length in loop
 *    BadSink : Beginning and end pointers are switched leading to an incorrect length in the loop
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define SRC_STR "abc/opqrstu"

#ifndef OMITBAD

void CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__char_loop_18_bad()
{
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char * data = SRC_STR;
        char dst[100] = "";
        char * end = strchr(data, '/');
        ptrdiff_t i;
        /* FIX: use proper order in pointer subtraction */
        for (i = 0; i < (end - data); i++)
        {
            dst[i] = data[i];
        }
        printLine(dst);
    }
sink:
    {
        char * data = SRC_STR;
        char dst[100] = "";
        char * end = strchr(data, '/');
        ptrdiff_t i;
        /* FLAW: switched the beginning and end pointers around */
        for (i = 0; i < (data - end); i++)
        {
            dst[i] = data[i];
        }
        printLine(dst);
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
        char * data = SRC_STR;
        char dst[100] = "";
        char * end = strchr(data, '/');
        ptrdiff_t i;
        /* FLAW: switched the beginning and end pointers around */
        for (i = 0; i < (data - end); i++)
        {
            dst[i] = data[i];
        }
        printLine(dst);
    }
sink:
    {
        char * data = SRC_STR;
        char dst[100] = "";
        char * end = strchr(data, '/');
        ptrdiff_t i;
        /* FIX: use proper order in pointer subtraction */
        for (i = 0; i < (end - data); i++)
        {
            dst[i] = data[i];
        }
        printLine(dst);
    }
}

void CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__char_loop_18_good()
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
    CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__char_loop_18_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__char_loop_18_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
