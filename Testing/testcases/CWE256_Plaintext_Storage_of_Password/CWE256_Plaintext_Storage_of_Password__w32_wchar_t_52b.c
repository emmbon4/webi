/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE256_Plaintext_Storage_of_Password__w32_wchar_t_52b.c
Label Definition File: CWE256_Plaintext_Storage_of_Password__w32.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 256 Plaintext Storage of Password
 * BadSource:  Read the password from a file
 * GoodSource: Read the password from the console
 * Sink:
 *    BadSink : Authenticate the user using LogonUserW()
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#include <windows.h>
#pragma comment(lib, "advapi32.lib")
#endif

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE256_Plaintext_Storage_of_Password__w32_wchar_t_52c_bad_sink(wchar_t * password);

void CWE256_Plaintext_Storage_of_Password__w32_wchar_t_52b_bad_sink(wchar_t * password)
{
    CWE256_Plaintext_Storage_of_Password__w32_wchar_t_52c_bad_sink(password);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE256_Plaintext_Storage_of_Password__w32_wchar_t_52c_goodG2B_sink(wchar_t * password);

/* goodG2B uses the GoodSource with the BadSink */
void CWE256_Plaintext_Storage_of_Password__w32_wchar_t_52b_goodG2B_sink(wchar_t * password)
{
    CWE256_Plaintext_Storage_of_Password__w32_wchar_t_52c_goodG2B_sink(password);
}

#endif /* OMITGOOD */
