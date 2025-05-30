/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE467_Use_of_sizeof_on_Pointer_Type__long_long_52b.c
Label Definition File: CWE467_Use_of_sizeof_on_Pointer_Type.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 467 Use of sizeof() on a Pointer Type
 * BadSource:  Initialize the source buffer using the size of a pointer
 * GoodSource: Initialize the source buffer using the size of the DataElementType
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE467_Use_of_sizeof_on_Pointer_Type__long_long_52c_bad_sink(long long * data);

void CWE467_Use_of_sizeof_on_Pointer_Type__long_long_52b_bad_sink(long long * data)
{
    CWE467_Use_of_sizeof_on_Pointer_Type__long_long_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE467_Use_of_sizeof_on_Pointer_Type__long_long_52c_goodG2B_sink(long long * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE467_Use_of_sizeof_on_Pointer_Type__long_long_52b_goodG2B_sink(long long * data)
{
    CWE467_Use_of_sizeof_on_Pointer_Type__long_long_52c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
