/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE758_Undefined_Behavior__long_long_new_use_19.cpp
Label Definition File: CWE758_Undefined_Behavior.new.label.xml
Template File: point-flaw-19.tmpl.cpp
*/
/*
 * @description
 * CWE: 758 Undefined Behavior
 * Sinks: new_use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 19 Control flow: Dead code after a return
 *
 * */

#include "std_testcase.h"

namespace CWE758_Undefined_Behavior__long_long_new_use_19
{

#ifndef OMITBAD

void bad()
{
    {
        long long * pointer = new long long;
        long long data = *pointer; /* FLAW: the value pointed to by pointer is undefined */
        delete pointer;
        printLongLongLine(data);
    }
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        long long data;
        data = 5L;
        long long * pointer = new long long;
        *pointer = data; /* FIX: Assign a value to the thing pointed to by pointer */
        {
            long long data = *pointer;
            printLongLongLine(data);
        }
        delete pointer;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() reverses the GoodSinkBody and the BadSinkBody so that the BadSinkBody never runs */
static void good1()
{
    {
        long long data;
        data = 5L;
        long long * pointer = new long long;
        *pointer = data; /* FIX: Assign a value to the thing pointed to by pointer */
        {
            long long data = *pointer;
            printLongLongLine(data);
        }
        delete pointer;
    }
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        long long * pointer = new long long;
        long long data = *pointer; /* FLAW: the value pointed to by pointer is undefined */
        delete pointer;
        printLongLongLine(data);
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

using namespace CWE758_Undefined_Behavior__long_long_new_use_19; // so that we can use good and bad easily

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
