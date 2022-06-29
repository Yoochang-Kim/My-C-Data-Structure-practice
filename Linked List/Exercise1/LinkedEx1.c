#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node * next;
}Node;

int main(void)
{
    Node * head = NULL;
    Node * tail = NULL;
    Node * cur = NULL;
    Node * newNode = NULL;
    int readData;

    while(1)
    {
        printf("자연수 입력:");
        scanf("%d",&readData);
        if(readData < 1)
            break;

        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = readData;
        newNode->next = NULL;
        
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }   
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    //입력 받은 데이터의 출력 과정
    printf("입력 받은 데이터의 전체 출력 \n");
    if (head == NULL)
    {
        printf("저장된 자연수가 존재하지 않습니다. \n");
    }
    else
    {
        cur = head;               // cur이 리스트의 첫 번째 노드를 가리킨다
        printf("%d ", cur->data); //첫 번째 데이터 출력

        while (cur->next != NULL) //연결된 노드가 존재하다면 두 번째 이후의 데이터 출력
        {
            cur = cur->next;          // cur이 다음 노드를 가리키게 한다
            printf("%d ", cur->data); // cur이 가리키는 노드를 출력한다
        }
        printf("\n\n");
    }
}