/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE123_Write_What_Where_Condition__connect_socket_05.c
Label Definition File: CWE123_Write_What_Where_Condition.label.xml
Template File: sources-sink-05.tmpl.c
*/
/*
 * @description
 * CWE: 123 Write-What-Where Condition
 * BadSource: connect_socket Overwrite linked list pointers using a connect socket (client side)
 * GoodSource: Don't overwrite linked list pointers
 * Sink:
 *    BadSink : Remove element from list
 * Flow Variant: 05 Control flow: if(static_t) and if(static_f)
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

#ifdef _WIN32
# include <winsock2.h>
# include <windows.h>
# include <direct.h>
# pragma comment(lib, "ws2_32") /* include ws2_32.lib when linking */
# define CLOSE_SOCKET closesocket
#else /* NOT _WIN32 */
# define INVALID_SOCKET -1
# define SOCKET_ERROR -1
# define CLOSE_SOCKET close
# define SOCKET int
#endif

#define TCP_PORT 27015

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int static_t = 1; /* true */
static int static_f = 0; /* false */

#ifndef OMITBAD

void CWE123_Write_What_Where_Condition__connect_socket_05_bad()
{
    bad_struct data;
    linked_list head = { &head, &head };
    /* This simulates a Microsoft-style linked list insertion */
    data.list.next = head.next;
    data.list.prev = &head;
    head.next = &data.list;
    head.next->prev = &data.list;
    if(static_t)
    {
        {
#ifdef _WIN32
            WSADATA wsa_data;
            int wsa_data_init = 0;
#endif
            int recv_rv;
            struct sockaddr_in s_in;
            SOCKET connect_socket = INVALID_SOCKET;
            do
            {
#ifdef _WIN32
                if (WSAStartup(MAKEWORD(2,2), &wsa_data) != NO_ERROR) break;
                wsa_data_init = 1;
#endif
                connect_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
                if (connect_socket == INVALID_SOCKET) break;
                memset(&s_in, 0, sizeof(s_in));
                s_in.sin_family = AF_INET;
                s_in.sin_addr.s_addr = inet_addr("127.0.0.1");
                s_in.sin_port = htons(TCP_PORT);
                if (connect(connect_socket, (struct sockaddr*)&s_in, sizeof(s_in)) == SOCKET_ERROR) break;
                /* Abort on error or the connection was closed, make sure to recv one
                 * less char than is in the recv_buf in order to append a terminator */
                /* FLAW: overwrite linked list pointers with data */
                recv_rv = recv(connect_socket, (char*)&data, sizeof(data), 0);
                if (recv_rv == SOCKET_ERROR || recv_rv == 0) break;
            }
            while (0);
            if (connect_socket != INVALID_SOCKET) CLOSE_SOCKET(connect_socket);
#ifdef _WIN32
            if (wsa_data_init) WSACleanup();
#endif
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        /* FIX: don't overwrite linked list pointers */
        ; /* empty statement needed by some flow variants */
    }
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

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the static_t to static_f */
static void goodG2B1()
{
    bad_struct data;
    linked_list head = { &head, &head };
    /* This simulates a Microsoft-style linked list insertion */
    data.list.next = head.next;
    data.list.prev = &head;
    head.next = &data.list;
    head.next->prev = &data.list;
    if(static_f)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
#ifdef _WIN32
            WSADATA wsa_data;
            int wsa_data_init = 0;
#endif
            int recv_rv;
            struct sockaddr_in s_in;
            SOCKET connect_socket = INVALID_SOCKET;
            do
            {
#ifdef _WIN32
                if (WSAStartup(MAKEWORD(2,2), &wsa_data) != NO_ERROR) break;
                wsa_data_init = 1;
#endif
                connect_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
                if (connect_socket == INVALID_SOCKET) break;
                memset(&s_in, 0, sizeof(s_in));
                s_in.sin_family = AF_INET;
                s_in.sin_addr.s_addr = inet_addr("127.0.0.1");
                s_in.sin_port = htons(TCP_PORT);
                if (connect(connect_socket, (struct sockaddr*)&s_in, sizeof(s_in)) == SOCKET_ERROR) break;
                /* Abort on error or the connection was closed, make sure to recv one
                 * less char than is in the recv_buf in order to append a terminator */
                /* FLAW: overwrite linked list pointers with data */
                recv_rv = recv(connect_socket, (char*)&data, sizeof(data), 0);
                if (recv_rv == SOCKET_ERROR || recv_rv == 0) break;
            }
            while (0);
            if (connect_socket != INVALID_SOCKET) CLOSE_SOCKET(connect_socket);
#ifdef _WIN32
            if (wsa_data_init) WSACleanup();
#endif
        }
    }
    else
    {
        /* FIX: don't overwrite linked list pointers */
        ; /* empty statement needed by some flow variants */
    }
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

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    bad_struct data;
    linked_list head = { &head, &head };
    /* This simulates a Microsoft-style linked list insertion */
    data.list.next = head.next;
    data.list.prev = &head;
    head.next = &data.list;
    head.next->prev = &data.list;
    if(static_t)
    {
        /* FIX: don't overwrite linked list pointers */
        ; /* empty statement needed by some flow variants */
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
#ifdef _WIN32
            WSADATA wsa_data;
            int wsa_data_init = 0;
#endif
            int recv_rv;
            struct sockaddr_in s_in;
            SOCKET connect_socket = INVALID_SOCKET;
            do
            {
#ifdef _WIN32
                if (WSAStartup(MAKEWORD(2,2), &wsa_data) != NO_ERROR) break;
                wsa_data_init = 1;
#endif
                connect_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
                if (connect_socket == INVALID_SOCKET) break;
                memset(&s_in, 0, sizeof(s_in));
                s_in.sin_family = AF_INET;
                s_in.sin_addr.s_addr = inet_addr("127.0.0.1");
                s_in.sin_port = htons(TCP_PORT);
                if (connect(connect_socket, (struct sockaddr*)&s_in, sizeof(s_in)) == SOCKET_ERROR) break;
                /* Abort on error or the connection was closed, make sure to recv one
                 * less char than is in the recv_buf in order to append a terminator */
                /* FLAW: overwrite linked list pointers with data */
                recv_rv = recv(connect_socket, (char*)&data, sizeof(data), 0);
                if (recv_rv == SOCKET_ERROR || recv_rv == 0) break;
            }
            while (0);
            if (connect_socket != INVALID_SOCKET) CLOSE_SOCKET(connect_socket);
#ifdef _WIN32
            if (wsa_data_init) WSACleanup();
#endif
        }
    }
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

void CWE123_Write_What_Where_Condition__connect_socket_05_good()
{
    goodG2B1();
    goodG2B2();
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
    CWE123_Write_What_Where_Condition__connect_socket_05_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE123_Write_What_Where_Condition__connect_socket_05_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
