/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE377_Insecure_Temporary_File__char_mktemp_19.c
Label Definition File: CWE377_Insecure_Temporary_File.label.xml
Template File: point-flaw-19.tmpl.c
*/
/*
 * @description
 * CWE: 377 Insecure Temporary File
 * Sinks: mktemp
 *    GoodSink: Create and open a temporary file, created with mktemp(), insecurely
 *    BadSink : Create and open a temporary file, created with mktemp(), insecurely
 * Flow Variant: 19 Control flow: Dead code after a return
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

void CWE377_Insecure_Temporary_File__char_mktemp_19_bad()
{
    {
        char * filename;
        char * template = "fnXXXXXX";
        FILE * tmp;
        filename = mktemp(template);
        printLine(filename);
        /* FLAW: Use an incorrect method for opening the temporary file */
        tmp = fopen(filename, "wb+");
        if (tmp != NULL)
        {
            printLine("Temporary file was opened...now closing file");
            fclose(tmp);
        }
    }
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char * filename;
        char * template = "fnXXXXXX";
        int fd;
        filename = mktemp(template);
        printLine(filename);
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

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() reverses the GoodSinkBody and the BadSinkBody so that the BadSinkBody never runs */
static void good1()
{
    {
        char * filename;
        char * template = "fnXXXXXX";
        int fd;
        filename = mktemp(template);
        printLine(filename);
        /* FIX: Open a temporary file using open() and the O_CREAT and O_EXCL flags
         * NOTE: This is not a perfect solution, but it is the base case scenario */
        fd = OPEN(filename, O_CREAT|O_EXCL, S_IREAD|S_IWRITE);
        if (fd != -1)
        {
            printLine("Temporary file was opened...now closing file");
            CLOSE(fd);
        }
    }
    return;
    /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
    {
        char * filename;
        char * template = "fnXXXXXX";
        FILE * tmp;
        filename = mktemp(template);
        printLine(filename);
        /* FLAW: Use an incorrect method for opening the temporary file */
        tmp = fopen(filename, "wb+");
        if (tmp != NULL)
        {
            printLine("Temporary file was opened...now closing file");
            fclose(tmp);
        }
    }
}

void CWE377_Insecure_Temporary_File__char_mktemp_19_good()
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
    CWE377_Insecure_Temporary_File__char_mktemp_19_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE377_Insecure_Temporary_File__char_mktemp_19_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
