/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__new_delete_wchar_t_12.cpp
Label Definition File: CWE416_Use_After_Free__new_delete.label.xml
Template File: sources-sinks-12.tmpl.cpp
*/
/*
 * @description
 * CWE: 416 Use After Free
 * BadSource:  Allocate data using new, initialize memory block, and Deallocate data using delete
 * GoodSource: Allocate data using new and initialize memory block
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Use data after free()
 * Flow Variant: 12 Control flow: if(global_returns_t_or_f())
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE416_Use_After_Free__new_delete_wchar_t_12
{

#ifndef OMITBAD

void bad()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    if(global_returns_t_or_f())
    {
        data = new wchar_t;
        *data = L'A';
        /* POTENTIAL FLAW: Delete data in the source - the bad sink attempts to use data */
        delete data;
    }
    else
    {
        data = new wchar_t;
        *data = L'A';
        /* FIX: Do not delete data in the source */
    }
    if(global_returns_t_or_f())
    {
        /* POTENTIAL FLAW - Use of data that may have been deleted */
        printWcharLine(*data);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    }
    else
    {
        /* FIX - Don't use data that may have been deleted already */
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by changing the first "if" so that
   both branches use the BadSource and the second "if" so that both branches
   use the GoodSink */
static void goodB2G()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    if(global_returns_t_or_f())
    {
        data = new wchar_t;
        *data = L'A';
        /* POTENTIAL FLAW: Delete data in the source - the bad sink attempts to use data */
        delete data;
    }
    else
    {
        data = new wchar_t;
        *data = L'A';
        /* POTENTIAL FLAW: Delete data in the source - the bad sink attempts to use data */
        delete data;
    }
    if(global_returns_t_or_f())
    {
        /* FIX - Don't use data that may have been deleted already */
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* FIX - Don't use data that may have been deleted already */
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodG2B() - use goodsource and badsink by changing the first "if" so that
   both branches use the GoodSource and the second "if" so that both branches
   use the BadSink */
static void goodG2B()
{
    wchar_t * data;
    /* Initialize data */
    data = NULL;
    if(global_returns_t_or_f())
    {
        data = new wchar_t;
        *data = L'A';
        /* FIX: Do not delete data in the source */
    }
    else
    {
        data = new wchar_t;
        *data = L'A';
        /* FIX: Do not delete data in the source */
    }
    if(global_returns_t_or_f())
    {
        /* POTENTIAL FLAW - Use of data that may have been deleted */
        printWcharLine(*data);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
    }
    else
    {
        /* POTENTIAL FLAW - Use of data that may have been deleted */
        printWcharLine(*data);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
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

using namespace CWE416_Use_After_Free__new_delete_wchar_t_12; // so that we can use good and bad easily

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
