/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__rand_for_loop_34.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-34.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Assign count to be a relatively small number
 * Sinks: for_loop
 *    GoodSink: Validate count before using it as the loop variant in a for loop
 *    BadSink : Use count as the loop variant in a for loop
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

typedef union
{
    int a;
    int b;
} CWE400_Resource_Exhaustion__rand_for_loop_34_union_type;

#ifndef OMITBAD

void CWE400_Resource_Exhaustion__rand_for_loop_34_bad()
{
    int count;
    CWE400_Resource_Exhaustion__rand_for_loop_34_union_type my_union;
    /* Initialize count */
    count = -1;
    count = RAND32();
    my_union.a = count;
    {
        int count = my_union.b;
        {
            size_t i = 0;
            /* FLAW: For loop using count as the loop variant and no validation */
            for (i = 0; i < (size_t)count; i++)
            {
                printLine("Hello");
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    int count;
    CWE400_Resource_Exhaustion__rand_for_loop_34_union_type my_union;
    /* Initialize count */
    count = -1;
    /* FIX: Use a relatively small number */
    count = 20;
    my_union.a = count;
    {
        int count = my_union.b;
        {
            size_t i = 0;
            /* FLAW: For loop using count as the loop variant and no validation */
            for (i = 0; i < (size_t)count; i++)
            {
                printLine("Hello");
            }
        }
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    int count;
    CWE400_Resource_Exhaustion__rand_for_loop_34_union_type my_union;
    /* Initialize count */
    count = -1;
    count = RAND32();
    my_union.a = count;
    {
        int count = my_union.b;
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
}

void CWE400_Resource_Exhaustion__rand_for_loop_34_good()
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
    CWE400_Resource_Exhaustion__rand_for_loop_34_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE400_Resource_Exhaustion__rand_for_loop_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
