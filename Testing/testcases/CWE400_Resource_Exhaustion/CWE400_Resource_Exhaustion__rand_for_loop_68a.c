/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__rand_for_loop_68a.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Assign count to be a relatively small number
 * Sinks: for_loop
 *    GoodSink: Validate count before using it as the loop variant in a for loop
 *    BadSink : Use count as the loop variant in a for loop
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

int CWE400_Resource_Exhaustion__rand_for_loop_68_bad_data;
int CWE400_Resource_Exhaustion__rand_for_loop_68_goodG2B_data;
int CWE400_Resource_Exhaustion__rand_for_loop_68_goodB2G_data;

#ifndef OMITBAD

/* bad function declaration */
void CWE400_Resource_Exhaustion__rand_for_loop_68b_bad_sink();

void CWE400_Resource_Exhaustion__rand_for_loop_68_bad()
{
    int count;
    /* Initialize count */
    count = -1;
    count = RAND32();
    CWE400_Resource_Exhaustion__rand_for_loop_68_bad_data = count;
    CWE400_Resource_Exhaustion__rand_for_loop_68b_bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE400_Resource_Exhaustion__rand_for_loop_68b_goodG2B_sink();
void CWE400_Resource_Exhaustion__rand_for_loop_68b_goodB2G_sink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int count;
    /* Initialize count */
    count = -1;
    /* FIX: Use a relatively small number */
    count = 20;
    CWE400_Resource_Exhaustion__rand_for_loop_68_goodG2B_data = count;
    CWE400_Resource_Exhaustion__rand_for_loop_68b_goodG2B_sink();
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    int count;
    /* Initialize count */
    count = -1;
    count = RAND32();
    CWE400_Resource_Exhaustion__rand_for_loop_68_goodB2G_data = count;
    CWE400_Resource_Exhaustion__rand_for_loop_68b_goodB2G_sink();
}

void CWE400_Resource_Exhaustion__rand_for_loop_68_good()
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
    CWE400_Resource_Exhaustion__rand_for_loop_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE400_Resource_Exhaustion__rand_for_loop_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
