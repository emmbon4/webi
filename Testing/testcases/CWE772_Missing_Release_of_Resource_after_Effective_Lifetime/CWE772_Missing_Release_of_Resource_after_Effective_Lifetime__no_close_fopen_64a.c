/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_64a.c
Label Definition File: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close.label.xml
Template File: source-sinks-64a.tmpl.c
*/
/*
 * @description
 * CWE: 772 Missing Release of Resource after Effective Lifetime
 * BadSource: fopen Open a file using fopen()
 * Sinks:
 *    GoodSink: Close the file using fclose()
 *    BadSink : Do not close file
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_64b_bad_sink(void * void_data_ptr);

void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_64_bad()
{
    FILE * data;
    data = NULL;
    data = fopen("BadSource_fopen.txt", "w+");
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_64b_bad_sink(&data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_64b_goodB2G_sink(void * void_data_ptr);

static void goodB2G()
{
    FILE * data;
    data = NULL;
    data = fopen("BadSource_fopen.txt", "w+");
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_64b_goodB2G_sink(&data);
}

void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_64_good()
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
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_64_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__no_close_fopen_64_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
