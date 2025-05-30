/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_struct_twoints_31.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-31.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 31 Data flow using a copy of data within the same function
 *
 * */

#include "std_testcase.h"

namespace CWE401_Memory_Leak__new_struct_twoints_31
{

#ifndef OMITBAD

void bad()
{
    struct _twoints * data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new struct _twoints;
    /* Initialize and make use of data */
    data->a = 0;
    data->b = 0;
    printStructLine((twoints *)data);
    {
        struct _twoints * data_copy = data;
        struct _twoints * data = data_copy;
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    struct _twoints * data;
    data = NULL;
    /* FIX: Use memory allocated on the stack */
    struct _twoints data_good;
    data = &data_good;
    /* Initialize and make use of data */
    data->a = 0;
    data->b = 0;
    printStructLine((twoints *)data);
    {
        struct _twoints * data_copy = data;
        struct _twoints * data = data_copy;
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    struct _twoints * data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new struct _twoints;
    /* Initialize and make use of data */
    data->a = 0;
    data->b = 0;
    printStructLine((twoints *)data);
    {
        struct _twoints * data_copy = data;
        struct _twoints * data = data_copy;
        /* FIX: Deallocate memory */
        delete data;
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

using namespace CWE401_Memory_Leak__new_struct_twoints_31; // so that we can use good and bad easily

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
