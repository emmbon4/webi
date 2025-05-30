/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__char_fromConsole_w32CreateFile_52b.c
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: fromConsole Read input from the console
 * GoodSource: Full path and file name
 * Sink: w32CreateFile
 *    BadSink :
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE36_Absolute_Path_Traversal__char_fromConsole_w32CreateFile_52c_bad_sink(char * data);

void CWE36_Absolute_Path_Traversal__char_fromConsole_w32CreateFile_52b_bad_sink(char * data)
{
    CWE36_Absolute_Path_Traversal__char_fromConsole_w32CreateFile_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE36_Absolute_Path_Traversal__char_fromConsole_w32CreateFile_52c_goodG2B_sink(char * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE36_Absolute_Path_Traversal__char_fromConsole_w32CreateFile_52b_goodG2B_sink(char * data)
{
    CWE36_Absolute_Path_Traversal__char_fromConsole_w32CreateFile_52c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
