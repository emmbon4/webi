/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_45.c
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Small number greater than zero
 * Sinks:
 *    GoodSink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    BadSink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE sizeof(data)*sizeof(data)

#define HELLO_STRING L"hello"

static int CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_45_bad_data;
static int CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_45_goodG2B_data;
static int CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_45_goodB2G_data;

#ifndef OMITBAD

static void bad_sink()
{
    int data = CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_45_bad_data;
    {
        wchar_t * wchar_t_string;
        /* FLAW: No MAXIMUM limitation for memory allocation and no check to ensure data is large enough
         * for the wcscpy() function to not cause a buffer overflow */
        /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
        if (data > 0)
        {
            wchar_t_string = (wchar_t *)malloc(data*sizeof(wchar_t));
            /* Copy a small string into wchar_t_string$ */
            wcscpy(wchar_t_string, HELLO_STRING);
            printWLine(wchar_t_string);
            free(wchar_t_string);
        }
        else
        {
            printLine("Input is less than 0");
        }
    }
}

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_45_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    {
        char input_buf[CHAR_ARRAY_SIZE] = "";
        fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
        /* Convert to int */
        data = atoi(input_buf);
    }
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_45_bad_data = data;
    bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B_sink()
{
    int data = CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_45_goodG2B_data;
    {
        wchar_t * wchar_t_string;
        /* FLAW: No MAXIMUM limitation for memory allocation and no check to ensure data is large enough
         * for the wcscpy() function to not cause a buffer overflow */
        /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
        if (data > 0)
        {
            wchar_t_string = (wchar_t *)malloc(data*sizeof(wchar_t));
            /* Copy a small string into wchar_t_string$ */
            wcscpy(wchar_t_string, HELLO_STRING);
            printWLine(wchar_t_string);
            free(wchar_t_string);
        }
        else
        {
            printLine("Input is less than 0");
        }
    }
}

static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a relatively small number for memory allocation */
    data = 20;
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_45_goodG2B_data = data;
    goodG2B_sink();
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G_sink()
{
    int data = CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_45_goodB2G_data;
    {
        wchar_t * wchar_t_string;
        /* FIX: Include a MAXIMUM limitation for memory allocation and a check to ensure data is large enough
         * for the wcscpy() function to not cause a buffer overflow */
        /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
        if ((size_t)data > wcslen(HELLO_STRING) && data < 100)
        {
            wchar_t_string = (wchar_t *)malloc(data*sizeof(wchar_t));
            /* Copy a small string into wchar_t_string$ */
            wcscpy(wchar_t_string, HELLO_STRING);
            printWLine(wchar_t_string);
            free(wchar_t_string);
        }
        else
        {
            printLine("Input is less than the length of the source string or too large");
        }
    }
}

static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    {
        char input_buf[CHAR_ARRAY_SIZE] = "";
        fgets(input_buf, CHAR_ARRAY_SIZE, stdin);
        /* Convert to int */
        data = atoi(input_buf);
    }
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_45_goodB2G_data = data;
    goodB2G_sink();
}

void CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_45_good()
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
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_45_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE789_Uncontrolled_Mem_Alloc__malloc_wchar_t_fgets_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
