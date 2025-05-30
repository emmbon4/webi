/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__freopen_15.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-15.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource: freopen Open and close a file using freopen() and flose()
 * GoodSource: Open a file using fopen()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 15 Control flow: switch(6) and switch(7)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE675_Duplicate_Operations_on_Resource__freopen_15_bad()
{
    FILE * data;
    data = NULL; /* Initialize data */
    switch(6)
    {
    case 6:
        data = freopen("BadSource_freopen.txt","w+",stdin);
        /* POTENTIAL FLAW: Close the file in the source */
        fclose(data);
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Open, but do not close the file in the source */
        data = fopen("GoodSource_fopen.txt", "w+");
        break;
    }
    switch(7)
    {
    case 7:
        /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
        fclose(data);
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* Do nothing */
        /* FIX: Don't close the file in the sink */
        ; /* empty statement needed for some flow variants */
        break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second switch to switch(8) */
static void goodB2G1()
{
    FILE * data;
    data = NULL; /* Initialize data */
    switch(6)
    {
    case 6:
        data = freopen("BadSource_freopen.txt","w+",stdin);
        /* POTENTIAL FLAW: Close the file in the source */
        fclose(data);
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Open, but do not close the file in the source */
        data = fopen("GoodSource_fopen.txt", "w+");
        break;
    }
    switch(8)
    {
    case 7:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
        fclose(data);
        break;
    default:
        /* Do nothing */
        /* FIX: Don't close the file in the sink */
        ; /* empty statement needed for some flow variants */
        break;
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second switch */
static void goodB2G2()
{
    FILE * data;
    data = NULL; /* Initialize data */
    switch(6)
    {
    case 6:
        data = freopen("BadSource_freopen.txt","w+",stdin);
        /* POTENTIAL FLAW: Close the file in the source */
        fclose(data);
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: Open, but do not close the file in the source */
        data = fopen("GoodSource_fopen.txt", "w+");
        break;
    }
    switch(7)
    {
    case 7:
        /* Do nothing */
        /* FIX: Don't close the file in the sink */
        ; /* empty statement needed for some flow variants */
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
        fclose(data);
        break;
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first switch to switch(5) */
static void goodG2B1()
{
    FILE * data;
    data = NULL; /* Initialize data */
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data = freopen("BadSource_freopen.txt","w+",stdin);
        /* POTENTIAL FLAW: Close the file in the source */
        fclose(data);
        break;
    default:
        /* FIX: Open, but do not close the file in the source */
        data = fopen("GoodSource_fopen.txt", "w+");
        break;
    }
    switch(7)
    {
    case 7:
        /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
        fclose(data);
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* Do nothing */
        /* FIX: Don't close the file in the sink */
        ; /* empty statement needed for some flow variants */
        break;
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first switch */
static void goodG2B2()
{
    FILE * data;
    data = NULL; /* Initialize data */
    switch(6)
    {
    case 6:
        /* FIX: Open, but do not close the file in the source */
        data = fopen("GoodSource_fopen.txt", "w+");
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        data = freopen("BadSource_freopen.txt","w+",stdin);
        /* POTENTIAL FLAW: Close the file in the source */
        fclose(data);
        break;
    }
    switch(7)
    {
    case 7:
        /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
        fclose(data);
        break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* Do nothing */
        /* FIX: Don't close the file in the sink */
        ; /* empty statement needed for some flow variants */
        break;
    }
}

void CWE675_Duplicate_Operations_on_Resource__freopen_15_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
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
    CWE675_Duplicate_Operations_on_Resource__freopen_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE675_Duplicate_Operations_on_Resource__freopen_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
