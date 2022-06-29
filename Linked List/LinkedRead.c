#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data; //데이터 담는 공간
    struct _node * next; //연결 도구
} Node;

int main(void)
{
    Node * head = NULL; //리스트 머리를 가리키는 포인터 변수
    Node * tail = NULL; //리스트 꼬리를 가리키는 포인터 변수
    Node * cur = NULL; //저장된 데이터의 조회에 사용되는 포인터 변수
    
    Node * newNode = NULL;
    int readData;

    //데이터를 입력 받는 과정
    while(1)
    {
        printf("자연수 입력: ");
        scanf("%d", &readData);
        if(readData < 1)
            break;
        
        //노드의 추가 과정
        newNode = (Node*)malloc(sizeof(Node)); //노드의 생성
        newNode->data = readData; //노드에 데이터 저장
        newNode->next = NULL; //노드의 next를 NULL로 초기화

        if(head == NULL) //첫 번째 노드라면
            head = newNode; //첫 번쨰 노드를 head가 가리키게 함
        else //두 번째 이후 노드라면
            tail->next = newNode;
        
        tail = newNode; //노드의 끝을 tail이 가리키게 함
    }

    //입력 받은 데이터의 출력 과정
    printf("입력 받은 데이터의 전체 출력 \n");
    if(head == NULL)
    {
        printf("저장된 자연수가 존재하지 않습니다. \n");
    }
    else
    {
        cur = head; // cur이 리스트의 첫 번째 노드를 가리킨다
        printf("%d ", cur->data); //첫 번째 데이터 출력

        while(cur->next != NULL) //연결된 노드가 존재하다면 두 번째 이후의 데이터 출력
        {
            cur = cur->next; //cur이 다음 노드를 가리키게 한다
            printf("%d ", cur->data); //cur이 가리키는 노드를 출력한다
        }
        printf("\n\n");
    }

    //메모리의 해체과정
    if(head == NULL)
    {
        return 0; //삭제할 노드가 존재하지 않는다
    }
    else
    {
        Node *delNode = head;
        Node *delNextNode = head->next;

        printf("%d을(를) 삭제합니다. \n",head->data);
        free(delNode); //첫번 째 노드 삭제

        while(delNextNode != NULL)//두 번째 이후 노드 삭제 , delNextNode를 참조하여 추가로 삭제할 노드가 있는지 확인한다 
        {
            delNode = delNextNode;
            delNextNode = delNextNode ->next;

            printf("%d을(를) 삭제합니다. \n", delNode->data);
            free(delNode);
        }
    }

    return 0;
}