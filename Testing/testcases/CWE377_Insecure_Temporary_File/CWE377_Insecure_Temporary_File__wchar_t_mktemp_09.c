/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE377_Insecure_Temporary_File__wchar_t_mktemp_09.c
Label Definition File: CWE377_Insecure_Temporary_File.label.xml
Template File: point-flaw-09.tmpl.c
*/
/*
 * @description
 * CWE: 377 Insecure Temporary File
 * Sinks: mktemp
 *    GoodSink: Create and open a temporary file, created with _wmktemp(), insecurely
 *    BadSink : Create and open a temporary file, created with _wmktemp(), insecurely
 * Flow Variant: 09 Control flow: if(global_const_t) and if(global_const_f)
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

#ifndef OMITBAD

void CWE377_Insecure_Temporary_File__wchar_t_mktemp_09_bad()
{
    if(global_const_t)
    {
        {
            wchar_t * filename;
            wchar_t * template = L"fnXXXXXX";
            FILE * tmp;
            filename = _wmktemp(template);
            printWLine(filename);
            /* FLAW: Use an incorrect method for opening the temporary file */
            tmp = _wfopen(filename, L"wb+");
            if (tmp != NULL)
            {
                printLine("Temporary file was opened...now closing file");
                fclose(tmp);
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t * filename;
            wchar_t * template = L"fnXXXXXX";
            int fd;
            filename = _wmktemp(template);
            printWLine(filename);
            /* FIX: Open a temporary file using open() and the O_CREAT and O_EXCL flags
             * NOTE: This is not a perfect solution, but it is the base case scenario */
            fd = OPEN(filename, O_CREAT|O_EXCL, S_IREAD|S_IWRITE);
            if (fd != -1)
            {
                printLine("Temporary file was opened...now closing file");
                CLOSE(fd);
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(global_const_f) instead of if(global_const_t) */
static void good1()
{
    if(global_const_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t * filename;
            wchar_t * template = L"fnXXXXXX";
            FILE * tmp;
            filename = _wmktemp(template);
            printWLine(filename);
            /* FLAW: Use an incorrect method for opening the temporary file */
            tmp = _wfopen(filename, L"wb+");
            if (tmp != NULL)
            {
                printLine("Temporary file was opened...now closing file");
                fclose(tmp);
            }
        }
    }
    else
    {
        {
            wchar_t * filename;
            wchar_t * template = L"fnXXXXXX";
            int fd;
            filename = _wmktemp(template);
            printWLine(filename);
            /* FIX: Open a temporary file using open() and the O_CREAT and O_EXCL flags
             * NOTE: This is not a perfect solution, but it is the base case scenario */
            fd = OPEN(filename, O_CREAT|O_EXCL, S_IREAD|S_IWRITE);
            if (fd != -1)
            {
                printLine("Temporary file was opened...now closing file");
                CLOSE(fd);
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(global_const_t)
    {
        {
            wchar_t * filename;
            wchar_t * template = L"fnXXXXXX";
            int fd;
            filename = _wmktemp(template);
            printWLine(filename);
            /* FIX: Open a temporary file using open() and the O_CREAT and O_EXCL flags
             * NOTE: This is not a perfect solution, but it is the base case scenario */
            fd = OPEN(filename, O_CREAT|O_EXCL, S_IREAD|S_IWRITE);
            if (fd != -1)
            {
                printLine("Temporary file was opened...now closing file");
                CLOSE(fd);
            }
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
            wchar_t * filename;
            wchar_t * template = L"fnXXXXXX";
            FILE * tmp;
            filename = _wmktemp(template);
            printWLine(filename);
            /* FLAW: Use an incorrect method for opening the temporary file */
            tmp = _wfopen(filename, L"wb+");
            if (tmp != NULL)
            {
                printLine("Temporary file was opened...now closing file");
                fclose(tmp);
            }
        }
    }
}

void CWE377_Insecure_Temporary_File__wchar_t_mktemp_09_good()
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
    CWE377_Insecure_Temporary_File__wchar_t_mktemp_09_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE377_Insecure_Temporary_File__wchar_t_mktemp_09_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
