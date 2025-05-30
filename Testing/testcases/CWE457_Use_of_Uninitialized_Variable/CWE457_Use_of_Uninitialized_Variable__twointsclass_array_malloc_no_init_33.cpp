/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__twointsclass_array_malloc_no_init_33.cpp
Label Definition File: CWE457_Use_of_Uninitialized_Variable__twointsclass_array.label.xml
Template File: sources-sinks-33.tmpl.cpp
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 33 Data flow: use of a C++ reference to data within the same function
 *
 * */

#include "std_testcase.h"

namespace CWE457_Use_of_Uninitialized_Variable__twointsclass_array_malloc_no_init_33
{

#ifndef OMITBAD

void bad()
{
    twointsclass * data;
    twointsclass * &data_ref = data;
    data = (twointsclass *)malloc(10*sizeof(twointsclass));
    /* Don't initialize data */
    ; /* empty statement needed for some flow variants */
    {
        twointsclass * data = data_ref;
        for(int i=0; i<10; i++)
        {
            printIntLine(data[i].a);
            printIntLine(data[i].b);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    twointsclass * data;
    twointsclass * &data_ref = data;
    data = (twointsclass *)malloc(10*sizeof(twointsclass));
    for(int i=0; i<10; i++)
    {
        data[i].a = i;
        data[i].b = i;
    }
    {
        twointsclass * data = data_ref;
        for(int i=0; i<10; i++)
        {
            printIntLine(data[i].a);
            printIntLine(data[i].b);
        }
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    twointsclass * data;
    twointsclass * &data_ref = data;
    data = (twointsclass *)malloc(10*sizeof(twointsclass));
    /* Don't initialize data */
    ; /* empty statement needed for some flow variants */
    {
        twointsclass * data = data_ref;
        for(int i=0; i<10; i++)
        {
            data[i].a = i;
            data[i].b = i;
        }
        for(int i=0; i<10; i++)
        {
            printIntLine(data[i].a);
            printIntLine(data[i].b);
        }
    }
}

void good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */
#ifdef INCLUDEMAIN

using namespace CWE457_Use_of_Uninitialized_Variable__twointsclass_array_malloc_no_init_33; // so that we can use good and bad easily

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
