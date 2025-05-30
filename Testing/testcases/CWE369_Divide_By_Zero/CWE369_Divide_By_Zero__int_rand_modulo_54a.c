/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_By_Zero__int_rand_modulo_54a.c
Label Definition File: CWE369_Divide_By_Zero__int.label.xml
Template File: sources-sink-54a.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide By Zero
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Non-zero
 * Sink: modulo
 *    BadSink : Modulo a constant with data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE369_Divide_By_Zero__int_rand_modulo_54b_bad_sink(int data);

void CWE369_Divide_By_Zero__int_rand_modulo_54_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    data = RAND32();
    CWE369_Divide_By_Zero__int_rand_modulo_54b_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE369_Divide_By_Zero__int_rand_modulo_54b_goodG2B_sink(int data);

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a value not equal to zero */
    data = 7;
    CWE369_Divide_By_Zero__int_rand_modulo_54b_goodG2B_sink(data);
}

void CWE369_Divide_By_Zero__int_rand_modulo_54_good()
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
    CWE369_Divide_By_Zero__int_rand_modulo_54_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE369_Divide_By_Zero__int_rand_modulo_54_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
