/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_char_63a.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-63a.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE401_Memory_Leak__new_char_63
{

#ifndef OMITBAD

/* bad function declaration */
void bad_sink(char * * data_ptr);

void bad()
{
    char * data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new char;
    /* Initialize and make use of data */
    *data = 'A';
    printHexCharLine(*data);
    bad_sink(&data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_sink(char * * data);

static void goodG2B()
{
    char * data;
    data = NULL;
    /* FIX: Use memory allocated on the stack */
    char data_good;
    data = &data_good;
    /* Initialize and make use of data */
    *data = 'A';
    printHexCharLine(*data);
    goodG2B_sink(&data);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2G_sink(char * * data);

static void goodB2G()
{
    char * data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new char;
    /* Initialize and make use of data */
    *data = 'A';
    printHexCharLine(*data);
    goodB2G_sink(&data);
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

using namespace CWE401_Memory_Leak__new_char_63; // so that we can use good and bad easily

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
