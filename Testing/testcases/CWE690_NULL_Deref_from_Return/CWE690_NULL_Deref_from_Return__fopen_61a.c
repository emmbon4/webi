/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_from_Return__fopen_61a.c
Label Definition File: CWE690_NULL_Deref_from_Return.fclose.label.xml
Template File: source-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: fopen Open data with fopen()
 * Sinks: 0
 *    GoodSink: Check data for NULL
 *    BadSink : Do not check data for NULL
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
FILE * CWE690_NULL_Deref_from_Return__fopen_61b_bad_source(FILE * data);

void CWE690_NULL_Deref_from_Return__fopen_61_bad()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    data = CWE690_NULL_Deref_from_Return__fopen_61b_bad_source(data);
    /* FLAW: if the fopen failed, data could be NULL here */
    fclose(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
FILE * CWE690_NULL_Deref_from_Return__fopen_61b_goodB2G_source(FILE * data);

static void goodB2G()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    data = CWE690_NULL_Deref_from_Return__fopen_61b_goodB2G_source(data);
    /* FIX: check the return value */
    if (data != NULL)
    {
        fclose(data);
    }
}

void CWE690_NULL_Deref_from_Return__fopen_61_good()
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
    CWE690_NULL_Deref_from_Return__fopen_61_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE690_NULL_Deref_from_Return__fopen_61_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
