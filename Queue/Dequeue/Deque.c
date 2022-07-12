#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque * pdeque)
{
    pdeque->head = NULL;
    pdeque->tail = NULL;
}

int DQIsEmpty(Deque * pdeque)
{
    if(pdeque->head == NULL)
        return TRUE;
    else
        return FALSE;
}

/* 덱 머리에 데이터 추가 */
void DQAddFirst(Deque * pdef, Data data) 
{
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = data;

    newNode->next = pdef->head; 

    if(DQIsEmpty(pdef))
        pdef->tail = newNode;
    else
        pdef->head->prev = newNode;
    
    newNode->prev = NULL;
    pdef->head = newNode;
}

/* 덱 꼬리에 데이터 추가 */
void DQAddLast(Deque * pdeq, Data data)
{
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = data;

    /* 새노드의 왼쪽 연결 */
    newNode->prev = pdeq->tail;  //첫 노드는 null 두번쨰 부터 다음 노드를 가리킴

    if(DQIsEmpty(pdeq))
        pdeq->head = newNode;
    else
        pdeq->tail->next = newNode;

    newNode->next = NULL;
    pdeq->tail = newNode;
}

/* 덱 머리에서 데이터 삭제 */
Data DQRemoveFirst(Deque * pdeq)
{
    Node * rNode;
    Data rData;

     if(DQIsEmpty(pdeq))
    {
        printf("Deque is empty");
        exit(-1);
    }

    rNode = pdeq->head;
    rData = rNode->data;

   
    /* 노드를 한칸 전진 */
    pdeq->head = pdeq->head->next;
    
    free(rNode);

    /* 노드가 하나도 안남은 경우 */
    if(pdeq->head == NULL)
        pdeq->tail = NULL;
    else
        pdeq->head->prev = NULL;
    return rData;
} 

/* 덱의 꼬리에서 데이터 삭제 */
Data DQRemoveLast(Deque * pdeq)
{
    Node * rNode = pdeq->tail;
    Data rData;

    if(DQIsEmpty(pdeq))
    {
        printf("Deque is empty.\n");
        exit(-1);
    }
    rData = rNode -> data;

    /* tail 한칸 이동 */
    pdeq->tail = pdeq->tail->prev;

    free(rNode);

    if(pdeq->tail == NULL)
        pdeq->head = NULL;
    else
        pdeq->tail->next = NULL;
        
    return rData;
}

/* 덱의 머리에서 데이터 참조 */
Data DQGetFirst(Deque * pdeq)
{
    if(DQIsEmpty(pdeq))
    {
          printf("Deque is empty.\n");
        exit(-1);
    }

    return pdeq->head->data;
}


 /* 덱 꼬리에서 데이터 참조 */
Data DQGetLast(Deque * pdeq)
{
     if(DQIsEmpty(pdeq))
    {
          printf("Deque is empty.\n");
        exit(-1);
    }

    return pdeq->tail->data;
}
