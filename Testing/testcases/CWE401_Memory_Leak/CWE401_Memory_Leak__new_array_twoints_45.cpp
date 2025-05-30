/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_array_twoints_45.cpp
Label Definition File: CWE401_Memory_Leak__new_array.label.xml
Template File: sources-sinks-45.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new[]
 * GoodSource: Point data to a stack buffer
 * Sinks:
 *    GoodSink: call delete[] on data
 *    BadSink : no deallocation of data
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

namespace CWE401_Memory_Leak__new_array_twoints_45
{

static twoints * bad_data;
static twoints * goodG2B_data;
static twoints * goodB2G_data;

#ifndef OMITBAD

static void bad_sink()
{
    twoints * data = bad_data;
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

void bad()
{
    twoints * data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new twoints[100];
    /* Initialize and make use of data */
    data[0].a = 0;
    data[0].b = 0;
    printStructLine(&data[0]);
    bad_data = data;
    bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B_sink()
{
    twoints * data = goodG2B_data;
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

static void goodG2B()
{
    twoints * data;
    data = NULL;
    {
        /* FIX: Use memory allocated on the stack */
        twoints data_goodbuf[100];
        data = data_goodbuf;
        /* Initialize and make use of data */
        data[0].a = 0;
        data[0].b = 0;
        printStructLine(&data[0]);
    }
    goodG2B_data = data;
    goodG2B_sink();
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G_sink()
{
    twoints * data = goodB2G_data;
    /* FIX: Deallocate memory */
    delete[] data;
}

static void goodB2G()
{
    twoints * data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new twoints[100];
    /* Initialize and make use of data */
    data[0].a = 0;
    data[0].b = 0;
    printStructLine(&data[0]);
    goodB2G_data = data;
    goodB2G_sink();
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

using namespace CWE401_Memory_Leak__new_array_twoints_45; // so that we can use good and bad easily

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
