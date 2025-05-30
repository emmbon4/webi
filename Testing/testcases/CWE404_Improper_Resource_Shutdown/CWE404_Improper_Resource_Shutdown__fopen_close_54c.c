/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__fopen_close_54c.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-54c.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource: fopen Open a file using fopen()
 * Sinks: close
 *    GoodSink: Close the file using fclose()
 *    BadSink : Close the file using close()
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define CLOSE _close
#else
# define CLOSE close
#endif

#ifndef OMITBAD

/* bad function declaration */
void CWE404_Improper_Resource_Shutdown__fopen_close_54d_bad_sink(FILE * data);

void CWE404_Improper_Resource_Shutdown__fopen_close_54c_bad_sink(FILE * data)
{
    CWE404_Improper_Resource_Shutdown__fopen_close_54d_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE404_Improper_Resource_Shutdown__fopen_close_54d_goodB2G_sink(FILE * data);

void CWE404_Improper_Resource_Shutdown__fopen_close_54c_goodB2G_sink(FILE * data)
{
    CWE404_Improper_Resource_Shutdown__fopen_close_54d_goodB2G_sink(data);
}

#endif /* OMITGOOD */
