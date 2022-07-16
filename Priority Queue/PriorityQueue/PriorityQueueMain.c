#include <stdio.h>
#include "PriorityQueue.h"
#include <string.h>

int DataPriorityComp(char * ch1, char * ch2)
{
    return strlen(ch2) - strlen(ch1);
}

int main(void)
{
    PQueue pq;
    PQueueInit(&pq, DataPriorityComp);

    PEnqueue(&pq,"I am a boy");
    PEnqueue(&pq,"Korean");
    PEnqueue(&pq,"Hobart");
    PEnqueue(&pq,"Yes");
    PEnqueue(&pq,"Testing");
    PEnqueue(&pq,"Was complete");

    while(!PQIsEmpty(&pq))
        printf("%s \n", PDequeue(&pq));

    return 0;
}