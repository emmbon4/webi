/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__malloc_char_memmove_66a.c
Label Definition File: CWE127_Buffer_Underread__malloc.label.xml
Template File: sources-sink-66a.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sinks: memmove
 *    BadSink : Copy data to string using memmove
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE127_Buffer_Underread__malloc_char_memmove_66b_bad_sink(char * data_array[]);

void CWE127_Buffer_Underread__malloc_char_memmove_66_bad()
{
    char * data;
    char * data_array[5];
    data = NULL;
    {
        char * data_buf = (char *)malloc(100*sizeof(char));
        memset(data_buf, 'A', 100-1);
        data_buf[100-1] = '\0';
        /* FLAW: Set data pointer to before the allocated memory buffer */
        data = data_buf - 8;
    }
    /* put data in array */
    data_array[2] = data;
    CWE127_Buffer_Underread__malloc_char_memmove_66b_bad_sink(data_array);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE127_Buffer_Underread__malloc_char_memmove_66b_goodG2B_sink(char * data_array[]);

static void goodG2B()
{
    char * data;
    char * data_array[5];
    data = NULL;
    {
        char * data_buf = (char *)malloc(100*sizeof(char));
        memset(data_buf, 'A', 100-1);
        data_buf[100-1] = '\0';
        /* FIX: Set data pointer to the allocated memory buffer */
        data = data_buf;
    }
    data_array[2] = data;
    CWE127_Buffer_Underread__malloc_char_memmove_66b_goodG2B_sink(data_array);
}

void CWE127_Buffer_Underread__malloc_char_memmove_66_good()
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
    CWE127_Buffer_Underread__malloc_char_memmove_66_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE127_Buffer_Underread__malloc_char_memmove_66_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
