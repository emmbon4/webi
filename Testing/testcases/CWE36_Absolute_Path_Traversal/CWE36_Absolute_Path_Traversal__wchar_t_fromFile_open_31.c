/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__wchar_t_fromFile_open_31.c
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-31.tmpl.c
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: fromFile Read input from a file
 * GoodSource: Full path and file name
 * Sinks: open
 *    BadSink :
 * Flow Variant: 31 Data flow using a copy of data within the same function
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define FOPEN _wfopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

#ifdef _WIN32
# define OPEN _wopen
# define CLOSE _close
#else
# define OPEN wopen
# define CLOSE close
#endif

#ifndef OMITBAD

void CWE36_Absolute_Path_Traversal__wchar_t_fromFile_open_31_bad()
{
    wchar_t * data;
    wchar_t data_buf[FILENAME_MAX] = L"";
    data = data_buf;
    {
        /* Read input from a file */
        size_t data_len = wcslen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if(FILENAME_MAX-data_len > 1)
        {
            pFile = FOPEN(L"C:\\temp\\file.txt", L"r");
            if (pFile != NULL)
            {
                fgetws(data+data_len, (int)(FILENAME_MAX-data_len), pFile);
                fclose(pFile);
            }
        }
    }
    {
        wchar_t * data_copy = data;
        wchar_t * data = data_copy;
        {
            int fd;
            /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
            fd = OPEN(data, O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
            if (fd != -1)
            {
                CLOSE(fd);
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    wchar_t data_buf[FILENAME_MAX] = L"";
    data = data_buf;
#ifdef _WIN32
    /* FIX: Full path and file name */
    wcscpy(data, L"c:\\temp\\file.txt");
#else
    /* FIX: Full path and file name */
    wcscpy(data, L"/tmp/file.txt");
#endif
    {
        wchar_t * data_copy = data;
        wchar_t * data = data_copy;
        {
            int fd;
            /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
            fd = OPEN(data, O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
            if (fd != -1)
            {
                CLOSE(fd);
            }
        }
    }
}

void CWE36_Absolute_Path_Traversal__wchar_t_fromFile_open_31_good()
{
    goodG2B();
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
    CWE36_Absolute_Path_Traversal__wchar_t_fromFile_open_31_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE36_Absolute_Path_Traversal__wchar_t_fromFile_open_31_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
