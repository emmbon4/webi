/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__wchar_t_fromConsole_open_67b.c
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: fromConsole Read input from the console
 * GoodSource: Full path and file name
 * Sinks: open
 *    BadSink :
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define OPEN _wopen
# define CLOSE _close
#else
# define OPEN wopen
# define CLOSE close
#endif

typedef struct _CWE36_Absolute_Path_Traversal__wchar_t_fromConsole_open_67_struct_type
{
    wchar_t * a;
} CWE36_Absolute_Path_Traversal__wchar_t_fromConsole_open_67_struct_type;

#ifndef OMITBAD

void CWE36_Absolute_Path_Traversal__wchar_t_fromConsole_open_67b_bad_sink(CWE36_Absolute_Path_Traversal__wchar_t_fromConsole_open_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
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
void CWE36_Absolute_Path_Traversal__wchar_t_fromConsole_open_67b_goodG2B_sink(CWE36_Absolute_Path_Traversal__wchar_t_fromConsole_open_67_struct_type my_struct)
{
    wchar_t * data = my_struct.a;
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
