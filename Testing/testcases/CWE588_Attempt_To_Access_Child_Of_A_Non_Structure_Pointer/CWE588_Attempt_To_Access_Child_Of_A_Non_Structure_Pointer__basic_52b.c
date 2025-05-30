/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_52b.c
Label Definition File: CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 588 Attempt to Access Child of a Non Structure Type
 * BadSource:  Void pointer to an int
 * GoodSource: Void pointer to a twoints struct
 * Sink:
 *    BadSink : Print data
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_52c_bad_sink(void * data);

void CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_52b_bad_sink(void * data)
{
    CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_52c_goodG2B_sink(void * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_52b_goodG2B_sink(void * data)
{
    CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_52c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
