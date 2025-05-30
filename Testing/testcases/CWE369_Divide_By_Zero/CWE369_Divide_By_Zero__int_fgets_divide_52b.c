/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_By_Zero__int_fgets_divide_52b.c
Label Definition File: CWE369_Divide_By_Zero__int.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide By Zero
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Non-zero
 * Sink: divide
 *    BadSink : Divide a constant by data
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(data)*sizeof(data)

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE369_Divide_By_Zero__int_fgets_divide_52c_bad_sink(int data);

void CWE369_Divide_By_Zero__int_fgets_divide_52b_bad_sink(int data)
{
    CWE369_Divide_By_Zero__int_fgets_divide_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE369_Divide_By_Zero__int_fgets_divide_52c_goodG2B_sink(int data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE369_Divide_By_Zero__int_fgets_divide_52b_goodG2B_sink(int data)
{
    CWE369_Divide_By_Zero__int_fgets_divide_52c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
