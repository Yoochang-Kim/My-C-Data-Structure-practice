#include <stdio.h>
#include <stdlib.h>
#include "ClinkedList.h"

void ListInit(List * plist)
{
    plist -> tail = NULL;
    plist -> before = NULL;
    plist -> cur = NULL;
    plist ->numOfData = 0;
}

void LInsertFront(List * plist, Data data)
{
    Node * newNode = (Node *)malloc(sizeof(Node)); /* 새 노드 생성 */
    newNode->data = data; /* 새 노드에 데이터 저장 */

    if(plist->tail == NULL) /* 첫 번째 노드라면, */
    {
        plist->tail = newNode;/* tail이 새 노드를 가리키게 한다. */
        newNode -> next = newNode;/* 새 노드 자신을 가리키게 한다 */
    } /* 두 번째 이후의 노드라면, */
    else
    {
        newNode->next = plist->tail->next;/* 새 노드 오른쪽 연결 */
        plist->tail->next = newNode;/* 새 노드 왼쪽 연결 */
    }

    /* 노드의 수 증가  */
    (plist->numOfData)++;
}

void LInsert(List * plist, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));/* 새 노드 생성 */
    newNode->data = data;/* 새 노드에 데이터 저장 */

    if(plist->tail == NULL)/* 첫번째 노드라면 */
    {
        plist->tail = newNode;/* tail이 새 노드를 가리키게 한다 */
        newNode->next = newNode;/* 새 노드 자신을 가리키게 한다 */
    }
    else /* 두번째 이 후의 노드라면 */
    {   
        newNode->next = plist->tail->next;/* 새 노드의 오른쪽 연결 */
        plist->tail->next = newNode;/* 새 노드의 왼쪽 연결 */
        plist->tail = newNode;/* tail이 새로운 노드를 가리키게 한다. */
    }
    /* 노드의 수 증가 */
    (plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
    if(plist->tail==NULL)/*저장된 노드가 없다면 */
    {
        return FALSE;
    }
    plist->before = plist->tail; /* before가 꼬리를 가리키게 한다 */
    plist->cur = plist->tail->next; /* cur이 머리를 가리키게 한다. */
    *pdata = plist->cur->data;/* cur이 가리키는 노드의 데이터 반환 */
    return TRUE;/* 함수 종료 */
}

int LNext(List *plist, Data * pdata)
{
     if(plist->tail ==NULL) /* 저장된 노드가 없다면 */
        return FALSE;
      plist->before = plist->cur;/* before가 다음 노드를 가리키게 한다 */
      plist->cur = plist->cur->next;/* cur이 다음 노드를 가리키게 한다 */

      *pdata = plist->cur ->data;/* cur이 가리키는 노드의 데이터 변환 */
      return TRUE;/* 함수 종료 */
}

Data LRemove(List * plist) 
{
    Node * rpos = plist->cur;/* 소멸되는 노드의 주소값을 rpos에 저장 */
    Data rdata = rpos-> data;/* 소멸되는 노드의 데이터를 rdata에 저장 */

    if(rpos == plist->tail)/* 삭제 대상을 tail이 가리킨다면 */
    {
        if(plist->tail == plist->tail->next)/* 그리고 마지막 남은 노드라면 */
        {
            /* 노드 제거 */
            plist->tail = NULL;
        }
    }else
    {   /* 마지막 남은 노드가 아니면 */
        /* tail이 한칸 뒤로 움직임 */
        plist->tail = plist->before;
    }

    plist->before = plist->cur->next;/* 소멸 대상을 리스트에서 제거 */
    plist->cur = plist->before;/* cur이 가리키는 위치 재조정  */

    free(rpos);/* 리스트에서 제거된 노드 소멸 */
    (plist->numOfData)--;/* 저장된 데이터의 수 감소 */
    return rdata;/* 제거된 노드의 데이터 반환 */
}

int LCount(List * plist)
{
    return plist->numOfData;
}

