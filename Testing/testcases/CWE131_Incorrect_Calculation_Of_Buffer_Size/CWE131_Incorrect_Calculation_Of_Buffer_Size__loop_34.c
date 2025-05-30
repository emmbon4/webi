/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE131_Incorrect_Calculation_Of_Buffer_Size__loop_34.c
Label Definition File: CWE131_Incorrect_Calculation_Of_Buffer_Size.missing_sizeof.label.xml
Template File: sources-sink-34.tmpl.c
*/
/*
 * @description
 * CWE: 131 Incorrect Calculation of Buffer Size
 * BadSource:  Allocate memory without using sizeof(int)
 * GoodSource: Allocate memory using sizeof(int)
 * Sinks: loop
 *    BadSink : Copy array to data using a loop
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

typedef union
{
    int * a;
    int * b;
} CWE131_Incorrect_Calculation_Of_Buffer_Size__loop_34_union_type;

#ifndef OMITBAD

void CWE131_Incorrect_Calculation_Of_Buffer_Size__loop_34_bad()
{
    int * data;
    CWE131_Incorrect_Calculation_Of_Buffer_Size__loop_34_union_type my_union;
    data = NULL;
    /* FLAW: Allocate memory without using sizeof(int *) */
    data = (int *)malloc(10);
    my_union.a = data;
    {
        int * data = my_union.b;
        {
            int data_src[10] = {0};
            size_t i;
            /* POTENTIAL FLAW: Possible buffer overflow if data was not allocated correctly in the source */
            for (i = 0; i < 10; i++)
            {
                data[i] = data_src[i];
            }
            printIntLine(data[0]);
            free(data);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    int * data;
    CWE131_Incorrect_Calculation_Of_Buffer_Size__loop_34_union_type my_union;
    data = NULL;
    /* FIX: Allocate memory using sizeof(int *) */
    data = (int *)malloc(10*sizeof(int));
    my_union.a = data;
    {
        int * data = my_union.b;
        {
            int data_src[10] = {0};
            size_t i;
            /* POTENTIAL FLAW: Possible buffer overflow if data was not allocated correctly in the source */
            for (i = 0; i < 10; i++)
            {
                data[i] = data_src[i];
            }
            printIntLine(data[0]);
            free(data);
        }
    }
}

void CWE131_Incorrect_Calculation_Of_Buffer_Size__loop_34_good()
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
    CWE131_Incorrect_Calculation_Of_Buffer_Size__loop_34_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE131_Incorrect_Calculation_Of_Buffer_Size__loop_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
