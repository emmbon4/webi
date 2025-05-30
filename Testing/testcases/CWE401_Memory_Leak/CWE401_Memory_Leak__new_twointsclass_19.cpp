/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_twointsclass_19.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-19.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 19 Control flow: Dead code after a return
 * */

#include "std_testcase.h"

namespace CWE401_Memory_Leak__new_twointsclass_19
{

#ifndef OMITBAD

void bad()
{
    twointsclass * data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new twointsclass;
    /* Initialize and make use of data */
    data->a = 0;
    data->b = 0;
    printIntLine(data->a);
    printIntLine(data->b);
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* FIX: Deallocate memory */
    delete data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by switching statements around return */
static void goodB2G()
{
    twointsclass * data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new twointsclass;
    /* Initialize and make use of data */
    data->a = 0;
    data->b = 0;
    printIntLine(data->a);
    printIntLine(data->b);
    /* FIX: Deallocate memory */
    delete data;
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

/* goodG2B() - use goodsource and badsink by moving BadSource and BadSink to after return */
static void goodG2B()
{
    twointsclass * data;
    data = NULL;
    /* FIX: Use memory allocated on the stack */
    twointsclass data_good;
    data = &data_good;
    /* Initialize and make use of data */
    data->a = 0;
    data->b = 0;
    printIntLine(data->a);
    printIntLine(data->b);
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new twointsclass;
    /* Initialize and make use of data */
    data->a = 0;
    data->b = 0;
    printIntLine(data->a);
    printIntLine(data->b);
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

void good()
{
    goodB2G();
    goodG2B();
}

#endif /* OMITGOOD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE401_Memory_Leak__new_twointsclass_19; // so that we can use good and bad easily

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
