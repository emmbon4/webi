/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__open_fclose_61a.c
Label Definition File: CWE404_Improper_Resource_Shutdown__open.label.xml
Template File: source-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource:  Open a file using open()
 * Sinks: fclose
 *    GoodSink: Close the file using close()
 *    BadSink : Close the file using fclose()
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define OPEN _open
# define CLOSE _close
#else
# define OPEN open
# define CLOSE close
#endif

#ifndef OMITBAD

/* bad function declaration */
int CWE404_Improper_Resource_Shutdown__open_fclose_61b_bad_source(int data);

void CWE404_Improper_Resource_Shutdown__open_fclose_61_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    data = CWE404_Improper_Resource_Shutdown__open_fclose_61b_bad_source(data);
    if (data != -1)
    {
        /* FLAW: Attempt to close the file using fclose() instead of close() */
        fclose((FILE *)data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
int CWE404_Improper_Resource_Shutdown__open_fclose_61b_goodB2G_source(int data);

static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    data = CWE404_Improper_Resource_Shutdown__open_fclose_61b_goodB2G_source(data);
    if (data != -1)
    {
        /* FIX: Close the file using close() */
        CLOSE(data);
    }
}

void CWE404_Improper_Resource_Shutdown__open_fclose_61_good()
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
    CWE404_Improper_Resource_Shutdown__open_fclose_61_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE404_Improper_Resource_Shutdown__open_fclose_61_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
