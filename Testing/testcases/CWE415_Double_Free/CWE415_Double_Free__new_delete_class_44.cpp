/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_class_44.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-44.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 44 Data/control flow: data passed as an argument from one function to a function in the same source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_class_44
{

#ifndef OMITBAD

static void bad_sink(twointsclass * data)
{
    /* POTENTIAL FLAW: Possibly deleting memory twice */
    delete data;
}

void bad()
{
    twointsclass * data;
    /* define a function pointer */
    void (*func_ptr) (twointsclass *) = bad_sink;
    /* Initialize data */
    data = NULL;
    data = new twointsclass;
    /* POTENTIAL FLAW: delete data in the source - the bad sink deletes data as well */
    delete data;
    /* use the function pointer */
    func_ptr(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B_sink(twointsclass * data)
{
    /* POTENTIAL FLAW: Possibly deleting memory twice */
    delete data;
}

static void goodG2B()
{
    twointsclass * data;
    void (*func_ptr) (twointsclass *) = goodG2B_sink;
    /* Initialize data */
    data = NULL;
    data = new twointsclass;
    /* FIX: Do NOT delete data in the source - the bad sink deletes data */
    func_ptr(data);
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G_sink(twointsclass * data)
{
    /* do nothing */
    /* FIX: Don't attempt to delete the memory */
    ; /* empty statement needed for some flow variants */
}

static void goodB2G()
{
    twointsclass * data;
    void (*func_ptr) (twointsclass *) = goodB2G_sink;
    /* Initialize data */
    data = NULL;
    data = new twointsclass;
    /* POTENTIAL FLAW: delete data in the source - the bad sink deletes data as well */
    delete data;
    func_ptr(data);
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

using namespace CWE415_Double_Free__new_delete_class_44; // so that we can use good and bad easily

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
