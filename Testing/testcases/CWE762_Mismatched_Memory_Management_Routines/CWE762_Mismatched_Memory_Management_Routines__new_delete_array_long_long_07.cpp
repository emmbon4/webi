/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_delete_array_long_long_07.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_delete_array.label.xml
Template File: sources-sinks-07.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data using new []
 * Sinks:
 *    GoodSink: Deallocate data using delete
 *    BadSink : Deallocate data using delete []
 * Flow Variant: 07 Control flow: if(static_five==5) and if(static_five!=5)
 *
 * */

#include "std_testcase.h"

/* The variable below is not declared "const", but is never assigned
   any other value so a tool should be able to identify that reads of
   this will always give its initialized value. */
static int static_five = 5;

namespace CWE762_Mismatched_Memory_Management_Routines__new_delete_array_long_long_07
{

#ifndef OMITBAD

void bad()
{
    long long * data;
    /* Initialize data*/
    data = NULL;
    if(static_five==5)
    {
        /* POTENTIAL FLAW: Allocate memory with a function that requires delete to free the memory */
        data = new long long;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Allocate memory from the heap using new [] */
        data = new long long[100];
    }
    if(static_five==5)
    {
        /* POTENTIAL FLAW: Deallocate memory using delete [] - the source memory allocation function may
         * require a call to delete to deallocate the memory */
        delete [] data;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Deallocate the memory using delete */
        delete data;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second static_five==5 to static_five!=5 */
static void goodB2G1()
{
    long long * data;
    /* Initialize data*/
    data = NULL;
    if(static_five==5)
    {
        /* POTENTIAL FLAW: Allocate memory with a function that requires delete to free the memory */
        data = new long long;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Allocate memory from the heap using new [] */
        data = new long long[100];
    }
    if(static_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Deallocate memory using delete [] - the source memory allocation function may
         * require a call to delete to deallocate the memory */
        delete [] data;
    }
    else
    {
        /* FIX: Deallocate the memory using delete */
        delete data;
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    long long * data;
    /* Initialize data*/
    data = NULL;
    if(static_five==5)
    {
        /* POTENTIAL FLAW: Allocate memory with a function that requires delete to free the memory */
        data = new long long;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Allocate memory from the heap using new [] */
        data = new long long[100];
    }
    if(static_five==5)
    {
        /* FIX: Deallocate the memory using delete */
        delete data;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Deallocate memory using delete [] - the source memory allocation function may
         * require a call to delete to deallocate the memory */
        delete [] data;
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first static_five==5 to static_five!=5 */
static void goodG2B1()
{
    long long * data;
    /* Initialize data*/
    data = NULL;
    if(static_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Allocate memory with a function that requires delete to free the memory */
        data = new long long;
    }
    else
    {
        /* FIX: Allocate memory from the heap using new [] */
        data = new long long[100];
    }
    if(static_five==5)
    {
        /* POTENTIAL FLAW: Deallocate memory using delete [] - the source memory allocation function may
         * require a call to delete to deallocate the memory */
        delete [] data;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Deallocate the memory using delete */
        delete data;
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    long long * data;
    /* Initialize data*/
    data = NULL;
    if(static_five==5)
    {
        /* FIX: Allocate memory from the heap using new [] */
        data = new long long[100];
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Allocate memory with a function that requires delete to free the memory */
        data = new long long;
    }
    if(static_five==5)
    {
        /* POTENTIAL FLAW: Deallocate memory using delete [] - the source memory allocation function may
         * require a call to delete to deallocate the memory */
        delete [] data;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Deallocate the memory using delete */
        delete data;
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

using namespace CWE762_Mismatched_Memory_Management_Routines__new_delete_array_long_long_07; // so that we can use good and bad easily

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
