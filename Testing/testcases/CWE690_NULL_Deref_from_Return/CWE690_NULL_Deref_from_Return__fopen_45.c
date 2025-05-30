/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_from_Return__fopen_45.c
Label Definition File: CWE690_NULL_Deref_from_Return.fclose.label.xml
Template File: source-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: fopen Open data with fopen()
 * Sinks: 0
 *    GoodSink: Check data for NULL
 *    BadSink : Do not check data for NULL
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

static FILE * CWE690_NULL_Deref_from_Return__fopen_45_bad_data;
static FILE * CWE690_NULL_Deref_from_Return__fopen_45_goodB2G_data;

#ifndef OMITBAD

static void bad_sink()
{
    FILE * data = CWE690_NULL_Deref_from_Return__fopen_45_bad_data;
    /* FLAW: if the fopen failed, data could be NULL here */
    fclose(data);
}

void CWE690_NULL_Deref_from_Return__fopen_45_bad()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    data = fopen("file.txt", "w+");
    CWE690_NULL_Deref_from_Return__fopen_45_bad_data = data;
    bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G_sink()
{
    FILE * data = CWE690_NULL_Deref_from_Return__fopen_45_goodB2G_data;
    /* FIX: check the return value */
    if (data != NULL)
    {
        fclose(data);
    }
}

static void goodB2G()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    data = fopen("file.txt", "w+");
    CWE690_NULL_Deref_from_Return__fopen_45_goodB2G_data = data;
    goodB2G_sink();
}

void CWE690_NULL_Deref_from_Return__fopen_45_good()
{
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
    CWE690_NULL_Deref_from_Return__fopen_45_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE690_NULL_Deref_from_Return__fopen_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
