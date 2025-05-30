/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE377_Insecure_Temporary_File__char_tmpnam_02.c
Label Definition File: CWE377_Insecure_Temporary_File.label.xml
Template File: point-flaw-02.tmpl.c
*/
/*
 * @description
 * CWE: 377 Insecure Temporary File
 * Sinks: tmpnam
 *    GoodSink: Create and open a temporary file, created with tmpnam(), more securely
 *    BadSink : Create and open a temporary file, created with tmpnam(), insecurely
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
# define OPEN _open
# define CLOSE _close
# define FOPEN fopen
#else
# define OPEN open
# define CLOSE close
# define FOPEN fopen
#endif

#ifndef OMITBAD

void CWE377_Insecure_Temporary_File__char_tmpnam_02_bad()
{
    if(1)
    {
        {
            char * filename;
            FILE * tmp;
            filename = tmpnam(NULL);
            printLine(filename);
            /* FLAW: Use an incorrect method for opening the temporary file */
            tmp = fopen(filename, "wb+");
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
            char * filename;
            int fd;
            filename = tmpnam(NULL);
            printLine(filename);
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

/* good1() uses if(0) instead of if(1) */
static void good1()
{
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char * filename;
            FILE * tmp;
            filename = tmpnam(NULL);
            printLine(filename);
            /* FLAW: Use an incorrect method for opening the temporary file */
            tmp = fopen(filename, "wb+");
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
            char * filename;
            int fd;
            filename = tmpnam(NULL);
            printLine(filename);
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
    if(1)
    {
        {
            char * filename;
            int fd;
            filename = tmpnam(NULL);
            printLine(filename);
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
            char * filename;
            FILE * tmp;
            filename = tmpnam(NULL);
            printLine(filename);
            /* FLAW: Use an incorrect method for opening the temporary file */
            tmp = fopen(filename, "wb+");
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

void CWE377_Insecure_Temporary_File__char_tmpnam_02_good()
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
    CWE377_Insecure_Temporary_File__char_tmpnam_02_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE377_Insecure_Temporary_File__char_tmpnam_02_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
