/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE426_Untrusted_Search_Path__char_popen_67b.c
Label Definition File: CWE426_Untrusted_Search_Path.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 426 Untrusted Search Path
 * BadSource:  Don't specify the full path in the OS command
 * GoodSource: Specify the full path in the OS command
 * Sinks: popen
 *    BadSink : Execute the popen function
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
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

typedef struct _CWE426_Untrusted_Search_Path__char_popen_67_struct_type
{
    char * a;
} CWE426_Untrusted_Search_Path__char_popen_67_struct_type;

#ifndef OMITBAD

void CWE426_Untrusted_Search_Path__char_popen_67b_bad_sink(CWE426_Untrusted_Search_Path__char_popen_67_struct_type my_struct)
{
    char * data = my_struct.a;
    {
        FILE *pipe;
        /* POTENTIAL FLAW: Executing the popen() function without specifying the full path to the executable
         * can allow an attacker to run their own program */
        pipe = POPEN(data, "wb");
        if (pipe != NULL) PCLOSE(pipe);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE426_Untrusted_Search_Path__char_popen_67b_goodG2B_sink(CWE426_Untrusted_Search_Path__char_popen_67_struct_type my_struct)
{
    char * data = my_struct.a;
    {
        FILE *pipe;
        /* POTENTIAL FLAW: Executing the popen() function without specifying the full path to the executable
         * can allow an attacker to run their own program */
        pipe = POPEN(data, "wb");
        if (pipe != NULL) PCLOSE(pipe);
    }
}

#endif /* OMITGOOD */
