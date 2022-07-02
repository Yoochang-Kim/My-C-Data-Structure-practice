#include <stdio.h>

typedef int LData;
typedef struct _node 
{
    int data;
}Node;

typedef struct _linkedList
{
    Node * head;
    Node * tail;
    Node * before;
    int numOfData;
    int (*comp)(LData d1, LData d2);
}LinkedList;

int main(){
    return 0;
}

