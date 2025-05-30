/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__class_05.cpp
Label Definition File: CWE476_NULL_Pointer_Dereference__class.label.xml
Template File: sources-sink-05.tmpl.cpp
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sink:
 *    BadSink : Print data
 * Flow Variant: 05 Control flow: if(static_t) and if(static_f)
 *
 * */

#include "std_testcase.h"

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int static_t = 1; /* true */
static int static_f = 0; /* false */

namespace CWE476_NULL_Pointer_Dereference__class_05
{

#ifndef OMITBAD

void bad()
{
    twointsclass * data;
    /* Initialize data */
    data = NULL;
    if(static_t)
    {
        /* FLAW: Set data to NULL - it will be used in the sink */
        data = NULL;
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            twointsclass * tmp = new twointsclass;
            tmp->a = 0;
            tmp->b = 0;
            /* FIX: Initialize data - it will be used in the sink */
            data = tmp;
        }
    }
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printIntLine(data[0].a);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the static_t to static_f */
static void goodG2B1()
{
    twointsclass * data;
    /* Initialize data */
    data = NULL;
    if(static_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Set data to NULL - it will be used in the sink */
        data = NULL;
    }
    else
    {
        {
            twointsclass * tmp = new twointsclass;
            tmp->a = 0;
            tmp->b = 0;
            /* FIX: Initialize data - it will be used in the sink */
            data = tmp;
        }
    }
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printIntLine(data[0].a);
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    twointsclass * data;
    /* Initialize data */
    data = NULL;
    if(static_t)
    {
        {
            twointsclass * tmp = new twointsclass;
            tmp->a = 0;
            tmp->b = 0;
            /* FIX: Initialize data - it will be used in the sink */
            data = tmp;
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: Set data to NULL - it will be used in the sink */
        data = NULL;
    }
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printIntLine(data[0].a);
}

void good()
{
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

using namespace CWE476_NULL_Pointer_Dereference__class_05; // so that we can use good and bad easily

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
