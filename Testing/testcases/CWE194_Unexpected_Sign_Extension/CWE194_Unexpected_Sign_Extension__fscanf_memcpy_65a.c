/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE194_Unexpected_Sign_Extension__fscanf_memcpy_65a.c
Label Definition File: CWE194_Unexpected_Sign_Extension.label.xml
Template File: sources-sink-65a.tmpl.c
*/
/*
 * @description
 * CWE: 194 Unexpected Sign Extension
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Positive integer
 * Sinks: memcpy
 *    BadSink : Copy strings using memcpy() with the length of data
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE194_Unexpected_Sign_Extension__fscanf_memcpy_65b_bad_sink(short data);

void CWE194_Unexpected_Sign_Extension__fscanf_memcpy_65_bad()
{
    short data;
    /* define a function pointer */
    void (*func_ptr) (short) = CWE194_Unexpected_Sign_Extension__fscanf_memcpy_65b_bad_sink;
    /* Initialize data */
    data = 0;
    /* POTENTIAL FLAW: Use a value input from the console using fscanf() */
    fscanf (stdin, "%hd", &data);
    /* use the function pointer */
    func_ptr(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE194_Unexpected_Sign_Extension__fscanf_memcpy_65b_goodG2B_sink(short data);

static void goodG2B()
{
    short data;
    void (*func_ptr) (short) = CWE194_Unexpected_Sign_Extension__fscanf_memcpy_65b_goodG2B_sink;
    /* Initialize data */
    data = 0;
    /* FIX: Use a positive integer less than &InitialDataSize&*/
    data = 100-1;
    func_ptr(data);
}

void CWE194_Unexpected_Sign_Extension__fscanf_memcpy_65_good()
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
    CWE194_Unexpected_Sign_Extension__fscanf_memcpy_65_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE194_Unexpected_Sign_Extension__fscanf_memcpy_65_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
