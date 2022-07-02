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
