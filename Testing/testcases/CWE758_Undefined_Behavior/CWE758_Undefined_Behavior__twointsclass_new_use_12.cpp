/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE758_Undefined_Behavior__twointsclass_new_use_12.cpp
Label Definition File: CWE758_Undefined_Behavior.new.label.xml
Template File: point-flaw-12.tmpl.cpp
*/
/*
 * @description
 * CWE: 758 Undefined Behavior
 * Sinks: new_use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 12 Control flow: if(global_returns_t_or_f())
 *
 * */

#include "std_testcase.h"

namespace CWE758_Undefined_Behavior__twointsclass_new_use_12
{

#ifndef OMITBAD

void bad()
{
    if(global_returns_t_or_f())
    {
        {
            twointsclass * pointer = new twointsclass;
            twointsclass data = *pointer; /* FLAW: the value pointed to by pointer is undefined */
            delete pointer;
            printIntLine(data.a);
            printIntLine(data.b);
        }
    }
    else
    {
        {
            twointsclass data;
            data.a = 1;
            data.b = 2;
            twointsclass * pointer = new twointsclass;
            *pointer = data; /* FIX: Assign a value to the thing pointed to by pointer */
            {
                twointsclass data = *pointer;
                printIntLine(data.a);
                printIntLine(data.b);
            }
            delete pointer;
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses the GoodSink on both sides of the "if" statement */
static void good1()
{
    if(global_returns_t_or_f())
    {
        {
            twointsclass data;
            data.a = 1;
            data.b = 2;
            twointsclass * pointer = new twointsclass;
            *pointer = data; /* FIX: Assign a value to the thing pointed to by pointer */
            {
                twointsclass data = *pointer;
                printIntLine(data.a);
                printIntLine(data.b);
            }
            delete pointer;
        }
    }
    else
    {
        {
            twointsclass data;
            data.a = 1;
            data.b = 2;
            twointsclass * pointer = new twointsclass;
            *pointer = data; /* FIX: Assign a value to the thing pointed to by pointer */
            {
                twointsclass data = *pointer;
                printIntLine(data.a);
                printIntLine(data.b);
            }
            delete pointer;
        }
    }
}

void good()
{
    good1();
}

#endif /* OMITGOOD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE758_Undefined_Behavior__twointsclass_new_use_12; // so that we can use good and bad easily

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
