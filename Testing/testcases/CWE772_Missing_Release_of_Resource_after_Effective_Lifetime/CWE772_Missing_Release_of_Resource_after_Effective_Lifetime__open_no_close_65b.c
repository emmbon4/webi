/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__open_no_close_65b.c
Label Definition File: CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__open_no_close.label.xml
Template File: source-sinks-65b.tmpl.c
*/
/*
 * @description
 * CWE: 772 Missing Release of Resource after Effective Lifetime
 * BadSource:  Open a file using open()
 * Sinks:
 *    GoodSink: Close the file using close()
 *    BadSink : Do not close file
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define OPEN _open
# define CLOSE _close
#else
# define OPEN open
# define CLOSE close
#endif

#ifndef OMITBAD

void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__open_no_close_65b_bad_sink(int data)
{
    /* FLAW: No attempt to close the file */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE772_Missing_Release_of_Resource_after_Effective_Lifetime__open_no_close_65b_goodB2G_sink(int data)
{
    /* FIX: If the file is still opened, close it */
    if (data != -1)
    {
        CLOSE(data);
    }
}

#endif /* OMITGOOD */
