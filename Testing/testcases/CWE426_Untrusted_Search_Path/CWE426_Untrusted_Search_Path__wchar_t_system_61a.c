/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE426_Untrusted_Search_Path__wchar_t_system_61a.c
Label Definition File: CWE426_Untrusted_Search_Path.label.xml
Template File: sources-sink-61a.tmpl.c
*/
/*
 * @description
 * CWE: 426 Untrusted Search Path
 * BadSource:  Don't specify the full path in the OS command
 * GoodSource: Specify the full path in the OS command
 * Sinks: system
 *    BadSink : Execute the _wsystem function
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
# define BAD_OS_COMMAND L"cmd.exe /c dir"

/* REVIEWERS NOTE:
 * This hard-coded path is probably incorrect for Windows systems, as it will
 * function improperly on 9x/NT/2K, possibly on XP+ systems upgraded from 2K,
 * and could introduce code execution vulnerabilities on Windows systems that
 * have a system drive on an alternate drive letter (e.g., d:\windows)
 */
# define GOOD_OS_COMMAND L"c:\\windows\\system32\\cmd.exe /c dir"
#else /* NOT _WIN32 */
# define BAD_OS_COMMAND L"ls -la"
# define GOOD_OS_COMMAND L"/usr/bin/ls -la"
#endif /* end NOT _WIN32 */

#ifndef OMITBAD

/* bad function declaration */
wchar_t * CWE426_Untrusted_Search_Path__wchar_t_system_61b_bad_source(wchar_t * data);

void CWE426_Untrusted_Search_Path__wchar_t_system_61_bad()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    data = CWE426_Untrusted_Search_Path__wchar_t_system_61b_bad_source(data);
    /* POTENTIAL FLAW: Executing the _wsystem() function without specifying the full path to the executable
     * can allow an attacker to run their own program */
    _wsystem(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
wchar_t * CWE426_Untrusted_Search_Path__wchar_t_system_61b_goodG2B_source(wchar_t * data);

static void goodG2B()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    data = CWE426_Untrusted_Search_Path__wchar_t_system_61b_goodG2B_source(data);
    /* POTENTIAL FLAW: Executing the _wsystem() function without specifying the full path to the executable
     * can allow an attacker to run their own program */
    _wsystem(data);
}

void CWE426_Untrusted_Search_Path__wchar_t_system_61_good()
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
    CWE426_Untrusted_Search_Path__wchar_t_system_61_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE426_Untrusted_Search_Path__wchar_t_system_61_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
