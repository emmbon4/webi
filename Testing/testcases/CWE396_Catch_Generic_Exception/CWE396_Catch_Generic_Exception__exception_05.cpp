/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE396_Catch_Generic_Exception__exception_05.cpp
Label Definition File: CWE396_Catch_Generic_Exception.label.xml
Template File: point-flaw-05.tmpl.cpp
*/
/*
 * @description
 * CWE: 396 Catch Generic Exception
 * Sinks: exception
 *    GoodSink: Catch specific exceptions
 *    BadSink : Catch exception reference, which will catch any exception
 * Flow Variant: 05 Control flow: if(static_t) and if(static_f)
 *
 * */

#include "std_testcase.h"

#include <stdexcept> /* for out_of_range and domain_error */

using namespace std; /* allow easy references to out_of_range and domain_error */

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int static_t = 1; /* true */
static int static_f = 0; /* false */

namespace CWE396_Catch_Generic_Exception__exception_05
{

#ifndef OMITBAD

void bad()
{
    if(static_t)
    {
        try
        {
            if (rand()%2 == 0) throw out_of_range("err1");
            if (rand()%2 == 0) throw domain_error("err2");
        }
        catch (exception &)
        {
            /* FLAW: this catches err1 and err2 */
            printLine("exception");
        }
        printLine("ok");
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        try
        {
            if (rand()%2 == 0) throw out_of_range("err1");
            if (rand()%2 == 0) throw domain_error("err2");
        }
        catch (out_of_range &)
        {
            /* FIX: specify each catch individually */
            printLine("out_of_range");
        }
        catch (domain_error &)
        {
            printLine("domain_error");
            return;
        }
        printLine("ok");
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(static_f) instead of if(static_t) */
static void good1()
{
    if(static_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        try
        {
            if (rand()%2 == 0) throw out_of_range("err1");
            if (rand()%2 == 0) throw domain_error("err2");
        }
        catch (exception &)
        {
            /* FLAW: this catches err1 and err2 */
            printLine("exception");
        }
        printLine("ok");
    }
    else
    {
        try
        {
            if (rand()%2 == 0) throw out_of_range("err1");
            if (rand()%2 == 0) throw domain_error("err2");
        }
        catch (out_of_range &)
        {
            /* FIX: specify each catch individually */
            printLine("out_of_range");
        }
        catch (domain_error &)
        {
            printLine("domain_error");
            return;
        }
        printLine("ok");
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_t)
    {
        try
        {
            if (rand()%2 == 0) throw out_of_range("err1");
            if (rand()%2 == 0) throw domain_error("err2");
        }
        catch (out_of_range &)
        {
            /* FIX: specify each catch individually */
            printLine("out_of_range");
        }
        catch (domain_error &)
        {
            printLine("domain_error");
            return;
        }
        printLine("ok");
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        try
        {
            if (rand()%2 == 0) throw out_of_range("err1");
            if (rand()%2 == 0) throw domain_error("err2");
        }
        catch (exception &)
        {
            /* FLAW: this catches err1 and err2 */
            printLine("exception");
        }
        printLine("ok");
    }
}

void good()
{
    good1();
    good2();
}

#endif /* OMITGOOD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE396_Catch_Generic_Exception__exception_05; // so that we can use good and bad easily

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
