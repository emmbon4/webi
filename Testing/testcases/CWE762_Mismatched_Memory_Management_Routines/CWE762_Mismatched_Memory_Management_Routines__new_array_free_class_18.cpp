/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_array_free_class_18.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_array_free.label.xml
Template File: sources-sinks-18.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using new []
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: Deallocate data using delete []
 *    BadSink : Deallocate data using free()
 * Flow Variant: 18 Control flow: goto statements
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_array_free_class_18
{

#ifndef OMITBAD

void bad()
{
    twointsclass * data;
    /* Initialize data*/
    data = NULL;
    goto source;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* FIX: Allocate memory from the heap using malloc() */
    data = (twointsclass *)malloc(100*sizeof(twointsclass));
source:
    /* POTENTIAL FLAW: Allocate memory with a function that requires delete [] to free the memory */
    data = new twointsclass[100];
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* FIX: Deallocate the memory using delete [] */
    delete [] data;
sink:
    /* POTENTIAL FLAW: Deallocate memory using free() - the source memory allocation function may
     * require a call to delete [] to deallocate the memory */
    free(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by reversing the blocks on the second goto statement */
static void goodB2G()
{
    twointsclass * data;
    /* Initialize data*/
    data = NULL;
    goto source;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* FIX: Allocate memory from the heap using malloc() */
    data = (twointsclass *)malloc(100*sizeof(twointsclass));
source:
    /* POTENTIAL FLAW: Allocate memory with a function that requires delete [] to free the memory */
    data = new twointsclass[100];
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* POTENTIAL FLAW: Deallocate memory using free() - the source memory allocation function may
     * require a call to delete [] to deallocate the memory */
    free(data);
sink:
    /* FIX: Deallocate the memory using delete [] */
    delete [] data;
}

/* goodG2B() - use goodsource and badsink by reversing the blocks on the first goto statement */
static void goodG2B()
{
    twointsclass * data;
    /* Initialize data*/
    data = NULL;
    goto source;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* POTENTIAL FLAW: Allocate memory with a function that requires delete [] to free the memory */
    data = new twointsclass[100];
source:
    /* FIX: Allocate memory from the heap using malloc() */
    data = (twointsclass *)malloc(100*sizeof(twointsclass));
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* FIX: Deallocate the memory using delete [] */
    delete [] data;
sink:
    /* POTENTIAL FLAW: Deallocate memory using free() - the source memory allocation function may
     * require a call to delete [] to deallocate the memory */
    free(data);
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

using namespace CWE762_Mismatched_Memory_Management_Routines__new_array_free_class_18; // so that we can use good and bad easily

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
