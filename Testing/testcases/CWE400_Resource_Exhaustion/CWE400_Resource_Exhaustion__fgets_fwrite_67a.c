/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fgets_fwrite_67a.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: fwrite
 *    GoodSink: Write to a file count number of times, but first validate count
 *    BadSink : Write to a file count number of times
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(count)*sizeof(count)

#define SENTENCE "This is the sentence we are printing to the file. "

typedef struct _CWE400_Resource_Exhaustion__fgets_fwrite_67_struct_type
{
    int a;
} CWE400_Resource_Exhaustion__fgets_fwrite_67_struct_type;

#ifndef OMITBAD

/* bad function declaration */
void CWE400_Resource_Exhaustion__fgets_fwrite_67b_bad_sink(CWE400_Resource_Exhaustion__fgets_fwrite_67_struct_type my_struct);

void CWE400_Resource_Exhaustion__fgets_fwrite_67_bad()
{
    int count;
    CWE400_Resource_Exhaustion__fgets_fwrite_67_struct_type my_struct;
    /* Initialize count */
    count = -1;
    {
        char input_buf[CHAR_ARRAY_SIZE] = "";
        fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
        /* Convert to int */
        count = atoi(input_buf);
    }
    my_struct.a = count;
    CWE400_Resource_Exhaustion__fgets_fwrite_67b_bad_sink(my_struct);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE400_Resource_Exhaustion__fgets_fwrite_67b_goodG2B_sink(CWE400_Resource_Exhaustion__fgets_fwrite_67_struct_type my_struct);

static void goodG2B()
{
    int count;
    CWE400_Resource_Exhaustion__fgets_fwrite_67_struct_type my_struct;
    /* Initialize count */
    count = -1;
    /* FIX: Use a relatively small number */
    count = 20;
    my_struct.a = count;
    CWE400_Resource_Exhaustion__fgets_fwrite_67b_goodG2B_sink(my_struct);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE400_Resource_Exhaustion__fgets_fwrite_67b_goodB2G_sink(CWE400_Resource_Exhaustion__fgets_fwrite_67_struct_type my_struct);

static void goodB2G()
{
    int count;
    CWE400_Resource_Exhaustion__fgets_fwrite_67_struct_type my_struct;
    /* Initialize count */
    count = -1;
    {
        char input_buf[CHAR_ARRAY_SIZE] = "";
        fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
        /* Convert to int */
        count = atoi(input_buf);
    }
    my_struct.a = count;
    CWE400_Resource_Exhaustion__fgets_fwrite_67b_goodB2G_sink(my_struct);
}

void CWE400_Resource_Exhaustion__fgets_fwrite_67_good()
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
    CWE400_Resource_Exhaustion__fgets_fwrite_67_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE400_Resource_Exhaustion__fgets_fwrite_67_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
