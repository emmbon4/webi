/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_wchar_t_fromConsole_68a.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * BadSource: fromConsole Read input from the console
 * GoodSource: Hard code the full pathname to the library
 * Sink:
 *    BadSink : Load a dynamic link library
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#include <windows.h>

wchar_t * CWE114_Process_Control__w32_wchar_t_fromConsole_68_bad_data;
wchar_t * CWE114_Process_Control__w32_wchar_t_fromConsole_68_goodG2B_data;

#ifndef OMITBAD

/* bad function declaration */
void CWE114_Process_Control__w32_wchar_t_fromConsole_68b_bad_sink();

void CWE114_Process_Control__w32_wchar_t_fromConsole_68_bad()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    {
        /* Read input from the console */
        size_t data_len = wcslen(data);
        /* if there is room in data, read into it from the console */
        if(100-data_len > 1)
        {
            fgetws(data+data_len, (int)(100-data_len), stdin);
            /* The next 3 lines remove the carriage return from the string that is
             * inserted by fgetws() */
            data_len = wcslen(data);
            if (data_len > 0)
            {
                data[data_len-1] = L'\0';
            }
        }
    }
    CWE114_Process_Control__w32_wchar_t_fromConsole_68_bad_data = data;
    CWE114_Process_Control__w32_wchar_t_fromConsole_68b_bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE114_Process_Control__w32_wchar_t_fromConsole_68b_goodG2B_sink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    wchar_t data_buf[100] = L"";
    data = data_buf;
    /* FIX: Specify the full pathname for the library */
    wcscpy(data, L"C:\\Windows\\System32\\winsrv.dll");
    CWE114_Process_Control__w32_wchar_t_fromConsole_68_goodG2B_data = data;
    CWE114_Process_Control__w32_wchar_t_fromConsole_68b_goodG2B_sink();
}

void CWE114_Process_Control__w32_wchar_t_fromConsole_68_good()
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
    CWE114_Process_Control__w32_wchar_t_fromConsole_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE114_Process_Control__w32_wchar_t_fromConsole_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
