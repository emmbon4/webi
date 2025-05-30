/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_array_twointsclass_16.cpp
Label Definition File: CWE401_Memory_Leak__new_array.label.xml
Template File: sources-sinks-16.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new[]
 * GoodSource: Point data to a stack buffer
 * Sinks:
 *    GoodSink: call delete[] on data
 *    BadSink : no deallocation of data
 * Flow Variant: 16 Control flow: while(1) and while(0)
 * */

#include "std_testcase.h"

namespace CWE401_Memory_Leak__new_array_twointsclass_16
{

#ifndef OMITBAD

void bad()
{
    twointsclass * data;
    data = NULL;
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: Use memory allocated on the stack */
            twointsclass data_goodbuf[100];
            data = data_goodbuf;
            /* Initialize and make use of data */
            data[0].a = 0;
            data[0].b = 0;
            printIntLine(data[0].a);
            printIntLine(data[0].b);
        }
        break;
    }
    while(1)
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = new twointsclass[100];
        /* Initialize and make use of data */
        data[0].a = 0;
        data[0].b = 0;
        printIntLine(data[0].a);
        printIntLine(data[0].b);
        break;
    }
    while(1)
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Deallocate memory */
        delete[] data;
        break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by changing the conditions on the third and fourth while statements */
static void goodB2G()
{
    twointsclass * data;
    data = NULL;
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            /* FIX: Use memory allocated on the stack */
            twointsclass data_goodbuf[100];
            data = data_goodbuf;
            /* Initialize and make use of data */
            data[0].a = 0;
            data[0].b = 0;
            printIntLine(data[0].a);
            printIntLine(data[0].b);
        }
        break;
    }
    while(1)
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = new twointsclass[100];
        /* Initialize and make use of data */
        data[0].a = 0;
        data[0].b = 0;
        printIntLine(data[0].a);
        printIntLine(data[0].b);
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
        break;
    }
    while(1)
    {
        /* FIX: Deallocate memory */
        delete[] data;
        break;
    }
}

/* goodG2B() - use goodsource and badsink by changing the conditions on the first and second while statements */
static void goodG2B()
{
    twointsclass * data;
    data = NULL;
    while(1)
    {
        {
            /* FIX: Use memory allocated on the stack */
            twointsclass data_goodbuf[100];
            data = data_goodbuf;
            /* Initialize and make use of data */
            data[0].a = 0;
            data[0].b = 0;
            printIntLine(data[0].a);
            printIntLine(data[0].b);
        }
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = new twointsclass[100];
        /* Initialize and make use of data */
        data[0].a = 0;
        data[0].b = 0;
        printIntLine(data[0].a);
        printIntLine(data[0].b);
        break;
    }
    while(1)
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Deallocate memory */
        delete[] data;
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

using namespace CWE401_Memory_Leak__new_array_twointsclass_16; // so that we can use good and bad easily

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
