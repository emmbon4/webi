/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_twointsclass_34.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-34.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

namespace CWE401_Memory_Leak__new_twointsclass_34
{

typedef union
{
    twointsclass * a;
    twointsclass * b;
} union_type;

#ifndef OMITBAD

void bad()
{
    twointsclass * data;
    union_type my_union;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new twointsclass;
    /* Initialize and make use of data */
    data->a = 0;
    data->b = 0;
    printIntLine(data->a);
    printIntLine(data->b);
    my_union.a = data;
    {
        twointsclass * data = my_union.b;
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    twointsclass * data;
    union_type my_union;
    data = NULL;
    /* FIX: Use memory allocated on the stack */
    twointsclass data_good;
    data = &data_good;
    /* Initialize and make use of data */
    data->a = 0;
    data->b = 0;
    printIntLine(data->a);
    printIntLine(data->b);
    my_union.a = data;
    {
        twointsclass * data = my_union.b;
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    twointsclass * data;
    union_type my_union;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new twointsclass;
    /* Initialize and make use of data */
    data->a = 0;
    data->b = 0;
    printIntLine(data->a);
    printIntLine(data->b);
    my_union.a = data;
    {
        twointsclass * data = my_union.b;
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

using namespace CWE401_Memory_Leak__new_twointsclass_34; // so that we can use good and bad easily

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
