/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE131_Incorrect_Calculation_Of_Buffer_Size__loop_67b.c
Label Definition File: CWE131_Incorrect_Calculation_Of_Buffer_Size.missing_sizeof.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 131 Incorrect Calculation of Buffer Size
 * BadSource:  Allocate memory without using sizeof(int)
 * GoodSource: Allocate memory using sizeof(int)
 * Sinks: loop
 *    BadSink : Copy array to data using a loop
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE131_Incorrect_Calculation_Of_Buffer_Size__loop_67_struct_type
{
    int * a;
} CWE131_Incorrect_Calculation_Of_Buffer_Size__loop_67_struct_type;

#ifndef OMITBAD

void CWE131_Incorrect_Calculation_Of_Buffer_Size__loop_67b_bad_sink(CWE131_Incorrect_Calculation_Of_Buffer_Size__loop_67_struct_type my_struct)
{
    int * data = my_struct.a;
    {
        int data_src[10] = {0};
        size_t i;
        /* POTENTIAL FLAW: Possible buffer overflow if data was not allocated correctly in the source */
        for (i = 0; i < 10; i++)
        {
            data[i] = data_src[i];
        }
        printIntLine(data[0]);
        free(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE131_Incorrect_Calculation_Of_Buffer_Size__loop_67b_goodG2B_sink(CWE131_Incorrect_Calculation_Of_Buffer_Size__loop_67_struct_type my_struct)
{
    int * data = my_struct.a;
    {
        int data_src[10] = {0};
        size_t i;
        /* POTENTIAL FLAW: Possible buffer overflow if data was not allocated correctly in the source */
        for (i = 0; i < 10; i++)
        {
            data[i] = data_src[i];
        }
        printIntLine(data[0]);
        free(data);
    }
}

#endif /* OMITGOOD */
