/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_array_char_33.cpp
Label Definition File: CWE401_Memory_Leak__new_array.label.xml
Template File: sources-sinks-33.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new[]
 * GoodSource: Point data to a stack buffer
 * Sinks:
 *    GoodSink: call delete[] on data
 *    BadSink : no deallocation of data
 * Flow Variant: 33 Data flow: use of a C++ reference to data within the same function
 *
 * */

#include "std_testcase.h"

namespace CWE401_Memory_Leak__new_array_char_33
{

#ifndef OMITBAD

void bad()
{
    char * data;
    char * &data_ref = data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new char[100];
    /* Initialize and make use of data */
    strcpy(data, "A String");
    printLine(data);
    {
        char * data = data_ref;
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    char * &data_ref = data;
    data = NULL;
    {
        /* FIX: Use memory allocated on the stack */
        char data_goodbuf[100];
        data = data_goodbuf;
        /* Initialize and make use of data */
        strcpy(data, "A String");
        printLine(data);
    }
    {
        char * data = data_ref;
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    char * data;
    char * &data_ref = data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new char[100];
    /* Initialize and make use of data */
    strcpy(data, "A String");
    printLine(data);
    {
        char * data = data_ref;
        /* FIX: Deallocate memory */
        delete[] data;
    }
}

void good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */
#ifdef INCLUDEMAIN

using namespace CWE401_Memory_Leak__new_array_char_33; // so that we can use good and bad easily

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
