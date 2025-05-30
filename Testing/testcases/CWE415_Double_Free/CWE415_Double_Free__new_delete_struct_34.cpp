/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_struct_34.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-34.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_struct_34
{

typedef union
{
    twoints * a;
    twoints * b;
} union_type;

#ifndef OMITBAD

void bad()
{
    twoints * data;
    union_type my_union;
    /* Initialize data */
    data = NULL;
    data = new twoints;
    /* POTENTIAL FLAW: delete data in the source - the bad sink deletes data as well */
    delete data;
    my_union.a = data;
    {
        twoints * data = my_union.b;
        /* POTENTIAL FLAW: Possibly deleting memory twice */
        delete data;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    twoints * data;
    union_type my_union;
    /* Initialize data */
    data = NULL;
    data = new twoints;
    /* FIX: Do NOT delete data in the source - the bad sink deletes data */
    my_union.a = data;
    {
        twoints * data = my_union.b;
        /* POTENTIAL FLAW: Possibly deleting memory twice */
        delete data;
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    twoints * data;
    union_type my_union;
    /* Initialize data */
    data = NULL;
    data = new twoints;
    /* POTENTIAL FLAW: delete data in the source - the bad sink deletes data as well */
    delete data;
    my_union.a = data;
    {
        twoints * data = my_union.b;
        /* do nothing */
        /* FIX: Don't attempt to delete the memory */
        ; /* empty statement needed for some flow variants */
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

using namespace CWE415_Double_Free__new_delete_struct_34; // so that we can use good and bad easily

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
