#include <stdio.h>
#include "CircularQueue.h"

int main(void)
{
    /* Queue의 생성 및 초기화 */
    Queue queue;
    QueueInit(&queue);

    /* 데이터 넣기 */   
    Enqueue(&queue,1);
    Enqueue(&queue,2);
    Enqueue(&queue,3);
    Enqueue(&queue,4);
    Enqueue(&queue,5);
    Enqueue(&queue,6);

    /* 데이터 꺼내기 */
    Dequque(&queue);
    Dequque(&queue);
    Dequque(&queue);
    Dequque(&queue);
    Dequque(&queue);
    Dequque(&queue);
    Dequque(&queue);
    Dequque(&queue);
    return 0;
}