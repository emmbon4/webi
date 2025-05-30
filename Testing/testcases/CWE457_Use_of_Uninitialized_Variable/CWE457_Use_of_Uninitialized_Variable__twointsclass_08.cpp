/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__twointsclass_08.cpp
Label Definition File: CWE457_Use_of_Uninitialized_Variable__twointsclass.label.xml
Template File: sources-sinks-08.tmpl.cpp
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 08 Control flow: if(static_returns_t()) and if(static_returns_f())
 *
 * */

#include "std_testcase.h"

/* The two function below always return the same value, so a tool
   should be able to identify that calls to the functions will always
   return a fixed value. */
static int static_returns_t()
{
    return 1;
}

static int static_returns_f()
{
    return 0;
}

namespace CWE457_Use_of_Uninitialized_Variable__twointsclass_08
{

#ifndef OMITBAD

void bad()
{
    twointsclass data;
    if(static_returns_t())
    {
        /* Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data.a = 1;
        data.b = 2;
    }
    if(static_returns_t())
    {
        printIntLine(data.a);
        printIntLine(data.b);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data.a = 1;
        data.b = 2;
        printIntLine(data.a);
        printIntLine(data.b);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second static_returns_t() to static_returns_f() */
static void goodB2G1()
{
    twointsclass data;
    if(static_returns_t())
    {
        /* Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data.a = 1;
        data.b = 2;
    }
    if(static_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printIntLine(data.a);
        printIntLine(data.b);
    }
    else
    {
        data.a = 1;
        data.b = 2;
        printIntLine(data.a);
        printIntLine(data.b);
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    twointsclass data;
    if(static_returns_t())
    {
        /* Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data.a = 1;
        data.b = 2;
    }
    if(static_returns_t())
    {
        data.a = 1;
        data.b = 2;
        printIntLine(data.a);
        printIntLine(data.b);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printIntLine(data.a);
        printIntLine(data.b);
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first static_returns_t() to static_returns_f() */
static void goodG2B1()
{
    twointsclass data;
    if(static_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        data.a = 1;
        data.b = 2;
    }
    if(static_returns_t())
    {
        printIntLine(data.a);
        printIntLine(data.b);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data.a = 1;
        data.b = 2;
        printIntLine(data.a);
        printIntLine(data.b);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    twointsclass data;
    if(static_returns_t())
    {
        data.a = 1;
        data.b = 2;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }
    if(static_returns_t())
    {
        printIntLine(data.a);
        printIntLine(data.b);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data.a = 1;
        data.b = 2;
        printIntLine(data.a);
        printIntLine(data.b);
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

using namespace CWE457_Use_of_Uninitialized_Variable__twointsclass_08; // so that we can use good and bad easily

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
