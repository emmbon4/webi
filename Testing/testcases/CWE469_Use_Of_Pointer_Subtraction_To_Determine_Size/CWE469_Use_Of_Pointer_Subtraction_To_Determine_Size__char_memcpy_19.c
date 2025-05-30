/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__char_memcpy_19.c
Label Definition File: CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size.label.xml
Template File: point-flaw-19.tmpl.c
*/
/*
 * @description
 * CWE: 469 Use Of Pointer Subtraction To Determine Size
 * Sinks: memcpy
 *    GoodSink: using correct pointer subtraction to determine length in memcpy()
 *    BadSink : Beginning and end pointers are switched leading to an incorrect length in memcpy()
 * Flow Variant: 19 Control flow: Dead code after a return
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define SRC_STR "abc/opqrstu"

#ifndef OMITBAD

void CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__char_memcpy_19_bad()
{
    {
        char * data = SRC_STR;
        char dst[100] = "";
        char * end = strchr(data, '/');
        /* FLAW: switched the beginning and end pointers around */
        memcpy(dst, data, sizeof(char)*(data - end));
        printLine(dst);
    }
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char * data = SRC_STR;
        char dst[100] = "";
        char * end = strchr(data, '/');
        /* FIX: use proper order in pointer subtraction */
        memcpy(dst, data, sizeof(char)*(end - data));
        printLine(dst);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() reverses the GoodSinkBody and the BadSinkBody so that the BadSinkBody never runs */
static void good1()
{
    {
        char * data = SRC_STR;
        char dst[100] = "";
        char * end = strchr(data, '/');
        /* FIX: use proper order in pointer subtraction */
        memcpy(dst, data, sizeof(char)*(end - data));
        printLine(dst);
    }
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char * data = SRC_STR;
        char dst[100] = "";
        char * end = strchr(data, '/');
        /* FLAW: switched the beginning and end pointers around */
        memcpy(dst, data, sizeof(char)*(data - end));
        printLine(dst);
    }
}

void CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__char_memcpy_19_good()
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
    CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__char_memcpy_19_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE469_Use_Of_Pointer_Subtraction_To_Determine_Size__char_memcpy_19_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
