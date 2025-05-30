/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE426_Untrusted_Search_Path__char_popen_32.c
Label Definition File: CWE426_Untrusted_Search_Path.label.xml
Template File: sources-sink-32.tmpl.c
*/
/*
 * @description
 * CWE: 426 Untrusted Search Path
 * BadSource:  Don't specify the full path in the OS command
 * GoodSource: Specify the full path in the OS command
 * Sink: popen
 *    BadSink : Execute the popen function
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
# define BAD_OS_COMMAND "cmd.exe /c dir"

/* REVIEWERS NOTE:
 * This hard-coded path is probably incorrect for Windows systems, as it will
 * function improperly on 9x/NT/2K, possibly on XP+ systems upgraded from 2K,
 * and could introduce code execution vulnerabilities on Windows systems that
 * have a system drive on an alternate drive letter (e.g., d:\windows)
 */
# define GOOD_OS_COMMAND "c:\\windows\\system32\\cmd.exe /c dir"
#else /* NOT _WIN32 */
# define BAD_OS_COMMAND "ls -la"
# define GOOD_OS_COMMAND "/usr/bin/ls -la"
#endif /* end NOT _WIN32 */

/* define POPEN as _popen on Windows and popen otherwise */
#ifdef _WIN32
# define POPEN _popen
# define PCLOSE _pclose
#else /* NOT _WIN32 */
# define POPEN popen
# define PCLOSE pclose
#endif

#ifndef OMITBAD

void CWE426_Untrusted_Search_Path__char_popen_32_bad()
{
    char * data;
    char * *data_ptr1 = &data;
    char * *data_ptr2 = &data;
    char data_buf[100] = "";
    data = data_buf;
    {
        char * data = *data_ptr1;
        /* FLAW - the full path is not specified */
        strcpy(data, BAD_OS_COMMAND);
        *data_ptr1 = data;
    }
    {
        char * data = *data_ptr2;
        {
            FILE *pipe;
            /* POTENTIAL FLAW: Executing the popen() function without specifying the full path to the executable
             * can allow an attacker to run their own program */
            pipe = POPEN(data, "wb");
            if (pipe != NULL) PCLOSE(pipe);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    char * *data_ptr1 = &data;
    char * *data_ptr2 = &data;
    char data_buf[100] = "";
    data = data_buf;
    {
        char * data = *data_ptr1;
        /* FIX - full path is specified */
        strcpy(data, GOOD_OS_COMMAND);
        *data_ptr1 = data;
    }
    {
        char * data = *data_ptr2;
        {
            FILE *pipe;
            /* POTENTIAL FLAW: Executing the popen() function without specifying the full path to the executable
             * can allow an attacker to run their own program */
            pipe = POPEN(data, "wb");
            if (pipe != NULL) PCLOSE(pipe);
        }
    }
}

void CWE426_Untrusted_Search_Path__char_popen_32_good()
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
    CWE426_Untrusted_Search_Path__char_popen_32_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE426_Untrusted_Search_Path__char_popen_32_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
