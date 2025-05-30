/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__new_int_array_partial_init_43.cpp
Label Definition File: CWE457_Use_of_Uninitialized_Variable__new.label.xml
Template File: sources-sinks-43.tmpl.cpp
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: partial_init Initialize part, but not all of the array
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 43 Data flow: data flows using a C++ reference from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

namespace CWE457_Use_of_Uninitialized_Variable__new_int_array_partial_init_43
{

#ifndef OMITBAD

void bad_source(int * &data)
{
    {
        int i;
        for(i=0; i<(10/2); i++)
        {
            data[i] = i;
        }
    }
}

void bad()
{
    int * data;
    data = new int[10];
    bad_source(data);
    {
        int i;
        for(i=0; i<10; i++)
        {
            printIntLine(data[i]);
        }
    }
    /* deallocate the memory */
    delete [] data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B_source(int * &data)
{
    {
        int i;
        for(i=0; i<10; i++)
        {
            data[i] = i;
        }
    }
}

static void goodG2B()
{
    int * data;
    data = new int[10];
    goodG2B_source(data);
    {
        int i;
        for(i=0; i<10; i++)
        {
            printIntLine(data[i]);
        }
    }
    /* deallocate the memory */
    delete [] data;
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G_source(int * &data)
{
    {
        int i;
        for(i=0; i<(10/2); i++)
        {
            data[i] = i;
        }
    }
}

static void goodB2G()
{
    int * data;
    data = new int[10];
    goodB2G_source(data);
    {
        int i;
        for(i=0; i<10; i++)
        {
            data[i] = i;
        }
    }
    {
        int i;
        for(i=0; i<10; i++)
        {
            printIntLine(data[i]);
        }
    }
    /* deallocate the memory */
    delete [] data;
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

using namespace CWE457_Use_of_Uninitialized_Variable__new_int_array_partial_init_43; // so that we can use good and bad easily

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
