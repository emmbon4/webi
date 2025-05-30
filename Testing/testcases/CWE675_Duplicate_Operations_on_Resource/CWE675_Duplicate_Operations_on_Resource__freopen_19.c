/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__freopen_19.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-19.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource: freopen Open and close a file using freopen() and flose()
 * GoodSource: Open a file using fopen()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 19 Control flow: Dead code after a return
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE675_Duplicate_Operations_on_Resource__freopen_19_bad()
{
    FILE * data;
    data = NULL; /* Initialize data */
    data = freopen("BadSource_freopen.txt","w+",stdin);
    /* POTENTIAL FLAW: Close the file in the source */
    fclose(data);
    /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
    fclose(data);
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* Do nothing */
    /* FIX: Don't close the file in the sink */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by switching statements around return */
static void goodB2G()
{
    FILE * data;
    data = NULL; /* Initialize data */
    data = freopen("BadSource_freopen.txt","w+",stdin);
    /* POTENTIAL FLAW: Close the file in the source */
    fclose(data);
    /* Do nothing */
    /* FIX: Don't close the file in the sink */
    ; /* empty statement needed for some flow variants */
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
    fclose(data);
}

/* goodG2B() - use goodsource and badsink by moving BadSource and BadSink to after return */
static void goodG2B()
{
    FILE * data;
    data = NULL; /* Initialize data */
    /* FIX: Open, but do not close the file in the source */
    data = fopen("GoodSource_fopen.txt", "w+");
    /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
    fclose(data);
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    data = freopen("BadSource_freopen.txt","w+",stdin);
    /* POTENTIAL FLAW: Close the file in the source */
    fclose(data);
    /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
    fclose(data);
}

void CWE675_Duplicate_Operations_on_Resource__freopen_19_good()
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
    CWE675_Duplicate_Operations_on_Resource__freopen_19_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE675_Duplicate_Operations_on_Resource__freopen_19_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
