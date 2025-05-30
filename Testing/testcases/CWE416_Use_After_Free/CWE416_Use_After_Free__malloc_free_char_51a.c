/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__malloc_free_char_51a.c
Label Definition File: CWE416_Use_After_Free__malloc_free.label.xml
Template File: sources-sinks-51a.tmpl.c
*/
/*
 * @description
 * CWE: 416 Use After Free
 * BadSource:  Allocate data using malloc(), initialize memory block, and Deallocate data using free()
 * GoodSource: Allocate data using malloc() and initialize memory block
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Use data
 * Flow Variant: 51 Data flow: data passed as an argument from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE416_Use_After_Free__malloc_free_char_51b_bad_sink(char * data);

void CWE416_Use_After_Free__malloc_free_char_51_bad()
{
    char * data;
    /* Initialize data */
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    memset(data, 'A', 100-1);
    data[100-1] = '\0';
    /* POTENTIAL FLAW: Free data in the source - the bad sink attempts to use data */
    free(data);
    CWE416_Use_After_Free__malloc_free_char_51b_bad_sink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE416_Use_After_Free__malloc_free_char_51b_goodG2B_sink(char * data);

static void goodG2B()
{
    char * data;
    /* Initialize data */
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    memset(data, 'A', 100-1);
    data[100-1] = '\0';
    /* FIX: Do not delete data in the source */
    CWE416_Use_After_Free__malloc_free_char_51b_goodG2B_sink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE416_Use_After_Free__malloc_free_char_51b_goodB2G_sink(char * data);

static void goodB2G()
{
    char * data;
    /* Initialize data */
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    memset(data, 'A', 100-1);
    data[100-1] = '\0';
    /* POTENTIAL FLAW: Free data in the source - the bad sink attempts to use data */
    free(data);
    CWE416_Use_After_Free__malloc_free_char_51b_goodB2G_sink(data);
}

void CWE416_Use_After_Free__malloc_free_char_51_good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE416_Use_After_Free__malloc_free_char_51_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE416_Use_After_Free__malloc_free_char_51_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
