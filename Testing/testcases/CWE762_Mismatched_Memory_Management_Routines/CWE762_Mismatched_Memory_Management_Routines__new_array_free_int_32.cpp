/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_array_free_int_32.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_array_free.label.xml
Template File: sources-sinks-32.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using new []
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: Deallocate data using delete []
 *    BadSink : Deallocate data using free()
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_array_free_int_32
{

#ifndef OMITBAD

void bad()
{
    int * data;
    int * *data_ptr1 = &data;
    int * *data_ptr2 = &data;
    /* Initialize data*/
    data = NULL;
    {
        int * data = *data_ptr1;
        /* POTENTIAL FLAW: Allocate memory with a function that requires delete [] to free the memory */
        data = new int[100];
        *data_ptr1 = data;
    }
    {
        int * data = *data_ptr2;
        /* POTENTIAL FLAW: Deallocate memory using free() - the source memory allocation function may
         * require a call to delete [] to deallocate the memory */
        free(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    int * data;
    int * *data_ptr1 = &data;
    int * *data_ptr2 = &data;
    /* Initialize data*/
    data = NULL;
    {
        int * data = *data_ptr1;
        /* FIX: Allocate memory from the heap using malloc() */
        data = (int *)malloc(100*sizeof(int));
        *data_ptr1 = data;
    }
    {
        int * data = *data_ptr2;
        /* POTENTIAL FLAW: Deallocate memory using free() - the source memory allocation function may
         * require a call to delete [] to deallocate the memory */
        free(data);
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    int * data;
    int * *data_ptr1 = &data;
    int * *data_ptr2 = &data;
    /* Initialize data*/
    data = NULL;
    {
        int * data = *data_ptr1;
        /* POTENTIAL FLAW: Allocate memory with a function that requires delete [] to free the memory */
        data = new int[100];
        *data_ptr1 = data;
    }
    {
        int * data = *data_ptr2;
        /* FIX: Deallocate the memory using delete [] */
        delete [] data;
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

using namespace CWE762_Mismatched_Memory_Management_Routines__new_array_free_int_32; // so that we can use good and bad easily

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
