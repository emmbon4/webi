/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_53c.c
Label Definition File: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32.label.xml
Template File: sources-sink-53c.tmpl.c
*/
/*
 * @description
 * CWE: 591 Sensitive Data Storage in Improperly Locked Memory
 * BadSource:  Allocate memory for sensitive data and use VirtualLock() to lock the buffer into memory
 * GoodSource: Allocate memory for sensitive data and use VirtualLock() to lock the buffer into memory
 * Sink:
 *    BadSink : Authenticate the user using LogonUserW()
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#ifdef _WIN32
#include <windows.h>
#endif

#ifdef _WIN32
#pragma comment(lib, "advapi32.lib")
#endif

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_53d_bad_sink(wchar_t * password);

void CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_53c_bad_sink(wchar_t * password)
{
    CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_53d_bad_sink(password);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_53d_goodG2B_sink(wchar_t * password);

/* goodG2B uses the GoodSource with the BadSink */
void CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_53c_goodG2B_sink(wchar_t * password)
{
    CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_53d_goodG2B_sink(password);
}

#endif /* OMITGOOD */
