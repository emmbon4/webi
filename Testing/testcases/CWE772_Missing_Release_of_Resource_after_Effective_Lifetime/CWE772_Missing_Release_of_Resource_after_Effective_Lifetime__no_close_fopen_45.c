/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_45.c
Label Definition File: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close.label.xml
Template File: source-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 772 Missing Release of Resource after Effective Lifetime
 * BadSource: fopen Open a file using fopen()
 * Sinks:
 *    GoodSink: Close the file using fclose()
 *    BadSink : Do not close file
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

static FILE * CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_45_bad_data;
static FILE * CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_45_goodB2G_data;

#ifndef OMITBAD

static void bad_sink()
{
    FILE * data = CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_45_bad_data;
    /* FLAW: No attempt to close the file */
    ; /* empty statement needed for some flow variants */
}

void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_45_bad()
{
    FILE * data;
    data = NULL;
    data = fopen("BadSource_fopen.txt", "w+");
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_45_bad_data = data;
    bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G_sink()
{
    FILE * data = CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_45_goodB2G_data;
    /* FIX: If the file is still opened, close it */
    if (data != NULL)
    {
        fclose(data);
    }
}

static void goodB2G()
{
    FILE * data;
    data = NULL;
    data = fopen("BadSource_fopen.txt", "w+");
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_45_goodB2G_data = data;
    goodB2G_sink();
}

void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_45_good()
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
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_45_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
