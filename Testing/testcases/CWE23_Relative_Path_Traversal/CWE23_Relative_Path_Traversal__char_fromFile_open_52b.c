/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__char_fromFile_open_52b.c
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: fromFile Read input from a file
 * GoodSource: File name without a period or slash
 * Sink: open
 *    BadSink :
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define BASEPATH "c:\\temp\\"
#else
#define BASEPATH "/tmp/"
#endif

#ifdef _WIN32
# define FOPEN fopen
#else
/* fopen is used on unix-based OSs */
# define FOPEN fopen
#endif

#ifdef _WIN32
# define OPEN _open
# define CLOSE _close
#else
# define OPEN open
# define CLOSE close
#endif

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE23_Relative_Path_Traversal__char_fromFile_open_52c_bad_sink(char * data);

void CWE23_Relative_Path_Traversal__char_fromFile_open_52b_bad_sink(char * data)
{
    CWE23_Relative_Path_Traversal__char_fromFile_open_52c_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE23_Relative_Path_Traversal__char_fromFile_open_52c_goodG2B_sink(char * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE23_Relative_Path_Traversal__char_fromFile_open_52b_goodG2B_sink(char * data)
{
    CWE23_Relative_Path_Traversal__char_fromFile_open_52c_goodG2B_sink(data);
}

#endif /* OMITGOOD */
