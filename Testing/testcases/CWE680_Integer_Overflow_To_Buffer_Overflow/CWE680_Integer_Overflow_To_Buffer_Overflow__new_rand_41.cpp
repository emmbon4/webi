/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_To_Buffer_Overflow__new_rand_41.cpp
Label Definition File: CWE680_Integer_Overflow_To_Buffer_Overflow__new.label.xml
Template File: sources-sink-41.tmpl.cpp
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Small number greater than zero that will not cause an integer overflow in the sink
 * Sink:
 *    BadSink : Attempt to allocate array using length value from source
 * Flow Variant: 41 Data flow: data passed as an argument from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

namespace CWE680_Integer_Overflow_To_Buffer_Overflow__new_rand_41
{

#ifndef OMITBAD

void bad_sink(int data)
{
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

void bad()
{
    int data;
    /* Initialize data */
    data = -1;
    data = RAND32();
    bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

void goodG2B_sink(int data)
{
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

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Set data to a relatively small number greater than zero */
    data = 20;
    goodG2B_sink(data);
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

using namespace CWE680_Integer_Overflow_To_Buffer_Overflow__new_rand_41; // so that we can use good and bad easily

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
