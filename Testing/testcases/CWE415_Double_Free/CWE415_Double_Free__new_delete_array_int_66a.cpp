/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_array_int_66a.cpp
Label Definition File: CWE415_Double_Free__new_delete_array.label.xml
Template File: sources-sinks-66a.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_array_int_66
{

#ifndef OMITBAD

/* bad function declaration */
void bad_sink(int * data_array[]);

void bad()
{
    int * data;
    int * data_array[5];
    /* Initialize data */
    data = NULL;
    data = new int[100];
    /* POTENTIAL FLAW: delete the array data in the source - the bad sink deletes the array data as well */
    delete [] data;
    /* put data in array */
    data_array[2] = data;
    bad_sink(data_array);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink(int * data_array[]);

static void goodG2B()
{
    int * data;
    int * data_array[5];
    /* Initialize data */
    data = NULL;
    data = new int[100];
    /* FIX: Do NOT delete the array data in the source - the bad sink deletes the array data */
    data_array[2] = data;
    goodG2B_sink(data_array);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2G_sink(int * data_array[]);

static void goodB2G()
{
    int * data;
    int * data_array[5];
    /* Initialize data */
    data = NULL;
    data = new int[100];
    /* POTENTIAL FLAW: delete the array data in the source - the bad sink deletes the array data as well */
    delete [] data;
    data_array[2] = data;
    goodB2G_sink(data_array);
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

using namespace CWE415_Double_Free__new_delete_array_int_66; // so that we can use good and bad easily

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
