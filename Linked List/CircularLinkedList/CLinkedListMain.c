#include <stdio.h>
#include "CLinkedList.h"

int main(void)
{
    /* 원형 연결 리스트의 생성 및 초기화 */
    List list;
    int data, i, nodeNum;
    ListInit(&list);

    /* 리스트에 5개의 데이터를 저장 */
    LInsert(&list, 3);
    LInsert(&list, 6);
    LInsertFront(&list, 22);
    LInsertFront(&list, 33);
    LInsertFront(&list, 78);

    /* 리스트에 저장된 데이터를 연속 3회 출력 */
    if (LFirst(&list, &data))
    {
        printf("%d ", data);
        for (i = 0; i < LCount(&list) * 3 - 1; i++)
        {
            if (LNext(&list, &data))
                printf("%d ", data);
        }
    }
    printf("\n");

    /* 2의 배수를 찾아서 모두 삭제 */

    /* 전체 데이터 1회 출력 */
}