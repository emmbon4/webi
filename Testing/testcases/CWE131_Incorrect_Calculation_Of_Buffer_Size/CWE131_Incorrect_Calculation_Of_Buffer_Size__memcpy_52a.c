/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE131_Incorrect_Calculation_Of_Buffer_Size__memcpy_52a.c
Label Definition File: CWE131_Incorrect_Calculation_Of_Buffer_Size.missing_sizeof.label.xml
Template File: sources-sink-52a.tmpl.c
*/
/*
 * @description
 * CWE: 131 Incorrect Calculation of Buffer Size
 * BadSource:  Allocate memory without using sizeof(int)
 * GoodSource: Allocate memory using sizeof(int)
 * Sink: memcpy
 *    BadSink : Copy array to data using memcpy()
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE131_Incorrect_Calculation_Of_Buffer_Size__memcpy_52b_bad_sink(int * data);

void CWE131_Incorrect_Calculation_Of_Buffer_Size__memcpy_52_bad()
{
    int * data;
    data = NULL;
    /* FLAW: Allocate memory without using sizeof(int *) */
    data = (int *)malloc(10);
    CWE131_Incorrect_Calculation_Of_Buffer_Size__memcpy_52b_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE131_Incorrect_Calculation_Of_Buffer_Size__memcpy_52b_goodG2B_sink(int * data);

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int * data;
    data = NULL;
    /* FIX: Allocate memory using sizeof(int *) */
    data = (int *)malloc(10*sizeof(int));
    CWE131_Incorrect_Calculation_Of_Buffer_Size__memcpy_52b_goodG2B_sink(data);
}

void CWE131_Incorrect_Calculation_Of_Buffer_Size__memcpy_52_good()
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
    CWE131_Incorrect_Calculation_Of_Buffer_Size__memcpy_52_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE131_Incorrect_Calculation_Of_Buffer_Size__memcpy_52_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
