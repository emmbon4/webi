/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_from_Return__wfopen_32.c
Label Definition File: CWE690_NULL_Deref_from_Return.fclose.label.xml
Template File: source-sinks-32.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: wfopen Open data with wfopen()
 * Sinks: 0
 *    GoodSink: Check data for NULL
 *    BadSink : Do not check data for NULL
 * Flow Variant: 32 Data flow: two pointers to the same value within the same function
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

void CWE690_NULL_Deref_from_Return__wfopen_32_bad()
{
    FILE * data;
    FILE * *data_ptr1 = &data;
    FILE * *data_ptr2 = &data;
    /* Initialize data */
    data = NULL;
    {
        FILE * data = *data_ptr1;
        data = WFOPEN(L"file.txt", L"w+");
        *data_ptr1 = data;
    }
    {
        FILE * data = *data_ptr2;
        /* FLAW: if the fopen failed, data could be NULL here */
        fclose(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    FILE * data;
    FILE * *data_ptr1 = &data;
    FILE * *data_ptr2 = &data;
    /* Initialize data */
    data = NULL;
    {
        FILE * data = *data_ptr1;
        data = WFOPEN(L"file.txt", L"w+");
        *data_ptr1 = data;
    }
    {
        FILE * data = *data_ptr2;
        /* FIX: check the return value */
        if (data != NULL)
        {
            fclose(data);
        }
    }
}

void CWE690_NULL_Deref_from_Return__wfopen_32_good()
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
    CWE690_NULL_Deref_from_Return__wfopen_32_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE690_NULL_Deref_from_Return__wfopen_32_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
