/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__rand_for_loop_44.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-44.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Assign count to be a relatively small number
 * Sinks: for_loop
 *    GoodSink: Validate count before using it as the loop variant in a for loop
 *    BadSink : Use count as the loop variant in a for loop
 * Flow Variant: 44 Data/control flow: data passed as an argument from one function to a function in the same source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

static void bad_sink(int count)
{
    {
        size_t i = 0;
        /* FLAW: For loop using count as the loop variant and no validation */
        for (i = 0; i < (size_t)count; i++)
        {
            printLine("Hello");
        }
    }
}

void CWE400_Resource_Exhaustion__rand_for_loop_44_bad()
{
    int count;
    /* define a function pointer */
    void (*func_ptr) (int) = bad_sink;
    /* Initialize count */
    count = -1;
    count = RAND32();
    /* use the function pointer */
    func_ptr(count);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B_sink(int count)
{
    {
        size_t i = 0;
        /* FLAW: For loop using count as the loop variant and no validation */
        for (i = 0; i < (size_t)count; i++)
        {
            printLine("Hello");
        }
    }
}

static void goodG2B()
{
    int count;
    void (*func_ptr) (int) = goodG2B_sink;
    /* Initialize count */
    count = -1;
    /* FIX: Use a relatively small number */
    count = 20;
    func_ptr(count);
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G_sink(int count)
{
    {
        size_t i = 0;
        /* FIX: Validate $Data% before using it as the for loop variant */
        if (count > 0 && count <= 20)
        {
            for (i = 0; i < (size_t)count; i++)
            {
                printLine("Hello");
            }
        }
    }
}

static void goodB2G()
{
    int count;
    void (*func_ptr) (int) = goodB2G_sink;
    /* Initialize count */
    count = -1;
    count = RAND32();
    func_ptr(count);
}

void CWE400_Resource_Exhaustion__rand_for_loop_44_good()
{
    goodG2B();
    goodB2G();
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
    CWE400_Resource_Exhaustion__rand_for_loop_44_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE400_Resource_Exhaustion__rand_for_loop_44_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
