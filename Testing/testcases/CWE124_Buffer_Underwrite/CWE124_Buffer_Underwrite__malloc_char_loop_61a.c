/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__malloc_char_loop_61a.c
Label Definition File: CWE124_Buffer_Underwrite__malloc.label.xml
Template File: sources-sink-61a.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sinks: loop
 *    BadSink : Copy string to data using a loop
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
char * CWE124_Buffer_Underwrite__malloc_char_loop_61b_bad_source(char * data);

void CWE124_Buffer_Underwrite__malloc_char_loop_61_bad()
{
    char * data;
    data = NULL;
    data = CWE124_Buffer_Underwrite__malloc_char_loop_61b_bad_source(data);
    {
        size_t i;
        char src[100];
        memset(src, 'C', 100-1); /* fill with 'C's */
        src[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copying data to memory before the destination buffer */
        for (i = 0; i < 100; i++)
        {
            data[i] = src[i];
        }
        /* Ensure the destination buffer is null terminated */
        data[100-1] = '\0';
        printLine(data);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
           returned by malloc() so can't safely call free() on it */
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
char * CWE124_Buffer_Underwrite__malloc_char_loop_61b_goodG2B_source(char * data);

static void goodG2B()
{
    char * data;
    data = NULL;
    data = CWE124_Buffer_Underwrite__malloc_char_loop_61b_goodG2B_source(data);
    {
        size_t i;
        char src[100];
        memset(src, 'C', 100-1); /* fill with 'C's */
        src[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copying data to memory before the destination buffer */
        for (i = 0; i < 100; i++)
        {
            data[i] = src[i];
        }
        /* Ensure the destination buffer is null terminated */
        data[100-1] = '\0';
        printLine(data);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
           returned by malloc() so can't safely call free() on it */
    }
}

void CWE124_Buffer_Underwrite__malloc_char_loop_61_good()
{
    goodG2B();
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
    CWE124_Buffer_Underwrite__malloc_char_loop_61_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE124_Buffer_Underwrite__malloc_char_loop_61_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
