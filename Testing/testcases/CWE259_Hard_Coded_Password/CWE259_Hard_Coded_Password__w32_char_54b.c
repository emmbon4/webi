/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE259_Hard_Coded_Password__w32_char_54b.c
Label Definition File: CWE259_Hard_Coded_Password__w32.label.xml
Template File: sources-sink-54b.tmpl.c
*/
/*
 * @description
 * CWE: 259 Use of Hard-coded Password
 * BadSource:  Use a hardcoded password
 * GoodSource: Read the password from the console
 * Sink:
 *    BadSink : Authenticate the user using LogonUserA()
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#define PASSWORD_SZ 100

#define PASSWORD "ABCD1234!"

#ifdef _WIN32
#include <windows.h>
#pragma comment(lib, "advapi32.lib")
#endif

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE259_Hard_Coded_Password__w32_char_54c_bad_sink(char * password);

void CWE259_Hard_Coded_Password__w32_char_54b_bad_sink(char * password)
{
    CWE259_Hard_Coded_Password__w32_char_54c_bad_sink(password);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE259_Hard_Coded_Password__w32_char_54c_goodG2B_sink(char * password);

/* goodG2B uses the GoodSource with the BadSink */
void CWE259_Hard_Coded_Password__w32_char_54b_goodG2B_sink(char * password)
{
    CWE259_Hard_Coded_Password__w32_char_54c_goodG2B_sink(password);
}

#endif /* OMITGOOD */
