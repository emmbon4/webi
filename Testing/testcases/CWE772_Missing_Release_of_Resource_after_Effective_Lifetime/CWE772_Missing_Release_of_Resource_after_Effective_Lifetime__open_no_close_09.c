/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__open_no_close_09.c
Label Definition File: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__open_no_close.label.xml
Template File: source-sinks-09.tmpl.c
*/
/*
 * @description
 * CWE: 772 Missing Release of Resource after Effective Lifetime
 * BadSource:  Open a file using open()
 * Sinks:
 *    GoodSink: Close the file using close()
 *    BadSink : Do not close file
 * Flow Variant: 09 Control flow: if(global_const_t) and if(global_const_f)
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

void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__open_no_close_09_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    data = OPEN("BadSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    if(global_const_t)
    {
        /* FLAW: No attempt to close the file */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: If the file is still opened, close it */
        if (data != -1)
        {
            CLOSE(data);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing global_const_t to global_const_f */
static void goodB2G1()
{
    int data;
    /* Initialize data */
    data = -1;
    data = OPEN("BadSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    if(global_const_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: No attempt to close the file */
        ; /* empty statement needed for some flow variants */
    }
    else
    {
        /* FIX: If the file is still opened, close it */
        if (data != -1)
        {
            CLOSE(data);
        }
    }
}

/* goodB2G2() - use badsource and goodsink by reversing statements in if  */
static void goodB2G2()
{
    int data;
    /* Initialize data */
    data = -1;
    data = OPEN("BadSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    if(global_const_t)
    {
        /* FIX: If the file is still opened, close it */
        if (data != -1)
        {
            CLOSE(data);
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW: No attempt to close the file */
        ; /* empty statement needed for some flow variants */
    }
}

void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__open_no_close_09_good()
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
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__open_no_close_09_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__open_no_close_09_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
