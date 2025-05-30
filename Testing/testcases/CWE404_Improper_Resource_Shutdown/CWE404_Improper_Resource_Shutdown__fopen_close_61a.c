/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__fopen_close_61a.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource: fopen Open a file using fopen()
 * Sinks: close
 *    GoodSink: Close the file using fclose()
 *    BadSink : Close the file using close()
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define CLOSE _close
#else
# define CLOSE close
#endif

#ifndef OMITBAD

/* bad function declaration */
FILE * CWE404_Improper_Resource_Shutdown__fopen_close_61b_bad_source(FILE * data);

void CWE404_Improper_Resource_Shutdown__fopen_close_61_bad()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    data = CWE404_Improper_Resource_Shutdown__fopen_close_61b_bad_source(data);
    if (data != NULL)
    {
        /* FLAW: Attempt to close the file using close() instead of fclose() */
        CLOSE((int)data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
FILE * CWE404_Improper_Resource_Shutdown__fopen_close_61b_goodB2G_source(FILE * data);

static void goodB2G()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    data = CWE404_Improper_Resource_Shutdown__fopen_close_61b_goodB2G_source(data);
    if (data != NULL)
    {
        /* FIX: Close the file using fclose() */
        fclose(data);
    }
}

void CWE404_Improper_Resource_Shutdown__fopen_close_61_good()
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
    CWE404_Improper_Resource_Shutdown__fopen_close_61_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE404_Improper_Resource_Shutdown__fopen_close_61_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
