#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List *plist)
{
    plist->head = (Node *)malloc(sizeof(Node));
    plist->head->prev = NULL;
    plist->head->next = plist->tail;
    plist->tail = (Node *)malloc(sizeof(Node));
    plist->tail->next = NULL;
    plist->tail->prev = plist->head;
    plist->numOfData = 0;
}

void LInsert(List *plist, Data data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    /* 새 노드와 새노드의 왼쪽에 위치할 노드가 서로를 가리키게 한다 */
    newNode->prev = plist->tail->prev;
    plist->tail->prev->next = newNode;

    /* 새 노드와 새노드의 오른쪽에 위치할 노드가 서로를 가리키게 한다 */
    newNode->next = plist->tail;
    plist->tail->prev = newNode;
    (plist->numOfData)++;
}

int LFirst(List *plist, Data *pdata)
{
    if (plist->head->next == plist->tail)
        return FALSE;

    plist->cur = plist->head->next;
    *pdata = plist->cur->data;
    return TRUE;
}

int LNext(List *plist, Data *pdata)
{
    if (plist->cur->next == plist->tail)
        return FALSE;

    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;

    return TRUE;
}

int LPrevious(List *plist, Data *pdata)
{
    if (plist->cur->prev == plist->head)
        return FALSE;

    plist->cur = plist->cur->prev;
    *pdata = plist->cur->data;

    return TRUE;
}

int LCount(List *plist)
{
    return plist->numOfData;
}

Data LRemove(List *plist)
{
    Node *rnode = plist->cur;
    Data rdata = rnode->data;

    plist->cur->prev->next = plist->cur->next;
    plist->cur->next->prev = plist->cur->prev;

    plist->cur = plist->cur->prev; // cur의 위치를 재조정
    free(rnode);
    (plist->numOfData)--;
    return rdata;
}