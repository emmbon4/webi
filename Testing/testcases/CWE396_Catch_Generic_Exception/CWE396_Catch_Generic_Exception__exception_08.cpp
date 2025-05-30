/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE396_Catch_Generic_Exception__exception_08.cpp
Label Definition File: CWE396_Catch_Generic_Exception.label.xml
Template File: point-flaw-08.tmpl.cpp
*/
/*
 * @description
 * CWE: 396 Catch Generic Exception
 * Sinks: exception
 *    GoodSink: Catch specific exceptions
 *    BadSink : Catch exception reference, which will catch any exception
 * Flow Variant: 08 Control flow: if(static_returns_t()) and if(static_returns_f())
 *
 * */

#include "std_testcase.h"

#include <stdexcept> /* for out_of_range and domain_error */

using namespace std; /* allow easy references to out_of_range and domain_error */

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

namespace CWE396_Catch_Generic_Exception__exception_08
{

#ifndef OMITBAD

void bad()
{
    if(static_returns_t())
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

/* good1() uses if(static_returns_f()) instead of if(static_returns_t()) */
static void good1()
{
    if(static_returns_f())
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
    if(static_returns_t())
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

using namespace CWE396_Catch_Generic_Exception__exception_08; // so that we can use good and bad easily

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
