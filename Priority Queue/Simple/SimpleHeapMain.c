#include <stdio.h>
#include "SimpleHeap.h"

int main(void)
{
    Heap heap;
    HeapInit(&heap); /* 초기화 */

    /* 문자 A를 최고 우선순위로 저장 */
    HInsert(&heap,'A',1);
    /* 문자 B를 두 번째 우선순위로 저장 */
    HInsert(&heap,'B',2);
    /* 문자 C를 세 번째 우선순위로 저장 */
    HInsert(&heap,'C',3);
    printf("%c \n",HDelete(&heap));

    /* 문자 A 한 번 더 저장 */
    HInsert(&heap,'A',1);
    /* 문자 B 한 번 더 저장 */
    HInsert(&heap,'B',2);
    /* 문자 C 한 번 더 저장 */
    HInsert(&heap,'C',3);
     printf("%c \n",HDelete(&heap));

    while(!HIsEmpty(&heap))
    {
        printf("%c \n", HDelete(&heap));
    }
    return 0;
}