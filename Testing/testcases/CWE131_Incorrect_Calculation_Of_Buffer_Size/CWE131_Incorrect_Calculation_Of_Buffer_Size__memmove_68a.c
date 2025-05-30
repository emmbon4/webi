/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE131_Incorrect_Calculation_Of_Buffer_Size__memmove_68a.c
Label Definition File: CWE131_Incorrect_Calculation_Of_Buffer_Size.missing_sizeof.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 131 Incorrect Calculation of Buffer Size
 * BadSource:  Allocate memory without using sizeof(int)
 * GoodSource: Allocate memory using sizeof(int)
 * Sink: memmove
 *    BadSink : Copy array to data using memmove()
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

int * CWE131_Incorrect_Calculation_Of_Buffer_Size__memmove_68_bad_data;
int * CWE131_Incorrect_Calculation_Of_Buffer_Size__memmove_68_goodG2B_data;

#ifndef OMITBAD

/* bad function declaration */
void CWE131_Incorrect_Calculation_Of_Buffer_Size__memmove_68b_bad_sink();

void CWE131_Incorrect_Calculation_Of_Buffer_Size__memmove_68_bad()
{
    int * data;
    data = NULL;
    /* FLAW: Allocate memory without using sizeof(int *) */
    data = (int *)malloc(10);
    CWE131_Incorrect_Calculation_Of_Buffer_Size__memmove_68_bad_data = data;
    CWE131_Incorrect_Calculation_Of_Buffer_Size__memmove_68b_bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE131_Incorrect_Calculation_Of_Buffer_Size__memmove_68b_goodG2B_sink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int * data;
    data = NULL;
    /* FIX: Allocate memory using sizeof(int *) */
    data = (int *)malloc(10*sizeof(int));
    CWE131_Incorrect_Calculation_Of_Buffer_Size__memmove_68_goodG2B_data = data;
    CWE131_Incorrect_Calculation_Of_Buffer_Size__memmove_68b_goodG2B_sink();
}

void CWE131_Incorrect_Calculation_Of_Buffer_Size__memmove_68_good()
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
    CWE131_Incorrect_Calculation_Of_Buffer_Size__memmove_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE131_Incorrect_Calculation_Of_Buffer_Size__memmove_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
