/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_from_Return__wfopen_13.c
Label Definition File: CWE690_NULL_Deref_from_Return.fclose.label.xml
Template File: source-sinks-13.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: wfopen Open data with wfopen()
 * Sinks: 0
 *    GoodSink: Check data for NULL
 *    BadSink : Do not check data for NULL
 * Flow Variant: 13 Control flow: if(global_const_five==5) and if(global_const_five!=5)
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

void CWE690_NULL_Deref_from_Return__wfopen_13_bad()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    data = WFOPEN(L"file.txt", L"w+");
    if(global_const_five==5)
    {
        /* FLAW: if the fopen failed, data could be NULL here */
        fclose(data);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: check the return value */
        if (data != NULL)
        {
            fclose(data);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing global_const_five==5 to global_const_five!=5 */
static void goodB2G1()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    data = WFOPEN(L"file.txt", L"w+");
    if(global_const_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: if the fopen failed, data could be NULL here */
        fclose(data);
    }
    else
    {
        /* FIX: check the return value */
        if (data != NULL)
        {
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
    data = WFOPEN(L"file.txt", L"w+");
    if(global_const_five==5)
    {
        /* FIX: check the return value */
        if (data != NULL)
        {
            fclose(data);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: if the fopen failed, data could be NULL here */
        fclose(data);
    }
}

void CWE690_NULL_Deref_from_Return__wfopen_13_good()
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
    CWE690_NULL_Deref_from_Return__wfopen_13_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE690_NULL_Deref_from_Return__wfopen_13_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
