/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE377_Insecure_Temporary_File__wchar_t_tempnam_07.c
Label Definition File: CWE377_Insecure_Temporary_File.label.xml
Template File: point-flaw-07.tmpl.c
*/
/*
 * @description
 * CWE: 377 Insecure Temporary File
 * Sinks: tempnam
 *    GoodSink: Create and open a temporary file, created with _wtempnam(), more securely
 *    BadSink : Create and open a temporary file, created with _wtempnam(), insecurely
 * Flow Variant: 07 Control flow: if(static_five==5) and if(static_five!=5)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
# define OPEN _wopen
# define CLOSE _close
# define FOPEN _wfopen
#else
# define OPEN wopen
# define CLOSE close
# define FOPEN fopen
#endif

/* The variable below is not declared "const", but is never assigned
   any other value so a tool should be able to identify that reads of
   this will always give its initialized value. */
static int static_five = 5;

#ifndef OMITBAD

void CWE377_Insecure_Temporary_File__wchar_t_tempnam_07_bad()
{
    if(static_five==5)
    {
        {
            wchar_t * filename;
            FILE * tmp;
            filename = _wtempnam(NULL, NULL);
            printWLine(filename);
            /* FLAW: Use an incorrect method for opening the temporary file */
            tmp = _wfopen(filename, L"wb+");
            if (tmp != NULL)
            {
                printLine("Temporary file was opened...now closing file");
                fclose(tmp);
            }
            if (filename != NULL)
            {
                free(filename);
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t * filename;
            int fd;
            filename = _wtempnam(NULL, NULL);
            printWLine(filename);
            /* FIX: Open a temporary file using open() and the O_CREAT and O_EXCL flags
             * NOTE: This is not a perfect solution, but it is the base case scenario */
            fd = OPEN(filename, O_CREAT|O_EXCL, S_IREAD|S_IWRITE);
            if (fd != -1)
            {
                printLine("Temporary file was opened...now closing file");
                CLOSE(fd);
            }
            if (filename != NULL)
            {
                free(filename);
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(static_five!=5) instead of if(static_five==5) */
static void good1()
{
    if(static_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t * filename;
            FILE * tmp;
            filename = _wtempnam(NULL, NULL);
            printWLine(filename);
            /* FLAW: Use an incorrect method for opening the temporary file */
            tmp = _wfopen(filename, L"wb+");
            if (tmp != NULL)
            {
                printLine("Temporary file was opened...now closing file");
                fclose(tmp);
            }
            if (filename != NULL)
            {
                free(filename);
            }
        }
    }
    else
    {
        {
            wchar_t * filename;
            int fd;
            filename = _wtempnam(NULL, NULL);
            printWLine(filename);
            /* FIX: Open a temporary file using open() and the O_CREAT and O_EXCL flags
             * NOTE: This is not a perfect solution, but it is the base case scenario */
            fd = OPEN(filename, O_CREAT|O_EXCL, S_IREAD|S_IWRITE);
            if (fd != -1)
            {
                printLine("Temporary file was opened...now closing file");
                CLOSE(fd);
            }
            if (filename != NULL)
            {
                free(filename);
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(static_five==5)
    {
        {
            wchar_t * filename;
            int fd;
            filename = _wtempnam(NULL, NULL);
            printWLine(filename);
            /* FIX: Open a temporary file using open() and the O_CREAT and O_EXCL flags
             * NOTE: This is not a perfect solution, but it is the base case scenario */
            fd = OPEN(filename, O_CREAT|O_EXCL, S_IREAD|S_IWRITE);
            if (fd != -1)
            {
                printLine("Temporary file was opened...now closing file");
                CLOSE(fd);
            }
            if (filename != NULL)
            {
                free(filename);
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t * filename;
            FILE * tmp;
            filename = _wtempnam(NULL, NULL);
            printWLine(filename);
            /* FLAW: Use an incorrect method for opening the temporary file */
            tmp = _wfopen(filename, L"wb+");
            if (tmp != NULL)
            {
                printLine("Temporary file was opened...now closing file");
                fclose(tmp);
            }
            if (filename != NULL)
            {
                free(filename);
            }
        }
    }
}

void CWE377_Insecure_Temporary_File__wchar_t_tempnam_07_good()
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
    CWE377_Insecure_Temporary_File__wchar_t_tempnam_07_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE377_Insecure_Temporary_File__wchar_t_tempnam_07_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
