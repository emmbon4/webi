/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_By_Zero__int_fgets_modulo_68a.c
Label Definition File: CWE369_Divide_By_Zero__int.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide By Zero
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Non-zero
 * Sink: modulo
 *    BadSink : Modulo a constant with data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(data)*sizeof(data)

int CWE369_Divide_By_Zero__int_fgets_modulo_68_bad_data;
int CWE369_Divide_By_Zero__int_fgets_modulo_68_goodG2B_data;

#ifndef OMITBAD

/* bad function declaration */
void CWE369_Divide_By_Zero__int_fgets_modulo_68b_bad_sink();

void CWE369_Divide_By_Zero__int_fgets_modulo_68_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    {
        char input_buf[CHAR_ARRAY_SIZE] = "";
        fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
        /* Convert to int */
        data = atoi(input_buf);
    }
    CWE369_Divide_By_Zero__int_fgets_modulo_68_bad_data = data;
    CWE369_Divide_By_Zero__int_fgets_modulo_68b_bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE369_Divide_By_Zero__int_fgets_modulo_68b_goodG2B_sink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a value not equal to zero */
    data = 7;
    CWE369_Divide_By_Zero__int_fgets_modulo_68_goodG2B_data = data;
    CWE369_Divide_By_Zero__int_fgets_modulo_68b_goodG2B_sink();
}

void CWE369_Divide_By_Zero__int_fgets_modulo_68_good()
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
    CWE369_Divide_By_Zero__int_fgets_modulo_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE369_Divide_By_Zero__int_fgets_modulo_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
