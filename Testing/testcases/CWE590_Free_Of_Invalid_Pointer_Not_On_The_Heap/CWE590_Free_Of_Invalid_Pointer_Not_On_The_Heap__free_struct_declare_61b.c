/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_struct_declare_61b.c
Label Definition File: CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free.label.xml
Template File: sources-sink-61b.tmpl.c
*/
/*
 * @description
 * CWE: 590 Free of Invalid Pointer Not on the Heap
 * BadSource: declare Data buffer is declared on the stack
 * GoodSource: Allocate memory on the heap
 * Sinks:
 *    BadSink : Print then free data
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

twoints * CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_struct_declare_61b_bad_source(twoints * data)
{
    {
        /* FLAW: data is allocated on the stack and deallocated in the BadSink */
        twoints data_buf[100];
        {
            size_t i;
            for (i = 0; i < 100; i++)
            {
                data_buf[i].a = 1;
                data_buf[i].b = 1;
            }
        }
        data = data_buf;
    }
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
twoints * CWE590_Free_Of_Invalid_Pointer_Not_On_The_Heap__free_struct_declare_61b_goodG2B_source(twoints * data)
{
    {
        /* FIX: data is allocated on the heap and deallocated in the BadSink */
        twoints * data_buf = (twoints *)malloc(100*sizeof(twoints));
        {
            size_t i;
            for (i = 0; i < 100; i++)
            {
                data_buf[i].a = 1;
                data_buf[i].b = 1;
            }
        }
        data = data_buf;
    }
    return data;
}

#endif /* OMITGOOD */
