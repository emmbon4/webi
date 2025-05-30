/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__new_delete_class_16.cpp
Label Definition File: CWE416_Use_After_Free__new_delete.label.xml
Template File: sources-sinks-16.tmpl.cpp
*/
/*
 * @description
 * CWE: 416 Use After Free
 * BadSource:  Allocate data using new, initialize memory block, and Deallocate data using delete
 * GoodSource: Allocate data using new and initialize memory block
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Use data after free()
 * Flow Variant: 16 Control flow: while(1) and while(0)
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE416_Use_After_Free__new_delete_class_16
{

#ifndef OMITBAD

void bad()
{
    twointsclass * data;
    /* Initialize data */
    data = NULL;
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data = new twointsclass;
        data->a = 1;
        data->b = 2;
        /* FIX: Do not delete data in the source */
        break;
    }
    while(1)
    {
        data = new twointsclass;
        data->a = 1;
        data->b = 2;
        /* POTENTIAL FLAW: Delete data in the source - the bad sink attempts to use data */
        delete data;
        break;
    }
    while(1)
    {
        /* POTENTIAL FLAW - Use of data that may have been deleted */
        printIntLine(data->a);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX - Don't use data that may have been deleted already */
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
        break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by changing the conditions on the third and fourth while statements */
static void goodB2G()
{
    twointsclass * data;
    /* Initialize data */
    data = NULL;
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data = new twointsclass;
        data->a = 1;
        data->b = 2;
        /* FIX: Do not delete data in the source */
        break;
    }
    while(1)
    {
        data = new twointsclass;
        data->a = 1;
        data->b = 2;
        /* POTENTIAL FLAW: Delete data in the source - the bad sink attempts to use data */
        delete data;
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW - Use of data that may have been deleted */
        printIntLine(data->a);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        break;
    }
    while(1)
    {
        /* FIX - Don't use data that may have been deleted already */
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
        break;
    }
}

/* goodG2B() - use goodsource and badsink by changing the conditions on the first and second while statements */
static void goodG2B()
{
    twointsclass * data;
    /* Initialize data */
    data = NULL;
    while(1)
    {
        data = new twointsclass;
        data->a = 1;
        data->b = 2;
        /* FIX: Do not delete data in the source */
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data = new twointsclass;
        data->a = 1;
        data->b = 2;
        /* POTENTIAL FLAW: Delete data in the source - the bad sink attempts to use data */
        delete data;
        break;
    }
    while(1)
    {
        /* POTENTIAL FLAW - Use of data that may have been deleted */
        printIntLine(data->a);
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX - Don't use data that may have been deleted already */
        /* POTENTIAL INCIDENTAL - Possible memory leak here if data was not deleted */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
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

using namespace CWE416_Use_After_Free__new_delete_class_16; // so that we can use good and bad easily

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
