/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__freopen_close_08.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-08.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource: freopen Open a file using freopen()
 * Sinks: close
 *    GoodSink: Close the file using fclose()
 *    BadSink : Close the file using close()
 * Flow Variant: 08 Control flow: if(static_returns_t()) and if(static_returns_f())
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define CLOSE _close
#else
# define CLOSE close
#endif

/* The two function below always return the same value, so a tool
   should be able to identify that calls to the functions will always
   return a fixed value. */
static int static_returns_t()
{
    return 1;
}

static int static_returns_f()
{
    return 0;
}

#ifndef OMITBAD

void CWE404_Improper_Resource_Shutdown__freopen_close_08_bad()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    data = freopen("BadSource_freopen.txt","w+",stdin);
    if(static_returns_t())
    {
        if (data != NULL)
        {
            /* FLAW: Attempt to close the file using close() instead of fclose() */
            CLOSE((int)data);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        if (data != NULL)
        {
            /* FIX: Close the file using fclose() */
            fclose(data);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing static_returns_t() to static_returns_f() */
static void goodB2G1()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    data = freopen("BadSource_freopen.txt","w+",stdin);
    if(static_returns_f())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        if (data != NULL)
        {
            /* FLAW: Attempt to close the file using close() instead of fclose() */
            CLOSE((int)data);
        }
    }
    else
    {
        if (data != NULL)
        {
            /* FIX: Close the file using fclose() */
            fclose(data);
        }
    }
}

/* goodB2G2() - use badsource and goodsink by reversing statements in if  */
static void goodB2G2()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    data = freopen("BadSource_freopen.txt","w+",stdin);
    if(static_returns_t())
    {
        if (data != NULL)
        {
            /* FIX: Close the file using fclose() */
            fclose(data);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        if (data != NULL)
        {
            /* FLAW: Attempt to close the file using close() instead of fclose() */
            CLOSE((int)data);
        }
    }
}

void CWE404_Improper_Resource_Shutdown__freopen_close_08_good()
{
    goodB2G1();
    goodB2G2();
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
    CWE404_Improper_Resource_Shutdown__freopen_close_08_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE404_Improper_Resource_Shutdown__freopen_close_08_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
