/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE464_Insertion_Of_Data_Structure_Sentinel__basic_64b.c
Label Definition File: CWE464_Insertion_Of_Data_Structure_Sentinel__basic.label.xml
Template File: sources-sink-64b.tmpl.c
*/
/*
 * @description
 * CWE: 464 Insertion of Data Structure Sentinel
 * BadSource:  Read in data from the console and convert to an int
 * GoodSource: Set data to a fixed char
 * Sinks:
 *    BadSink : Place data into and print an array
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE464_Insertion_Of_Data_Structure_Sentinel__basic_64b_bad_sink(void * void_data_ptr)
{
    /* cast void pointer to a pointer of the appropriate type */
    char * data_ptr = (char *)void_data_ptr;
    /* dereference data_ptr into data */
    char data = (*data_ptr);
    {
        char char_array[4];
        char_array[0] = 'x';
        /* POTENTIAL FLAW: If data is null, the rest of the array will not be printed */
        char_array[1] = data;
        char_array[2] = 'z';
        char_array[3] = '\0';
        printLine(char_array);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE464_Insertion_Of_Data_Structure_Sentinel__basic_64b_goodG2B_sink(void * void_data_ptr)
{
    /* cast void pointer to a pointer of the appropriate type */
    char * data_ptr = (char *)void_data_ptr;
    /* dereference data_ptr into data */
    char data = (*data_ptr);
    {
        char char_array[4];
        char_array[0] = 'x';
        /* POTENTIAL FLAW: If data is null, the rest of the array will not be printed */
        char_array[1] = data;
        char_array[2] = 'z';
        char_array[3] = '\0';
        printLine(char_array);
    }
}

#endif /* OMITGOOD */
