/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fixed_string_68a.c
Label Definition File: CWE761_Free_Pointer_Not_At_Start_Of_Buffer.label.xml
Template File: source-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 761 Free Pointer Not At Start of Buffer
 * BadSource: fixed_string Initialize data to be a fixed string
 * Sinks:
 *    GoodSink: free() memory correctly at the start of the buffer
 *    BadSink : free() memory not at the start of the buffer
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define SEARCH_CHAR 'S'
#define BAD_SRC_FIXED "Fixed String" /* MAINTENANCE NOTE: This string must contain the SEARCH_CHAR */

char * CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fixed_string_68_bad_data_for_bad_sink;

char * CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fixed_string_68_bad_data_for_good_sink;

#ifndef OMITBAD

/* bad function declaration */
void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fixed_string_68b_bad_sink();

void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fixed_string_68_bad()
{
    char * data;
    data = (char *)malloc(100*sizeof(char));
    data[0] = '\0';
    /* Initialize data to be a fixed string that contains the search character in the sinks */
    strcpy(data, BAD_SRC_FIXED);
    CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fixed_string_68_bad_data_for_bad_sink = data;
    CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fixed_string_68b_bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fixed_string_68b_goodB2G_sink();

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    char * data;
    data = (char *)malloc(100*sizeof(char));
    data[0] = '\0';
    /* Initialize data to be a fixed string that contains the search character in the sinks */
    strcpy(data, BAD_SRC_FIXED);
    CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fixed_string_68_bad_data_for_good_sink = data;
    CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fixed_string_68b_goodB2G_sink();
}

void CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fixed_string_68_good()
{
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
    CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fixed_string_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE761_Free_Pointer_Not_At_Start_Of_Buffer__char_fixed_string_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
