#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "Point.h"
int compare(Point *p1, Point *p2)
{
    if (p1->xpos < p2->xpos)
        return 0;
    if (p1->xpos == p2->xpos)
        if (p1->ypos < p2->ypos)
            return 0;
        else
            return -1;
    return -1;
}
int main(void)
{
    List list;
    Point compPos;
    Point *ppos;
    ListInit(&list);

    SetSortRule(&list, compare);
    // 4개의 데이터 저장
    ppos = (Point *)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 1);
    LInsert(&list, ppos);

    ppos = (Point *)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 2);
    LInsert(&list, ppos);

    ppos = (Point *)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 1);
    LInsert(&list, ppos);

    ppos = (Point *)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 2);
    LInsert(&list, ppos);

    printf("현재 데이터 수 : %d\n", LCount(&list));

    if (LFirst(&list, &ppos))
    {
        ShowPointPos(ppos);

        while (LNext(&list, &ppos))
            ShowPointPos(ppos);
    }

    printf("\n");

    return 0;
}