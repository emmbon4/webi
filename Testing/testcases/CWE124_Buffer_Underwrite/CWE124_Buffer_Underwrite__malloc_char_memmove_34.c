/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE124_Buffer_Underwrite__malloc_char_memmove_34.c
Label Definition File: CWE124_Buffer_Underwrite__malloc.label.xml
Template File: sources-sink-34.tmpl.c
*/
/*
 * @description
 * CWE: 124 Buffer Underwrite
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sinks: memmove
 *    BadSink : Copy string to data using memmove
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef union
{
    char * a;
    char * b;
} CWE124_Buffer_Underwrite__malloc_char_memmove_34_union_type;

#ifndef OMITBAD

void CWE124_Buffer_Underwrite__malloc_char_memmove_34_bad()
{
    char * data;
    CWE124_Buffer_Underwrite__malloc_char_memmove_34_union_type my_union;
    data = NULL;
    {
        char * data_buf = (char *)malloc(100*sizeof(char));
        memset(data_buf, 'A', 100-1);
        data_buf[100-1] = '\0';
        /* FLAW: Set data pointer to before the allocated memory buffer */
        data = data_buf - 8;
    }
    my_union.a = data;
    {
        char * data = my_union.b;
        {
            char src[100];
            memset(src, 'C', 100-1); /* fill with 'C's */
            src[100-1] = '\0'; /* null terminate */
            /* POTENTIAL FLAW: Possibly copying data to memory before the destination buffer */
            memmove(data, src, 100*sizeof(char));
            /* Ensure the destination buffer is null terminated */
            data[100-1] = '\0';
            printLine(data);
            /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
               returned by malloc() so can't safely call free() on it */
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    CWE124_Buffer_Underwrite__malloc_char_memmove_34_union_type my_union;
    data = NULL;
    {
        char * data_buf = (char *)malloc(100*sizeof(char));
        memset(data_buf, 'A', 100-1);
        data_buf[100-1] = '\0';
        /* FIX: Set data pointer to the allocated memory buffer */
        data = data_buf;
    }
    my_union.a = data;
    {
        char * data = my_union.b;
        {
            char src[100];
            memset(src, 'C', 100-1); /* fill with 'C's */
            src[100-1] = '\0'; /* null terminate */
            /* POTENTIAL FLAW: Possibly copying data to memory before the destination buffer */
            memmove(data, src, 100*sizeof(char));
            /* Ensure the destination buffer is null terminated */
            data[100-1] = '\0';
            printLine(data);
            /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
               returned by malloc() so can't safely call free() on it */
        }
    }
}

void CWE124_Buffer_Underwrite__malloc_char_memmove_34_good()
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
    CWE124_Buffer_Underwrite__malloc_char_memmove_34_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE124_Buffer_Underwrite__malloc_char_memmove_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
