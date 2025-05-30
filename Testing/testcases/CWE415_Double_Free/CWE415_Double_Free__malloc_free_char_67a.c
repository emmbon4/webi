/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_char_67a.c
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using malloc() and Deallocate data using free()
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using free()
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE415_Double_Free__malloc_free_char_67_struct_type
{
    char * a;
} CWE415_Double_Free__malloc_free_char_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE415_Double_Free__malloc_free_char_67b_bad_sink(CWE415_Double_Free__malloc_free_char_67_struct_type my_struct);

void CWE415_Double_Free__malloc_free_char_67_bad()
{
    char * data;
    CWE415_Double_Free__malloc_free_char_67_struct_type my_struct;
    /* Initialize data */
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    /* POTENTIAL FLAW: Free data in the source - the bad sink frees data as well */
    free(data);
    my_struct.a = data;
    CWE415_Double_Free__malloc_free_char_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE415_Double_Free__malloc_free_char_67b_goodG2B_sink(CWE415_Double_Free__malloc_free_char_67_struct_type my_struct);

static void goodG2B()
{
    char * data;
    CWE415_Double_Free__malloc_free_char_67_struct_type my_struct;
    /* Initialize data */
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    /* FIX: Do NOT free data in the source - the bad sink frees data */
    my_struct.a = data;
    CWE415_Double_Free__malloc_free_char_67b_goodG2B_sink(my_struct);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE415_Double_Free__malloc_free_char_67b_goodB2G_sink(CWE415_Double_Free__malloc_free_char_67_struct_type my_struct);

static void goodB2G()
{
    char * data;
    CWE415_Double_Free__malloc_free_char_67_struct_type my_struct;
    /* Initialize data */
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    /* POTENTIAL FLAW: Free data in the source - the bad sink frees data as well */
    free(data);
    my_struct.a = data;
    CWE415_Double_Free__malloc_free_char_67b_goodB2G_sink(my_struct);
}

void CWE415_Double_Free__malloc_free_char_67_good()
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
    CWE415_Double_Free__malloc_free_char_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE415_Double_Free__malloc_free_char_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
