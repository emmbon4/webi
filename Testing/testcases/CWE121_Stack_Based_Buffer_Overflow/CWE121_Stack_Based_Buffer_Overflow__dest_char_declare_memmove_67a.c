/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_memmove_67a.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__dest.string.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Set data pointer to the bad buffer
 * GoodSource: Set data pointer to the good buffer
 * Sinks: memmove
 *    BadSink : Copy string to data using memmove
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_memmove_67_struct_type
{
    char * a;
} CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_memmove_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_memmove_67b_bad_sink(CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_memmove_67_struct_type my_struct);

void CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_memmove_67_bad()
{
    char * data;
    CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_memmove_67_struct_type my_struct;
    char data_badbuf[50];
    char data_goodbuf[100];
    /* FLAW: Set a pointer to a "small" buffer. This buffer will be used in the sinks as a destination
     * buffer in various memory copying functions using a "large" source buffer. */
    data = data_badbuf;
    data[0] = '\0'; /* null terminate */
    my_struct.a = data;
    CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_memmove_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_memmove_67b_goodG2B_sink(CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_memmove_67_struct_type my_struct);

static void goodG2B()
{
    char * data;
    CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_memmove_67_struct_type my_struct;
    char data_badbuf[50];
    char data_goodbuf[100];
    /* FIX: Set a pointer to a "large" buffer, thus avoiding buffer overflows in the sinks. */
    data = data_goodbuf;
    data[0] = '\0'; /* null terminate */
    my_struct.a = data;
    CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_memmove_67b_goodG2B_sink(my_struct);
}

void CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_memmove_67_good()
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
    CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_memmove_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_memmove_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
