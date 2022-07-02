#include <stdio.h>
#include "DLinkedList.h"

/* 오른차순으로 정렬할거임 */
int WhoIsPrecede(int d1, int d2)
{
    if(d1 < d2)
        return 0; /* d1이 정렬상 앞선다 */
    else
        return -1;
}

int main()
{
    List list;
    int data;
    ListInit(&list);

    SetSortRule(&list,WhoIsPrecede); //정렬의 기준 등록

    LInsert(&list,11);
    LInsert(&list,22);
    LInsert(&list,11);
    LInsert(&list,22);
    LInsert(&list,33);

    printf("현재 데이터 수 : %d\n",LCount(&list));

    if(LFirst(&list,data))
    {
        printf("%d ",data);

        while(LNext(&list,&data))
            printf("%d ", data);
    }
    printf("\n\n")
}
