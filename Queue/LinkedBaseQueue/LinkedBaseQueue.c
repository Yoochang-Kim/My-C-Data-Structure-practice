#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

void QueueInit(Queue * pq)
{
    pq->front = NULL;
    pq->rear = NULL;
}

int QIsEmpty(Queue * pq)
{
    if(pq->front == NULL)
        return TRUE;
    else
        return FALSE;
}

void Enqueue(Queue * pq, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;

    if(QIsEmpty(pq)) /* 첫 번째 노드인 경우 */
    {
        pq->front = newNode; /* front가 새 노드를 가리키게 함 */
        pq->rear = newNode; /* rear가 새 노드를 가리키게 함 */
    }
    else /* 두 번째 이후 노드 */
    {
        pq->rear->next = newNode; /* 마지막 노드가 새 노드를 가리킨다 */
        pq->rear = newNode; /* rear가 새노드를 가리킨다 */
    }
}

Data Dequeue(Queue * pq)
{
    Node * delNode;
    Data RData;

    if(QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }

    delNode = pq->front;
    RData = delNode->data;
    pq->front = pq->front->next;

    free(delNode);
    return RData;
}

Data QPeek(Queue * pq)
{
    if(QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }

    return pq->front->data;
}