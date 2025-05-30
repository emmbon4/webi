/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__fopen_close_53a.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-53a.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource: fopen Open a file using fopen()
 * Sinks: close
 *    GoodSink: Close the file using fclose()
 *    BadSink : Close the file using close()
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
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
void CWE404_Improper_Resource_Shutdown__fopen_close_53b_bad_sink(FILE * data);

void CWE404_Improper_Resource_Shutdown__fopen_close_53_bad()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    data = fopen("BadSource_fopen.txt", "w+");
    CWE404_Improper_Resource_Shutdown__fopen_close_53b_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE404_Improper_Resource_Shutdown__fopen_close_53b_goodB2G_sink(FILE * data);

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    data = fopen("BadSource_fopen.txt", "w+");
    CWE404_Improper_Resource_Shutdown__fopen_close_53b_goodB2G_sink(data);
}

void CWE404_Improper_Resource_Shutdown__fopen_close_53_good()
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
    CWE404_Improper_Resource_Shutdown__fopen_close_53_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE404_Improper_Resource_Shutdown__fopen_close_53_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
