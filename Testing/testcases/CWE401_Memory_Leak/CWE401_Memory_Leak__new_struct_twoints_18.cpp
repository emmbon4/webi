/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_struct_twoints_18.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-18.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 18 Control flow: goto statements
 * */

#include "std_testcase.h"

namespace CWE401_Memory_Leak__new_struct_twoints_18
{

#ifndef OMITBAD

void bad()
{
    struct _twoints * data;
    data = NULL;
    goto source;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* FIX: Use memory allocated on the stack */
    struct _twoints data_good;
    data = &data_good;
    /* Initialize and make use of data */
    data->a = 0;
    data->b = 0;
    printStructLine((twoints *)data);
source:
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new struct _twoints;
    /* Initialize and make use of data */
    data->a = 0;
    data->b = 0;
    printStructLine((twoints *)data);
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* FIX: Deallocate memory */
    delete data;
sink:
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by reversing the blocks on the second goto statement */
static void goodB2G()
{
    struct _twoints * data;
    data = NULL;
    goto source;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* FIX: Use memory allocated on the stack */
    struct _twoints data_good;
    data = &data_good;
    /* Initialize and make use of data */
    data->a = 0;
    data->b = 0;
    printStructLine((twoints *)data);
source:
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new struct _twoints;
    /* Initialize and make use of data */
    data->a = 0;
    data->b = 0;
    printStructLine((twoints *)data);
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* POTENTIAL FLAW: No deallocation */
    ; /* empty statement needed for some flow variants */
sink:
    /* FIX: Deallocate memory */
    delete data;
}

/* goodG2B() - use goodsource and badsink by reversing the blocks on the first goto statement */
static void goodG2B()
{
    struct _twoints * data;
    data = NULL;
    goto source;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new struct _twoints;
    /* Initialize and make use of data */
    data->a = 0;
    data->b = 0;
    printStructLine((twoints *)data);
source:
    /* FIX: Use memory allocated on the stack */
    struct _twoints data_good;
    data = &data_good;
    /* Initialize and make use of data */
    data->a = 0;
    data->b = 0;
    printStructLine((twoints *)data);
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* FIX: Deallocate memory */
    delete data;
sink:
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

using namespace CWE401_Memory_Leak__new_struct_twoints_18; // so that we can use good and bad easily

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
