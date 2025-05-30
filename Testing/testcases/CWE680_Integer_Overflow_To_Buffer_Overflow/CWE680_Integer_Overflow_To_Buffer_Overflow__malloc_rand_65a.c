/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_rand_65a.c
Label Definition File: CWE680_Integer_Overflow_To_Buffer_Overflow__malloc.label.xml
Template File: sources-sink-65a.tmpl.c
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Small number greater than zero that will not cause an integer overflow in the sink
 * Sinks:
 *    BadSink : Attempt to allocate array using length value from source
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_rand_65b_bad_sink(int data);

void CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_rand_65_bad()
{
    int data;
    /* define a function pointer */
    void (*func_ptr) (int) = CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_rand_65b_bad_sink;
    /* Initialize data */
    data = -1;
    data = RAND32();
    /* use the function pointer */
    func_ptr(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_rand_65b_goodG2B_sink(int data);

static void goodG2B()
{
    int data;
    void (*func_ptr) (int) = CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_rand_65b_goodG2B_sink;
    /* Initialize data */
    data = -1;
    /* FIX: Set data to a relatively small number greater than zero */
    data = 20;
    func_ptr(data);
}

void CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_rand_65_good()
{
    goodG2B();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_rand_65_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE680_Integer_Overflow_To_Buffer_Overflow__malloc_rand_65_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
