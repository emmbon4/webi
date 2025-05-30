/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE131_Incorrect_Calculation_Of_Buffer_Size__memcpy_54b.c
Label Definition File: CWE131_Incorrect_Calculation_Of_Buffer_Size.missing_sizeof.label.xml
Template File: sources-sink-54b.tmpl.c
*/
/*
 * @description
 * CWE: 131 Incorrect Calculation of Buffer Size
 * BadSource:  Allocate memory without using sizeof(int)
 * GoodSource: Allocate memory using sizeof(int)
 * Sink: memcpy
 *    BadSink : Copy array to data using memcpy()
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE131_Incorrect_Calculation_Of_Buffer_Size__memcpy_54c_bad_sink(int * data);

void CWE131_Incorrect_Calculation_Of_Buffer_Size__memcpy_54b_bad_sink(int * data)
{
    CWE131_Incorrect_Calculation_Of_Buffer_Size__memcpy_54c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE131_Incorrect_Calculation_Of_Buffer_Size__memcpy_54c_goodG2B_sink(int * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE131_Incorrect_Calculation_Of_Buffer_Size__memcpy_54b_goodG2B_sink(int * data)
{
    CWE131_Incorrect_Calculation_Of_Buffer_Size__memcpy_54c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
