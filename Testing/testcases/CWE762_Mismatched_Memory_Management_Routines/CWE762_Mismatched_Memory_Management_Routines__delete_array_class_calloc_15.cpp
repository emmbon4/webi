/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_array_class_calloc_15.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete_array.label.xml
Template File: sources-sinks-15.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource: calloc Allocate data using calloc()
 * GoodSource: Allocate data using new []
 * Sinks:
 *    GoodSink: Deallocate data using free()
 *    BadSink : Deallocate data using delete []
 * Flow Variant: 15 Control flow: switch(6) and switch(7)
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_array_class_calloc_15
{

#ifndef OMITBAD

void bad()
{
    twointsclass * data;
    /* Initialize data*/
    data = NULL;
    switch(6)
    {
    case 6:
        /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
        data = (twointsclass *)calloc(100, sizeof(twointsclass));
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Allocate memory using new [] */
        data = new twointsclass[100];
        break;
    }
    switch(7)
    {
    case 7:
        /* POTENTIAL FLAW: Deallocate memory using delete [] - the source memory allocation function may
         * require a call to free() to deallocate the memory */
        delete [] data;
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Free memory using free() */
        free(data);
        break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second switch to switch(8) */
static void goodB2G1()
{
    twointsclass * data;
    /* Initialize data*/
    data = NULL;
    switch(6)
    {
    case 6:
        /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
        data = (twointsclass *)calloc(100, sizeof(twointsclass));
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Allocate memory using new [] */
        data = new twointsclass[100];
        break;
    }
    switch(8)
    {
    case 7:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Deallocate memory using delete [] - the source memory allocation function may
         * require a call to free() to deallocate the memory */
        delete [] data;
        break;
    default:
        /* FIX: Free memory using free() */
        free(data);
        break;
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second switch */
static void goodB2G2()
{
    twointsclass * data;
    /* Initialize data*/
    data = NULL;
    switch(6)
    {
    case 6:
        /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
        data = (twointsclass *)calloc(100, sizeof(twointsclass));
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Allocate memory using new [] */
        data = new twointsclass[100];
        break;
    }
    switch(7)
    {
    case 7:
        /* FIX: Free memory using free() */
        free(data);
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Deallocate memory using delete [] - the source memory allocation function may
         * require a call to free() to deallocate the memory */
        delete [] data;
        break;
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first switch to switch(5) */
static void goodG2B1()
{
    twointsclass * data;
    /* Initialize data*/
    data = NULL;
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
        data = (twointsclass *)calloc(100, sizeof(twointsclass));
        break;
    default:
        /* FIX: Allocate memory using new [] */
        data = new twointsclass[100];
        break;
    }
    switch(7)
    {
    case 7:
        /* POTENTIAL FLAW: Deallocate memory using delete [] - the source memory allocation function may
         * require a call to free() to deallocate the memory */
        delete [] data;
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Free memory using free() */
        free(data);
        break;
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first switch */
static void goodG2B2()
{
    twointsclass * data;
    /* Initialize data*/
    data = NULL;
    switch(6)
    {
    case 6:
        /* FIX: Allocate memory using new [] */
        data = new twointsclass[100];
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
        data = (twointsclass *)calloc(100, sizeof(twointsclass));
        break;
    }
    switch(7)
    {
    case 7:
        /* POTENTIAL FLAW: Deallocate memory using delete [] - the source memory allocation function may
         * require a call to free() to deallocate the memory */
        delete [] data;
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Free memory using free() */
        free(data);
        break;
    }
}

void good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}

#endif /* OMITGOOD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE762_Mismatched_Memory_Management_Routines__delete_array_class_calloc_15; // so that we can use good and bad easily

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
