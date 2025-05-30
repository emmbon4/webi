/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE377_Insecure_Temporary_File__char_w32GetTempFileName_17.c
Label Definition File: CWE377_Insecure_Temporary_File.label.xml
Template File: point-flaw-17.tmpl.c
*/
/*
 * @description
 * CWE: 377 Insecure Temporary File
 * Sinks: w32GetTempFileName
 *    GoodSink: Create and open a temporary file, created with GetTempFileNameA(), insecurely
 *    BadSink : Create and open a temporary file, created with GetTempFileNameA(), insecurely
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#include <windows.h>

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

void CWE377_Insecure_Temporary_File__char_w32GetTempFileName_17_bad()
{
    int j,k;
    for(j = 0; j < 1; j++)
    {
        {
            char filename[MAX_PATH] = "";
            FILE * tmp;
            if (GetTempFileNameA(".", NULL, 0, filename) == 0)
            {
                exit(1);
            }
            printLine(filename);
            /* FLAW: Use an incorrect method for opening the temporary file */
            tmp = fopen(filename, "wb+");
            if (tmp != NULL) fclose(tmp);
        }
    }
    for(k = 0; k < 0; k++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char filename[MAX_PATH] = "";
            int fd;
            if (GetTempFileNameA(".", NULL, 0, filename) == 0)
            {
                exit(1);
            }
            printLine(filename);
            /* FIX: Open a temporary file using open() and the O_CREAT and O_EXCL flags
             * NOTE: This is not a perfect solution, but it is the base case scenario */
            fd = OPEN(filename, O_CREAT|O_EXCL, S_IREAD|S_IWRITE);
            if (fd != -1)
            {
                printLine("Temporary file opened successfully");
                CLOSE(fd);
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() changes the conditions on the for statements */
static void good1()
{
    int j,k;
    for(j = 0; j < 0; j++)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            char filename[MAX_PATH] = "";
            FILE * tmp;
            if (GetTempFileNameA(".", NULL, 0, filename) == 0)
            {
                exit(1);
            }
            printLine(filename);
            /* FLAW: Use an incorrect method for opening the temporary file */
            tmp = fopen(filename, "wb+");
            if (tmp != NULL) fclose(tmp);
        }
    }
    for(k = 0; k < 1; k++)
    {
        {
            char filename[MAX_PATH] = "";
            int fd;
            if (GetTempFileNameA(".", NULL, 0, filename) == 0)
            {
                exit(1);
            }
            printLine(filename);
            /* FIX: Open a temporary file using open() and the O_CREAT and O_EXCL flags
             * NOTE: This is not a perfect solution, but it is the base case scenario */
            fd = OPEN(filename, O_CREAT|O_EXCL, S_IREAD|S_IWRITE);
            if (fd != -1)
            {
                printLine("Temporary file opened successfully");
                CLOSE(fd);
            }
        }
    }
}

void CWE377_Insecure_Temporary_File__char_w32GetTempFileName_17_good()
{
    good1();
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
    CWE377_Insecure_Temporary_File__char_w32GetTempFileName_17_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE377_Insecure_Temporary_File__char_w32GetTempFileName_17_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
