/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__open_68b.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource__open.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource:  Open and close a file using open() and close()
 * GoodSource: Open a file using open()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
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

extern int CWE675_Duplicate_Operations_on_Resource__open_68_bad_data;
extern int CWE675_Duplicate_Operations_on_Resource__open_68_goodG2B_data;
extern int CWE675_Duplicate_Operations_on_Resource__open_68_goodB2G_data;

#ifndef OMITBAD

void CWE675_Duplicate_Operations_on_Resource__open_68b_bad_sink()
{
    int data = CWE675_Duplicate_Operations_on_Resource__open_68_bad_data;
    /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
    CLOSE(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE675_Duplicate_Operations_on_Resource__open_68b_goodG2B_sink()
{
    int data = CWE675_Duplicate_Operations_on_Resource__open_68_goodG2B_data;
    /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
    CLOSE(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE675_Duplicate_Operations_on_Resource__open_68b_goodB2G_sink()
{
    int data = CWE675_Duplicate_Operations_on_Resource__open_68_goodB2G_data;
    /* Do nothing */
    /* FIX: Don't close the file in the sink */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITGOOD */
