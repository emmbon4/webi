/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE123_Write_What_Where_Condition__fgets_32.c
Label Definition File: CWE123_Write_What_Where_Condition.label.xml
Template File: sources-sink-32.tmpl.c
*/
/*
 * @description
 * CWE: 123 Write-What-Where Condition
 * BadSource: fgets Overwrite linked list pointers using fgets
 * GoodSource: Don't overwrite linked list pointers
 * Sink:
 *    BadSink : Remove element from list
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
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

#ifndef OMITBAD

void CWE123_Write_What_Where_Condition__fgets_32_bad()
{
    bad_struct data;
    bad_struct *data_ptr1 = &data;
    bad_struct *data_ptr2 = &data;
    linked_list head = { &head, &head };
    /* This simulates a Microsoft-style linked list insertion */
    data.list.next = head.next;
    data.list.prev = &head;
    head.next = &data.list;
    head.next->prev = &data.list;
    {
        bad_struct data = *data_ptr1;
        /* FLAW: overwrite linked list pointers with user data */
        fgets((char*)&data, sizeof(data), stdin);
        *data_ptr1 = data;
    }
    {
        bad_struct data = *data_ptr2;
        /* POTENTIAL FLAW: The following removes 'a' from the list.  Because of the possible overflow this
         * causes a "write-what-where" aka "write4".  It does another write as
         * well.  But this is the prototypical "write-what-where" at least from
         * the Windows perspective.
         *
         * prev = a->list->prev  WHAT
         * next = a->list->next  WHERE
         * prev->next = next  "at the address that prev/WHERE points, write
         *                    next/WHAT"
         *                    aka "write-what-where"
         * next->prev = prev  "at the address that next/WHAT points plus 4
         *                    (because prev is the second field in 'list' hence
         *                    4 bytes away on 32b machines), write prev/WHERE"
         */
        prev = data.list.prev;
        next = data.list.next;
        prev->next = next;
        next->prev = prev;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    bad_struct data;
    bad_struct *data_ptr1 = &data;
    bad_struct *data_ptr2 = &data;
    linked_list head = { &head, &head };
    /* This simulates a Microsoft-style linked list insertion */
    data.list.next = head.next;
    data.list.prev = &head;
    head.next = &data.list;
    head.next->prev = &data.list;
    {
        bad_struct data = *data_ptr1;
        /* FIX: don't overwrite linked list pointers */
        ; /* empty statement needed by some flow variants */
        *data_ptr1 = data;
    }
    {
        bad_struct data = *data_ptr2;
        /* POTENTIAL FLAW: The following removes 'a' from the list.  Because of the possible overflow this
         * causes a "write-what-where" aka "write4".  It does another write as
         * well.  But this is the prototypical "write-what-where" at least from
         * the Windows perspective.
         *
         * prev = a->list->prev  WHAT
         * next = a->list->next  WHERE
         * prev->next = next  "at the address that prev/WHERE points, write
         *                    next/WHAT"
         *                    aka "write-what-where"
         * next->prev = prev  "at the address that next/WHAT points plus 4
         *                    (because prev is the second field in 'list' hence
         *                    4 bytes away on 32b machines), write prev/WHERE"
         */
        prev = data.list.prev;
        next = data.list.next;
        prev->next = next;
        next->prev = prev;
    }
}

void CWE123_Write_What_Where_Condition__fgets_32_good()
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
    CWE123_Write_What_Where_Condition__fgets_32_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE123_Write_What_Where_Condition__fgets_32_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
