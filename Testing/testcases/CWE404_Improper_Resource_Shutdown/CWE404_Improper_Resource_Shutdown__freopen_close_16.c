/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__freopen_close_16.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-16.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource: freopen Open a file using freopen()
 * Sinks: close
 *    GoodSink: Close the file using fclose()
 *    BadSink : Close the file using close()
 * Flow Variant: 16 Control flow: while(1) and while(0)
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define CLOSE _close
#else
# define CLOSE close
#endif

#ifndef OMITBAD

void CWE404_Improper_Resource_Shutdown__freopen_close_16_bad()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    data = freopen("BadSource_freopen.txt","w+",stdin);
    while(1)
    {
        if (data != NULL)
        {
            /* FLAW: Attempt to close the file using close() instead of fclose() */
            CLOSE((int)data);
        }
        break;
    }
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        if (data != NULL)
        {
            /* FIX: Close the file using fclose() */
            fclose(data);
        }
        break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by changing the conditions on the while statements */
static void goodB2G()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    data = freopen("BadSource_freopen.txt","w+",stdin);
    while(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        if (data != NULL)
        {
            /* FLAW: Attempt to close the file using close() instead of fclose() */
            CLOSE((int)data);
        }
        break;
    }
    while(1)
    {
        if (data != NULL)
        {
            /* FIX: Close the file using fclose() */
            fclose(data);
        }
        break;
    }
}

void CWE404_Improper_Resource_Shutdown__freopen_close_16_good()
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
    CWE404_Improper_Resource_Shutdown__freopen_close_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE404_Improper_Resource_Shutdown__freopen_close_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
