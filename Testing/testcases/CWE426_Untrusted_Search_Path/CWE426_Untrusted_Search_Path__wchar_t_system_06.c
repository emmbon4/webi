/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE426_Untrusted_Search_Path__wchar_t_system_06.c
Label Definition File: CWE426_Untrusted_Search_Path.label.xml
Template File: sources-sink-06.tmpl.c
*/
/*
 * @description
 * CWE: 426 Untrusted Search Path
 * BadSource:  Don't specify the full path in the OS command
 * GoodSource: Specify the full path in the OS command
 * Sink: system
 *    BadSink : Execute the _wsystem function
 * Flow Variant: 06 Control flow: if(static_const_five==5) and if(static_const_five!=5)
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

/* The variable below is declared "const", so a tool should be able
   to identify that reads of this will always give its initialized
   value. */
static const int static_const_five = 5;

#ifndef OMITBAD

void CWE426_Untrusted_Search_Path__wchar_t_system_06_bad()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    if(static_const_five==5)
    {
        /* FLAW - the full path is not specified */
        wcscpy(data, BAD_OS_COMMAND);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX - full path is specified */
        wcscpy(data, GOOD_OS_COMMAND);
    }
    /* POTENTIAL FLAW: Executing the _wsystem() function without specifying the full path to the executable
     * can allow an attacker to run their own program */
    _wsystem(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the static_const_five==5 to static_const_five!=5 */
static void goodG2B1()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    if(static_const_five!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW - the full path is not specified */
        wcscpy(data, BAD_OS_COMMAND);
    }
    else
    {
        /* FIX - full path is specified */
        wcscpy(data, GOOD_OS_COMMAND);
    }
    /* POTENTIAL FLAW: Executing the _wsystem() function without specifying the full path to the executable
     * can allow an attacker to run their own program */
    _wsystem(data);
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    if(static_const_five==5)
    {
        /* FIX - full path is specified */
        wcscpy(data, GOOD_OS_COMMAND);
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FLAW - the full path is not specified */
        wcscpy(data, BAD_OS_COMMAND);
    }
    /* POTENTIAL FLAW: Executing the _wsystem() function without specifying the full path to the executable
     * can allow an attacker to run their own program */
    _wsystem(data);
}

void CWE426_Untrusted_Search_Path__wchar_t_system_06_good()
{
    goodG2B1();
    goodG2B2();
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
    CWE426_Untrusted_Search_Path__wchar_t_system_06_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE426_Untrusted_Search_Path__wchar_t_system_06_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
