/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__dest_char_alloca_loop_64b.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__dest.string.label.xml
Template File: sources-sink-64b.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Set data pointer to the bad buffer
 * GoodSource: Set data pointer to the good buffer
 * Sinks: loop
 *    BadSink : Copy string to data using a loop
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE121_Stack_Based_Buffer_Overflow__dest_char_alloca_loop_64b_bad_sink(void * void_data_ptr)
{
    /* cast void pointer to a pointer of the appropriate type */
    char * * data_ptr = (char * *)void_data_ptr;
    /* dereference data_ptr into data */
    char * data = (*data_ptr);
    {
        size_t i;
        char src[100];
        memset(src, 'C', 100-1); /* fill with 'C's */
        src[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: Possible buffer overflow if the size of data is less than the length of src */
        for (i = 0; i < 100; i++)
        {
            data[i] = src[i];
        }
        data[100-1] = '\0'; /* Ensure the destination buffer is null terminated */
        printLine(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__dest_char_alloca_loop_64b_goodG2B_sink(void * void_data_ptr)
{
    /* cast void pointer to a pointer of the appropriate type */
    char * * data_ptr = (char * *)void_data_ptr;
    /* dereference data_ptr into data */
    char * data = (*data_ptr);
    {
        size_t i;
        char src[100];
        memset(src, 'C', 100-1); /* fill with 'C's */
        src[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: Possible buffer overflow if the size of data is less than the length of src */
        for (i = 0; i < 100; i++)
        {
            data[i] = src[i];
        }
        data[100-1] = '\0'; /* Ensure the destination buffer is null terminated */
        printLine(data);
    }
}

#endif /* OMITGOOD */
