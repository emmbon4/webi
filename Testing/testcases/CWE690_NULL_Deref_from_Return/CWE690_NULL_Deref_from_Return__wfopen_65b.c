/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_from_Return__wfopen_65b.c
Label Definition File: CWE690_NULL_Deref_from_Return.fclose.label.xml
Template File: source-sinks-65b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: wfopen Open data with wfopen()
 * Sinks: 0
 *    GoodSink: Check data for NULL
 *    BadSink : Do not check data for NULL
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define WFOPEN _wfopen
#else
/*fopen is used on unix-based OSs */
# define WFOPEN fopen
#endif

#ifndef OMITBAD

void CWE690_NULL_Deref_from_Return__wfopen_65b_bad_sink(FILE * data)
{
    /* FLAW: if the fopen failed, data could be NULL here */
    fclose(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void CWE690_NULL_Deref_from_Return__wfopen_65b_goodB2G_sink(FILE * data)
{
    /* FIX: check the return value */
    if (data != NULL)
    {
        fclose(data);
    }
}

#endif /* OMITGOOD */
