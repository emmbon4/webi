/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_char_12.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-12.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 12 Control flow: if(global_returns_t_or_f())
 * */

#include "std_testcase.h"

namespace CWE401_Memory_Leak__new_char_12
{

#ifndef OMITBAD

void bad()
{
    char * data;
    data = NULL;
    if(global_returns_t_or_f())
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = new char;
        /* Initialize and make use of data */
        *data = 'A';
        printHexCharLine(*data);
    }
    else
    {
        /* FIX: Use memory allocated on the stack */
        char data_good;
        data = &data_good;
        /* Initialize and make use of data */
        *data = 'A';
        printHexCharLine(*data);
    }
    if(global_returns_t_or_f())
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* FIX: Deallocate memory */
        delete data;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by changing the first "if" so that
   both branches use the BadSource and the second "if" so that both branches
   use the GoodSink */
static void goodB2G()
{
    char * data;
    data = NULL;
    if(global_returns_t_or_f())
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = new char;
        /* Initialize and make use of data */
        *data = 'A';
        printHexCharLine(*data);
    }
    else
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = new char;
        /* Initialize and make use of data */
        *data = 'A';
        printHexCharLine(*data);
    }
    if(global_returns_t_or_f())
    {
        /* FIX: Deallocate memory */
        delete data;
    }
    else
    {
        /* FIX: Deallocate memory */
        delete data;
    }
}

/* goodG2B() - use goodsource and badsink by changing the first "if" so that
   both branches use the GoodSource and the second "if" so that both branches
   use the BadSink */
static void goodG2B()
{
    char * data;
    data = NULL;
    if(global_returns_t_or_f())
    {
        /* FIX: Use memory allocated on the stack */
        char data_good;
        data = &data_good;
        /* Initialize and make use of data */
        *data = 'A';
        printHexCharLine(*data);
    }
    else
    {
        /* FIX: Use memory allocated on the stack */
        char data_good;
        data = &data_good;
        /* Initialize and make use of data */
        *data = 'A';
        printHexCharLine(*data);
    }
    if(global_returns_t_or_f())
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
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

using namespace CWE401_Memory_Leak__new_char_12; // so that we can use good and bad easily

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
