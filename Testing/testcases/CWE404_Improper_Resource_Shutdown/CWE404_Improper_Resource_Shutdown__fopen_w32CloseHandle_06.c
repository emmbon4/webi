/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_06.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-06.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource: fopen Open a file using fopen()
 * Sinks: w32CloseHandle
 *    GoodSink: Close the file using fclose()
 *    BadSink : Close the file using CloseHandle
 * Flow Variant: 06 Control flow: if(static_const_five==5) and if(static_const_five!=5)
 *
 * */

#include "std_testcase.h"

#include <windows.h>

/* The variable below is declared "const", so a tool should be able
   to identify that reads of this will always give its initialized
   value. */
static const int static_const_five = 5;

#ifndef OMITBAD

void CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_06_bad()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    data = fopen("BadSource_fopen.txt", "w+");
    if(static_const_five==5)
    {
        if (data != NULL)
        {
            /* FLAW: Attempt to close the file using CloseHandle() instead of fclose() */
            CloseHandle((HANDLE)data);
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

/* goodB2G1() - use badsource and goodsink by changing static_const_five==5 to static_const_five!=5 */
static void goodB2G1()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    data = fopen("BadSource_fopen.txt", "w+");
    if(static_const_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        if (data != NULL)
        {
            /* FLAW: Attempt to close the file using CloseHandle() instead of fclose() */
            CloseHandle((HANDLE)data);
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
    data = fopen("BadSource_fopen.txt", "w+");
    if(static_const_five==5)
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
            /* FLAW: Attempt to close the file using CloseHandle() instead of fclose() */
            CloseHandle((HANDLE)data);
        }
    }
}

void CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_06_good()
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
    CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_06_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE404_Improper_Resource_Shutdown__fopen_w32CloseHandle_06_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
