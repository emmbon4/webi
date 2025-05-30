/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_memmove_67a.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__src.string.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sinks: memmove
 *    BadSink : Copy data to string using memmove
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_memmove_67_struct_type
{
    char * a;
} CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_memmove_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_memmove_67b_bad_sink(CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_memmove_67_struct_type my_struct);

void CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_memmove_67_bad()
{
    char * data;
    CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_memmove_67_struct_type my_struct;
    char * data_buf = (char *)ALLOCA(100*sizeof(char));
    data = data_buf;
    /* FLAW: Initialize data as a large buffer that is larger than the small buffer used in the sink */
    memset(data, 'A', 100-1); /* fill with 'A's */
    data[100-1] = '\0'; /* null terminate */
    my_struct.a = data;
    CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_memmove_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_memmove_67b_goodG2B_sink(CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_memmove_67_struct_type my_struct);

static void goodG2B()
{
    char * data;
    CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_memmove_67_struct_type my_struct;
    char * data_buf = (char *)ALLOCA(100*sizeof(char));
    data = data_buf;
    /* FIX: Initialize data as a small buffer that as small or smaller than the small buffer used in the sink */
    memset(data, 'A', 50-1); /* fill with 'A's */
    data[50-1] = '\0'; /* null terminate */
    my_struct.a = data;
    CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_memmove_67b_goodG2B_sink(my_struct);
}

void CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_memmove_67_good()
{
    goodG2B();
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
    CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_memmove_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_memmove_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
