/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__new_twoints_array_no_init_01.cpp
Label Definition File: CWE457_Use_of_Uninitialized_Variable__new.label.xml
Template File: sources-sinks-01.tmpl.cpp
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

namespace CWE457_Use_of_Uninitialized_Variable__new_twoints_array_no_init_01
{

#ifndef OMITBAD

void bad()
{
    twoints * data;
    data = new twoints[10];
    /* Don't initialize data */
    ; /* empty statement needed for some flow variants */
    {
        int i;
        for(i=0; i<10; i++)
        {
            printIntLine(data[i].a);
            printIntLine(data[i].b);
        }
    }
    /* deallocate the memory */
    delete [] data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    twoints * data;
    data = new twoints[10];
    {
        int i;
        for(i=0; i<10; i++)
        {
            data[i].a = i;
            data[i].b = i;
        }
    }
    {
        int i;
        for(i=0; i<10; i++)
        {
            printIntLine(data[i].a);
            printIntLine(data[i].b);
        }
    }
    /* deallocate the memory */
    delete [] data;
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    twoints * data;
    data = new twoints[10];
    /* Don't initialize data */
    ; /* empty statement needed for some flow variants */
    {
        int i;
        for(i=0; i<10; i++)
        {
            data[i].a = i;
            data[i].b = i;
        }
    }
    {
        int i;
        for(i=0; i<10; i++)
        {
            printIntLine(data[i].a);
            printIntLine(data[i].b);
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

using namespace CWE457_Use_of_Uninitialized_Variable__new_twoints_array_no_init_01; // so that we can use good and bad easily

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
