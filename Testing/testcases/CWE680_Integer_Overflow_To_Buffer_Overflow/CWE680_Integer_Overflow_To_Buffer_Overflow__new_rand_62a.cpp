/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_To_Buffer_Overflow__new_rand_62a.cpp
Label Definition File: CWE680_Integer_Overflow_To_Buffer_Overflow__new.label.xml
Template File: sources-sink-62a.tmpl.cpp
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Small number greater than zero that will not cause an integer overflow in the sink
 * Sinks:
 *    BadSink : Attempt to allocate array using length value from source
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE680_Integer_Overflow_To_Buffer_Overflow__new_rand_62
{

#ifndef OMITBAD

/* bad function declaration */
void bad_source(int &data);

void bad()
{
    int data;
    /* Initialize data */
    data = -1;
    bad_source(data);
    {
        size_t a,i;
        int *b;
        /* POTENTIAL FLAW: a may overflow to a small value */
        a = data * sizeof(int); /* sizeof array in bytes */
        b = (int*)new char[a];
        for (i = 0; i < (size_t)data; i++)
        {
            b[i] = 0; /* may write beyond limit of b if integer overflow occured above */
        }
        printIntLine(b[0]);
        delete [] b;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2B_source(int &data);

static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    goodG2B_source(data);
    {
        size_t a,i;
        int *b;
        /* POTENTIAL FLAW: a may overflow to a small value */
        a = data * sizeof(int); /* sizeof array in bytes */
        b = (int*)new char[a];
        for (i = 0; i < (size_t)data; i++)
        {
            b[i] = 0; /* may write beyond limit of b if integer overflow occured above */
        }
        printIntLine(b[0]);
        delete [] b;
    }
}

void good()
{
    goodG2B();
}

#endif /* OMITGOOD */

} // close namespace

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE680_Integer_Overflow_To_Buffer_Overflow__new_rand_62; // so that we can use good and bad easily

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
