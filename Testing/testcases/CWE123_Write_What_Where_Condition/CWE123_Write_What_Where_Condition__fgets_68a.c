/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE123_Write_What_Where_Condition__fgets_68a.c
Label Definition File: CWE123_Write_What_Where_Condition.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 123 Write-What-Where Condition
 * BadSource: fgets Overwrite linked list pointers using fgets
 * GoodSource: Don't overwrite linked list pointers
 * Sink:
 *    BadSink : Remove element from list
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _linked_list
{
    struct _linked_list *next;
    struct _linked_list *prev;
} linked_list;

typedef struct _bad_struct
{
    linked_list list;
} bad_struct;

static linked_list *prev, *next;

bad_struct CWE123_Write_What_Where_Condition__fgets_68_bad_data;
bad_struct CWE123_Write_What_Where_Condition__fgets_68_goodG2B_data;

#ifndef OMITBAD

/* bad function declaration */
void CWE123_Write_What_Where_Condition__fgets_68b_bad_sink();

void CWE123_Write_What_Where_Condition__fgets_68_bad()
{
    bad_struct data;
    linked_list head = { &head, &head };
    /* This simulates a Microsoft-style linked list insertion */
    data.list.next = head.next;
    data.list.prev = &head;
    head.next = &data.list;
    head.next->prev = &data.list;
    /* FLAW: overwrite linked list pointers with user data */
    fgets((char*)&data, sizeof(data), stdin);
    CWE123_Write_What_Where_Condition__fgets_68_bad_data = data;
    CWE123_Write_What_Where_Condition__fgets_68b_bad_sink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE123_Write_What_Where_Condition__fgets_68b_goodG2B_sink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    bad_struct data;
    linked_list head = { &head, &head };
    /* This simulates a Microsoft-style linked list insertion */
    data.list.next = head.next;
    data.list.prev = &head;
    head.next = &data.list;
    head.next->prev = &data.list;
    /* FIX: don't overwrite linked list pointers */
    ; /* empty statement needed by some flow variants */
    CWE123_Write_What_Where_Condition__fgets_68_goodG2B_data = data;
    CWE123_Write_What_Where_Condition__fgets_68b_goodG2B_sink();
}

void CWE123_Write_What_Where_Condition__fgets_68_good()
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
    CWE123_Write_What_Where_Condition__fgets_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE123_Write_What_Where_Condition__fgets_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
