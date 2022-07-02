#include <stdio.h>
#include "DLinkedList.h"

int main(void)
{
    /* 리스트의 생성 및 초기화 */
    List list;
    ListInit(&list);
    int data;
    /* 5개의 데이터 저장 */
    FInsert(&list,4);
    FInsert(&list,10);
    FInsert(&list,20);
    FInsert(&list,30);
    FInsert(&list,14);

    /* 저장된 데이터의 전체 출력 */
    if(LFist(&list, &data))
    {
        printf("%d ",data);
        
        while(LNext(&list,data))
            printf("%d ",data);
    }
    /* 숫자 22을 검색하여 모두 삭제 */


    /* 삭제 후 남아있는 데이터 전체 출력 */

}