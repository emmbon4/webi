/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_64b.c
Label Definition File: CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic.label.xml
Template File: sources-sink-64b.tmpl.c
*/
/*
 * @description
 * CWE: 588 Attempt to Access Child of a Non Structure Type
 * BadSource:  Void pointer to an int
 * GoodSource: Void pointer to a twoints struct
 * Sinks:
 *    BadSink : Print data
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_64b_bad_sink(void * void_data_ptr)
{
    /* cast void pointer to a pointer of the appropriate type */
    void * * data_ptr = (void * *)void_data_ptr;
    /* dereference data_ptr into data */
    void * data = (*data_ptr);
    /* POTENTIAL FLAW: Attempt to print a struct when data may be a non-struct data type */
    printStructLine((twoints *)data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE588_Attempt_To_Access_Child_Of_A_Non_Structure_Pointer__basic_64b_goodG2B_sink(void * void_data_ptr)
{
    /* cast void pointer to a pointer of the appropriate type */
    void * * data_ptr = (void * *)void_data_ptr;
    /* dereference data_ptr into data */
    void * data = (*data_ptr);
    /* POTENTIAL FLAW: Attempt to print a struct when data may be a non-struct data type */
    printStructLine((twoints *)data);
}

#endif /* OMITGOOD */
