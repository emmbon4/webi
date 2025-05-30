/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__twointsclass_array_alloca_partial_init_16.cpp
Label Definition File: CWE457_Use_of_Uninitialized_Variable__twointsclass_array.label.xml
Template File: sources-sinks-16.tmpl.cpp
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: partial_init Initialize part, but not all of the array
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 16 Control flow: while(1) and while(0)
 * */

#include "std_testcase.h"

namespace CWE457_Use_of_Uninitialized_Variable__twointsclass_array_alloca_partial_init_16
{

#ifndef OMITBAD

void bad()
{
    twointsclass * data;
    data = (twointsclass *)ALLOCA(10*sizeof(twointsclass));
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        for(int i=0; i<10; i++)
        {
            data[i].a = i;
            data[i].b = i;
        }
        break;
    }
    while(1)
    {
        for(int i=0; i<(10/2); i++)
        {
            data[i].a = i;
            data[i].b = i;
        }
        break;
    }
    while(1)
    {
        for(int i=0; i<10; i++)
        {
            printIntLine(data[i].a);
            printIntLine(data[i].b);
        }
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        for(int i=0; i<10; i++)
        {
            data[i].a = i;
            data[i].b = i;
        }
        for(int i=0; i<10; i++)
        {
            printIntLine(data[i].a);
            printIntLine(data[i].b);
        }
        break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by changing the conditions on the third and fourth while statements */
static void goodB2G()
{
    twointsclass * data;
    data = (twointsclass *)ALLOCA(10*sizeof(twointsclass));
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        for(int i=0; i<10; i++)
        {
            data[i].a = i;
            data[i].b = i;
        }
        break;
    }
    while(1)
    {
        for(int i=0; i<(10/2); i++)
        {
            data[i].a = i;
            data[i].b = i;
        }
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        for(int i=0; i<10; i++)
        {
            printIntLine(data[i].a);
            printIntLine(data[i].b);
        }
        break;
    }
    while(1)
    {
        for(int i=0; i<10; i++)
        {
            data[i].a = i;
            data[i].b = i;
        }
        for(int i=0; i<10; i++)
        {
            printIntLine(data[i].a);
            printIntLine(data[i].b);
        }
        break;
    }
}

/* goodG2B() - use goodsource and badsink by changing the conditions on the first and second while statements */
static void goodG2B()
{
    twointsclass * data;
    data = (twointsclass *)ALLOCA(10*sizeof(twointsclass));
    while(1)
    {
        for(int i=0; i<10; i++)
        {
            data[i].a = i;
            data[i].b = i;
        }
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        for(int i=0; i<(10/2); i++)
        {
            data[i].a = i;
            data[i].b = i;
        }
        break;
    }
    while(1)
    {
        for(int i=0; i<10; i++)
        {
            printIntLine(data[i].a);
            printIntLine(data[i].b);
        }
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        for(int i=0; i<10; i++)
        {
            data[i].a = i;
            data[i].b = i;
        }
        for(int i=0; i<10; i++)
        {
            printIntLine(data[i].a);
            printIntLine(data[i].b);
        }
        break;
    }
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

using namespace CWE457_Use_of_Uninitialized_Variable__twointsclass_array_alloca_partial_init_16; // so that we can use good and bad easily

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
