/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__char_fromConsole_open_68b.c
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: fromConsole Read input from the console
 * GoodSource: File name without a period or slash
 * Sink: open
 *    BadSink :
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define BASEPATH "c:\\temp\\"
#else
#define BASEPATH "/tmp/"
#endif

#ifdef _WIN32
# define OPEN _open
# define CLOSE _close
#else
# define OPEN open
# define CLOSE close
#endif

extern char * CWE23_Relative_Path_Traversal__char_fromConsole_open_68_bad_data;
extern char * CWE23_Relative_Path_Traversal__char_fromConsole_open_68_goodG2B_data;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void CWE23_Relative_Path_Traversal__char_fromConsole_open_68b_bad_sink()
{
    char * data = CWE23_Relative_Path_Traversal__char_fromConsole_open_68_bad_data;
    {
        int fd;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        fd = OPEN(data, O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
        if (fd != -1)
        {
            CLOSE(fd);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE23_Relative_Path_Traversal__char_fromConsole_open_68b_goodG2B_sink()
{
    char * data = CWE23_Relative_Path_Traversal__char_fromConsole_open_68_goodG2B_data;
    {
        int fd;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        fd = OPEN(data, O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
        if (fd != -1)
        {
            CLOSE(fd);
        }
    }
}

#endif /* OMITGOOD */
