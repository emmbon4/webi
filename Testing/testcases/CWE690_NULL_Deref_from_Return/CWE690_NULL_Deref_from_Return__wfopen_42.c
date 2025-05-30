/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_from_Return__wfopen_42.c
Label Definition File: CWE690_NULL_Deref_from_Return.fclose.label.xml
Template File: source-sinks-42.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: wfopen Open data with wfopen()
 * Sinks: 0
 *    GoodSink: Check data for NULL
 *    BadSink : Do not check data for NULL
 * Flow Variant: 42 Data flow: data returned from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define WFOPEN _wfopen
#else
/*fopen is used on unix-based OSs */
# define WFOPEN fopen
#endif

#ifndef OMITBAD

static FILE * bad_source(FILE * data)
{
    data = WFOPEN(L"file.txt", L"w+");
    return data;
}

void CWE690_NULL_Deref_from_Return__wfopen_42_bad()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    data = bad_source(data);
    /* FLAW: if the fopen failed, data could be NULL here */
    fclose(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static FILE * goodB2G_source(FILE * data)
{
    data = WFOPEN(L"file.txt", L"w+");
    return data;
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    data = goodB2G_source(data);
    /* FIX: check the return value */
    if (data != NULL)
    {
        fclose(data);
    }
}

void CWE690_NULL_Deref_from_Return__wfopen_42_good()
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
    CWE690_NULL_Deref_from_Return__wfopen_42_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE690_NULL_Deref_from_Return__wfopen_42_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
