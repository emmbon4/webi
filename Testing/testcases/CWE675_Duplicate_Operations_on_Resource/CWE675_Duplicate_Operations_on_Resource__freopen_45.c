/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__freopen_45.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource: freopen Open and close a file using freopen() and flose()
 * GoodSource: Open a file using fopen()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

static FILE * CWE675_Duplicate_Operations_on_Resource__freopen_45_bad_data;
static FILE * CWE675_Duplicate_Operations_on_Resource__freopen_45_goodG2B_data;
static FILE * CWE675_Duplicate_Operations_on_Resource__freopen_45_goodB2G_data;

#ifndef OMITBAD

static void bad_sink()
{
    FILE * data = CWE675_Duplicate_Operations_on_Resource__freopen_45_bad_data;
    /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
    fclose(data);
}

void CWE675_Duplicate_Operations_on_Resource__freopen_45_bad()
{
    FILE * data;
    data = NULL; /* Initialize data */
    data = freopen("BadSource_freopen.txt","w+",stdin);
    /* POTENTIAL FLAW: Close the file in the source */
    fclose(data);
    CWE675_Duplicate_Operations_on_Resource__freopen_45_bad_data = data;
    bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B_sink()
{
    FILE * data = CWE675_Duplicate_Operations_on_Resource__freopen_45_goodG2B_data;
    /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
    fclose(data);
}

static void goodG2B()
{
    FILE * data;
    data = NULL; /* Initialize data */
    /* FIX: Open, but do not close the file in the source */
    data = fopen("GoodSource_fopen.txt", "w+");
    CWE675_Duplicate_Operations_on_Resource__freopen_45_goodG2B_data = data;
    goodG2B_sink();
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G_sink()
{
    FILE * data = CWE675_Duplicate_Operations_on_Resource__freopen_45_goodB2G_data;
    /* Do nothing */
    /* FIX: Don't close the file in the sink */
    ; /* empty statement needed for some flow variants */
}

static void goodB2G()
{
    FILE * data;
    data = NULL; /* Initialize data */
    data = freopen("BadSource_freopen.txt","w+",stdin);
    /* POTENTIAL FLAW: Close the file in the source */
    fclose(data);
    CWE675_Duplicate_Operations_on_Resource__freopen_45_goodB2G_data = data;
    goodB2G_sink();
}

void CWE675_Duplicate_Operations_on_Resource__freopen_45_good()
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
    CWE675_Duplicate_Operations_on_Resource__freopen_45_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE675_Duplicate_Operations_on_Resource__freopen_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
