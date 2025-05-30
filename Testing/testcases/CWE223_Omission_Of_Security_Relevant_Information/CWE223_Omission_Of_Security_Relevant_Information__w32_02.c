/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE223_Omission_Of_Security_Relevant_Information__w32_02.c
Label Definition File: CWE223_Omission_Of_Security_Relevant_Information__w32.label.xml
Template File: point-flaw-02.tmpl.c
*/
/*
 * @description
 * CWE: 223 Omission of Security Relevant Information
 * Sinks:
 *    GoodSink: Log the username
 *    BadSink : Username is not logged
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# include <winsock2.h>
# pragma comment(lib, "ws2_32")
#endif

#ifdef _WIN32
# define CLOSESOCKET closesocket
# define UNLINK _unlink
#define LISTEN_PORT 999
#define LISTEN_BACKLOG 5
#define USERNAME_SZ 15
#endif

#ifndef OMITBAD

void CWE223_Omission_Of_Security_Relevant_Information__w32_02_bad()
{
    if(1)
    {
        {
#ifdef _WIN32
            WSADATA wsadata;
            BOOL wsa_init = FALSE;
            SOCKET listener = INVALID_SOCKET;
            SOCKET client = INVALID_SOCKET;
            struct sockaddr_in s_in;
            char username[USERNAME_SZ+1];
            do
            {
                if (0 != WSAStartup(MAKEWORD(2, 2), &wsadata)) break;
                wsa_init = TRUE;
                listener = socket(PF_INET, SOCK_STREAM, 0);
                if (listener == INVALID_SOCKET) break;
                memset(&s_in, 0, sizeof(s_in));
                s_in.sin_family = AF_INET;
                s_in.sin_addr.s_addr = INADDR_ANY;
                s_in.sin_port = htons(LISTEN_PORT);
                if (SOCKET_ERROR == bind(listener, (struct sockaddr*)&s_in, sizeof(s_in))) break;
                if (SOCKET_ERROR == listen(listener, LISTEN_BACKLOG)) break;
                client = accept(listener, NULL, NULL);
                if (client == INVALID_SOCKET) break;
                if (sizeof(username)-sizeof(char) != recv(client, username, sizeof(username)-sizeof(char), 0)) break;
                username[USERNAME_SZ] = '\0';
                /* INCIDENTAL CWE 188 - reliance on data memory layout
                * recv and friends return "number of bytes" received
                * fwrite wants "the size of".  ANSI/ISO allows the size of chars
                * to be anything (32 bits, 9 bits, etc.) so technically you
                * have to do conversion between these values
                */
                /* FLAW: username is not logged */
                fprintf(stderr, "User logged in\n");
            }
            while (0);
            if (client != INVALID_SOCKET) CLOSESOCKET(client);
            if (listener != INVALID_SOCKET) CLOSESOCKET(listener);
            if (wsa_init) WSACleanup();
#endif /* _WIN32 */
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
#ifdef _WIN32
            WSADATA wsadata;
            BOOL wsa_init = FALSE;
            SOCKET listener = INVALID_SOCKET;
            SOCKET client = INVALID_SOCKET;
            struct sockaddr_in s_in;
            char username[USERNAME_SZ+1];
            do
            {
                if (0 != WSAStartup(MAKEWORD(2, 2), &wsadata)) break;
                wsa_init = TRUE;
                listener = socket(PF_INET, SOCK_STREAM, 0);
                if (listener == INVALID_SOCKET) break;
                memset(&s_in, 0, sizeof(s_in));
                s_in.sin_family = AF_INET;
                s_in.sin_addr.s_addr = INADDR_ANY;
                s_in.sin_port = htons(LISTEN_PORT);
                if (SOCKET_ERROR == bind(listener, (struct sockaddr*)&s_in, sizeof(s_in))) break;
                if (SOCKET_ERROR == listen(listener, LISTEN_BACKLOG)) break;
                client = accept(listener, NULL, NULL);
                if (client == INVALID_SOCKET) break;
                if (sizeof(username)-sizeof(char) != recv(client, username, sizeof(username)-sizeof(char), 0)) break;
                username[USERNAME_SZ] = '\0';
                /* INCIDENTAL CWE 188 - reliance on data memory layout
                * recv and friends return "number of bytes" received
                * fwrite wants "the size of".  ANSI/ISO allows the size of chars
                * to be anything (32 bits, 9 bits, etc.) so technically you
                * have to do conversion between these values
                */
                /* FIX: Log the username */
                fprintf(stderr, "User %s logged in\n", username);
            }
            while (0);
            if (client != INVALID_SOCKET) CLOSESOCKET(client);
            if (listener != INVALID_SOCKET) CLOSESOCKET(listener);
            if (wsa_init) WSACleanup();
#endif /* _WIN32 */
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(0) instead of if(1) */
static void good1()
{
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
#ifdef _WIN32
            WSADATA wsadata;
            BOOL wsa_init = FALSE;
            SOCKET listener = INVALID_SOCKET;
            SOCKET client = INVALID_SOCKET;
            struct sockaddr_in s_in;
            char username[USERNAME_SZ+1];
            do
            {
                if (0 != WSAStartup(MAKEWORD(2, 2), &wsadata)) break;
                wsa_init = TRUE;
                listener = socket(PF_INET, SOCK_STREAM, 0);
                if (listener == INVALID_SOCKET) break;
                memset(&s_in, 0, sizeof(s_in));
                s_in.sin_family = AF_INET;
                s_in.sin_addr.s_addr = INADDR_ANY;
                s_in.sin_port = htons(LISTEN_PORT);
                if (SOCKET_ERROR == bind(listener, (struct sockaddr*)&s_in, sizeof(s_in))) break;
                if (SOCKET_ERROR == listen(listener, LISTEN_BACKLOG)) break;
                client = accept(listener, NULL, NULL);
                if (client == INVALID_SOCKET) break;
                if (sizeof(username)-sizeof(char) != recv(client, username, sizeof(username)-sizeof(char), 0)) break;
                username[USERNAME_SZ] = '\0';
                /* INCIDENTAL CWE 188 - reliance on data memory layout
                * recv and friends return "number of bytes" received
                * fwrite wants "the size of".  ANSI/ISO allows the size of chars
                * to be anything (32 bits, 9 bits, etc.) so technically you
                * have to do conversion between these values
                */
                /* FLAW: username is not logged */
                fprintf(stderr, "User logged in\n");
            }
            while (0);
            if (client != INVALID_SOCKET) CLOSESOCKET(client);
            if (listener != INVALID_SOCKET) CLOSESOCKET(listener);
            if (wsa_init) WSACleanup();
#endif /* _WIN32 */
        }
    }
    else
    {
        {
#ifdef _WIN32
            WSADATA wsadata;
            BOOL wsa_init = FALSE;
            SOCKET listener = INVALID_SOCKET;
            SOCKET client = INVALID_SOCKET;
            struct sockaddr_in s_in;
            char username[USERNAME_SZ+1];
            do
            {
                if (0 != WSAStartup(MAKEWORD(2, 2), &wsadata)) break;
                wsa_init = TRUE;
                listener = socket(PF_INET, SOCK_STREAM, 0);
                if (listener == INVALID_SOCKET) break;
                memset(&s_in, 0, sizeof(s_in));
                s_in.sin_family = AF_INET;
                s_in.sin_addr.s_addr = INADDR_ANY;
                s_in.sin_port = htons(LISTEN_PORT);
                if (SOCKET_ERROR == bind(listener, (struct sockaddr*)&s_in, sizeof(s_in))) break;
                if (SOCKET_ERROR == listen(listener, LISTEN_BACKLOG)) break;
                client = accept(listener, NULL, NULL);
                if (client == INVALID_SOCKET) break;
                if (sizeof(username)-sizeof(char) != recv(client, username, sizeof(username)-sizeof(char), 0)) break;
                username[USERNAME_SZ] = '\0';
                /* INCIDENTAL CWE 188 - reliance on data memory layout
                * recv and friends return "number of bytes" received
                * fwrite wants "the size of".  ANSI/ISO allows the size of chars
                * to be anything (32 bits, 9 bits, etc.) so technically you
                * have to do conversion between these values
                */
                /* FIX: Log the username */
                fprintf(stderr, "User %s logged in\n", username);
            }
            while (0);
            if (client != INVALID_SOCKET) CLOSESOCKET(client);
            if (listener != INVALID_SOCKET) CLOSESOCKET(listener);
            if (wsa_init) WSACleanup();
#endif /* _WIN32 */
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(1)
    {
        {
#ifdef _WIN32
            WSADATA wsadata;
            BOOL wsa_init = FALSE;
            SOCKET listener = INVALID_SOCKET;
            SOCKET client = INVALID_SOCKET;
            struct sockaddr_in s_in;
            char username[USERNAME_SZ+1];
            do
            {
                if (0 != WSAStartup(MAKEWORD(2, 2), &wsadata)) break;
                wsa_init = TRUE;
                listener = socket(PF_INET, SOCK_STREAM, 0);
                if (listener == INVALID_SOCKET) break;
                memset(&s_in, 0, sizeof(s_in));
                s_in.sin_family = AF_INET;
                s_in.sin_addr.s_addr = INADDR_ANY;
                s_in.sin_port = htons(LISTEN_PORT);
                if (SOCKET_ERROR == bind(listener, (struct sockaddr*)&s_in, sizeof(s_in))) break;
                if (SOCKET_ERROR == listen(listener, LISTEN_BACKLOG)) break;
                client = accept(listener, NULL, NULL);
                if (client == INVALID_SOCKET) break;
                if (sizeof(username)-sizeof(char) != recv(client, username, sizeof(username)-sizeof(char), 0)) break;
                username[USERNAME_SZ] = '\0';
                /* INCIDENTAL CWE 188 - reliance on data memory layout
                * recv and friends return "number of bytes" received
                * fwrite wants "the size of".  ANSI/ISO allows the size of chars
                * to be anything (32 bits, 9 bits, etc.) so technically you
                * have to do conversion between these values
                */
                /* FIX: Log the username */
                fprintf(stderr, "User %s logged in\n", username);
            }
            while (0);
            if (client != INVALID_SOCKET) CLOSESOCKET(client);
            if (listener != INVALID_SOCKET) CLOSESOCKET(listener);
            if (wsa_init) WSACleanup();
#endif /* _WIN32 */
        }
    }
    else
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        {
#ifdef _WIN32
            WSADATA wsadata;
            BOOL wsa_init = FALSE;
            SOCKET listener = INVALID_SOCKET;
            SOCKET client = INVALID_SOCKET;
            struct sockaddr_in s_in;
            char username[USERNAME_SZ+1];
            do
            {
                if (0 != WSAStartup(MAKEWORD(2, 2), &wsadata)) break;
                wsa_init = TRUE;
                listener = socket(PF_INET, SOCK_STREAM, 0);
                if (listener == INVALID_SOCKET) break;
                memset(&s_in, 0, sizeof(s_in));
                s_in.sin_family = AF_INET;
                s_in.sin_addr.s_addr = INADDR_ANY;
                s_in.sin_port = htons(LISTEN_PORT);
                if (SOCKET_ERROR == bind(listener, (struct sockaddr*)&s_in, sizeof(s_in))) break;
                if (SOCKET_ERROR == listen(listener, LISTEN_BACKLOG)) break;
                client = accept(listener, NULL, NULL);
                if (client == INVALID_SOCKET) break;
                if (sizeof(username)-sizeof(char) != recv(client, username, sizeof(username)-sizeof(char), 0)) break;
                username[USERNAME_SZ] = '\0';
                /* INCIDENTAL CWE 188 - reliance on data memory layout
                * recv and friends return "number of bytes" received
                * fwrite wants "the size of".  ANSI/ISO allows the size of chars
                * to be anything (32 bits, 9 bits, etc.) so technically you
                * have to do conversion between these values
                */
                /* FLAW: username is not logged */
                fprintf(stderr, "User logged in\n");
            }
            while (0);
            if (client != INVALID_SOCKET) CLOSESOCKET(client);
            if (listener != INVALID_SOCKET) CLOSESOCKET(listener);
            if (wsa_init) WSACleanup();
#endif /* _WIN32 */
        }
    }
}

void CWE223_Omission_Of_Security_Relevant_Information__w32_02_good()
{
    good1();
    good2();
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
    CWE223_Omission_Of_Security_Relevant_Information__w32_02_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE223_Omission_Of_Security_Relevant_Information__w32_02_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
