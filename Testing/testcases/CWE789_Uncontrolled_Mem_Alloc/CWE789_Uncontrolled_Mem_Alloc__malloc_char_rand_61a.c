/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_char_rand_61a.c
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Small number greater than zero
 * Sinks:
 *    GoodSink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    BadSink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define HELLO_STRING "hello"

#ifndef OMITBAD

/* bad function declaration */
int CWE789_Uncontrolled_Mem_Alloc__malloc_char_rand_61b_bad_source(int data);

void CWE789_Uncontrolled_Mem_Alloc__malloc_char_rand_61_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    data = CWE789_Uncontrolled_Mem_Alloc__malloc_char_rand_61b_bad_source(data);
    {
        char * char_string;
        /* FLAW: No MAXIMUM limitation for memory allocation and no check to ensure data is large enough
         * for the strcpy() function to not cause a buffer overflow */
        /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
        if (data > 0)
        {
            char_string = (char *)malloc(data*sizeof(char));
            /* Copy a small string into char_string$ */
            strcpy(char_string, HELLO_STRING);
            printLine(char_string);
            free(char_string);
        }
        else
        {
            printLine("Input is less than 0");
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
int CWE789_Uncontrolled_Mem_Alloc__malloc_char_rand_61b_goodG2B_source(int data);

static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    data = CWE789_Uncontrolled_Mem_Alloc__malloc_char_rand_61b_goodG2B_source(data);
    {
        char * char_string;
        /* FLAW: No MAXIMUM limitation for memory allocation and no check to ensure data is large enough
         * for the strcpy() function to not cause a buffer overflow */
        /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
        if (data > 0)
        {
            char_string = (char *)malloc(data*sizeof(char));
            /* Copy a small string into char_string$ */
            strcpy(char_string, HELLO_STRING);
            printLine(char_string);
            free(char_string);
        }
        else
        {
            printLine("Input is less than 0");
        }
    }
}

/* goodB2G uses the BadSource with the GoodSink */
int CWE789_Uncontrolled_Mem_Alloc__malloc_char_rand_61b_goodB2G_source(int data);

static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    data = CWE789_Uncontrolled_Mem_Alloc__malloc_char_rand_61b_goodB2G_source(data);
    {
        char * char_string;
        /* FIX: Include a MAXIMUM limitation for memory allocation and a check to ensure data is large enough
         * for the strcpy() function to not cause a buffer overflow */
        /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
        if ((size_t)data > strlen(HELLO_STRING) && data < 100)
        {
            char_string = (char *)malloc(data*sizeof(char));
            /* Copy a small string into char_string$ */
            strcpy(char_string, HELLO_STRING);
            printLine(char_string);
            free(char_string);
        }
        else
        {
            printLine("Input is less than the length of the source string or too large");
        }
    }
}

void CWE789_Uncontrolled_Mem_Alloc__malloc_char_rand_61_good()
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
    CWE789_Uncontrolled_Mem_Alloc__malloc_char_rand_61_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE789_Uncontrolled_Mem_Alloc__malloc_char_rand_61_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
