/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE390_Error_Without_Action__wchar_t_fopen_02.c
Label Definition File: CWE390_Error_Without_Action.string.label.xml
Template File: point-flaw-02.tmpl.c
*/
/*
 * @description
 * CWE: 390 Detection of Error Condition Without Action
 * Sinks: fopen
 *    GoodSink: Check to see if _wfopen() failed, and handle errors properly
 *    BadSink : Check to see if _wfopen() failed, but fail to handle errors
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE390_Error_Without_Action__wchar_t_fopen_02_bad()
{
    if(1)
    {
        {
            FILE * file_ptr = _wfopen(L"file.txt", L"w+");
            /* FLAW: Check to see if _wfopen() failed, but do nothing about it */
            if (file_ptr == NULL)
            {
                /* do nothing */
            }
            if (fputws(L"Write something to the file", stdout) == WEOF)
            {
                printLine("fputws failed!");
                exit(1);
            }
            if (file_ptr != NULL)
            {
                fclose(file_ptr);
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            FILE * file_ptr = _wfopen(L"file.txt", L"w+");
            /* FIX: Check to see if _wfopen() failed and handle errors properly */
            if (file_ptr == NULL)
            {
                printLine("The file failed to open");
                exit(1);
            }
            if (fputws(L"Write something to the file", stdout) == WEOF)
            {
                printLine("fputws failed!");
                exit(1);
            }
            if (file_ptr != NULL)
            {
                fclose(file_ptr);
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(0) instead of if(1) */
static void good1()
{
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            FILE * file_ptr = _wfopen(L"file.txt", L"w+");
            /* FLAW: Check to see if _wfopen() failed, but do nothing about it */
            if (file_ptr == NULL)
            {
                /* do nothing */
            }
            if (fputws(L"Write something to the file", stdout) == WEOF)
            {
                printLine("fputws failed!");
                exit(1);
            }
            if (file_ptr != NULL)
            {
                fclose(file_ptr);
            }
        }
    }
    else
    {
        {
            FILE * file_ptr = _wfopen(L"file.txt", L"w+");
            /* FIX: Check to see if _wfopen() failed and handle errors properly */
            if (file_ptr == NULL)
            {
                printLine("The file failed to open");
                exit(1);
            }
            if (fputws(L"Write something to the file", stdout) == WEOF)
            {
                printLine("fputws failed!");
                exit(1);
            }
            if (file_ptr != NULL)
            {
                fclose(file_ptr);
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(1)
    {
        {
            FILE * file_ptr = _wfopen(L"file.txt", L"w+");
            /* FIX: Check to see if _wfopen() failed and handle errors properly */
            if (file_ptr == NULL)
            {
                printLine("The file failed to open");
                exit(1);
            }
            if (fputws(L"Write something to the file", stdout) == WEOF)
            {
                printLine("fputws failed!");
                exit(1);
            }
            if (file_ptr != NULL)
            {
                fclose(file_ptr);
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            FILE * file_ptr = _wfopen(L"file.txt", L"w+");
            /* FLAW: Check to see if _wfopen() failed, but do nothing about it */
            if (file_ptr == NULL)
            {
                /* do nothing */
            }
            if (fputws(L"Write something to the file", stdout) == WEOF)
            {
                printLine("fputws failed!");
                exit(1);
            }
            if (file_ptr != NULL)
            {
                fclose(file_ptr);
            }
        }
    }
}

void CWE390_Error_Without_Action__wchar_t_fopen_02_good()
{
    good1();
    good2();
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
    CWE390_Error_Without_Action__wchar_t_fopen_02_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE390_Error_Without_Action__wchar_t_fopen_02_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
