/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_array_twointsclass_62b.cpp
Label Definition File: CWE401_Memory_Leak__new_array.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new[]
 * GoodSource: Point data to a stack buffer
 * Sinks:
 *    GoodSink: call delete[] on data
 *    BadSink : no deallocation of data
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE401_Memory_Leak__new_array_twointsclass_62
{

#ifndef OMITBAD

void bad_source(twointsclass * &data)
{
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new twointsclass[100];
    /* Initialize and make use of data */
    data[0].a = 0;
    data[0].b = 0;
    printIntLine(data[0].a);
    printIntLine(data[0].b);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
void goodG2B_source(twointsclass * &data)
{
    {
        /* FIX: Use memory allocated on the stack */
        twointsclass data_goodbuf[100];
        data = data_goodbuf;
        /* Initialize and make use of data */
        data[0].a = 0;
        data[0].b = 0;
        printIntLine(data[0].a);
        printIntLine(data[0].b);
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
void goodB2G_source(twointsclass * &data)
{
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new twointsclass[100];
    /* Initialize and make use of data */
    data[0].a = 0;
    data[0].b = 0;
    printIntLine(data[0].a);
    printIntLine(data[0].b);
}

#endif /* OMITGOOD */

} // close namespace
