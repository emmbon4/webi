/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_value_wchar_t_18.c
Label Definition File: CWE563_Unused_Variable__unused_value.label.xml
Template File: sources-sinks-18.tmpl.c
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * GoodSource: Initialize and use data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : Initialize and use data
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE563_Unused_Variable__unused_value_wchar_t_18_bad()
{
    wchar_t data;
    goto source;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* FIX: Initialize and use data before it is overwritten */
    data = L'W';
    printf("%02lx\n", data);
source:
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data = L'W';
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* FIX: Use data without over-writing its value */
    printf("%02lx\n", data);
sink:
    /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
    data = L'Z';
    printf("%02lx\n", data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by reversing the blocks on the second goto statement */
static void goodB2G()
{
    wchar_t data;
    goto source;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* FIX: Initialize and use data before it is overwritten */
    data = L'W';
    printf("%02lx\n", data);
source:
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data = L'W';
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
    data = L'Z';
    printf("%02lx\n", data);
sink:
    /* FIX: Use data without over-writing its value */
    printf("%02lx\n", data);
}

/* goodG2B() - use goodsource and badsink by reversing the blocks on the first goto statement */
static void goodG2B()
{
    wchar_t data;
    goto source;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data = L'W';
source:
    /* FIX: Initialize and use data before it is overwritten */
    data = L'W';
    printf("%02lx\n", data);
    goto sink;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* FIX: Use data without over-writing its value */
    printf("%02lx\n", data);
sink:
    /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
    data = L'Z';
    printf("%02lx\n", data);
}

void CWE563_Unused_Variable__unused_value_wchar_t_18_good()
{
    goodB2G();
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
    CWE563_Unused_Variable__unused_value_wchar_t_18_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE563_Unused_Variable__unused_value_wchar_t_18_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
