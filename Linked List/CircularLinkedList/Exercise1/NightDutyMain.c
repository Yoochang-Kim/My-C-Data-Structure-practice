#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Employee.h"
#include "CLinkedList.h"

Employee *WhosTheNightDuty(List *list, char *name, int day);
void showEmployeeInfo(Employee *e);

int main()
{
    Employee *emp;
    int i;

    /* 리스트 생성 및 초기화 */
    List list;
    ListInit(&list);

    /* 4개의 데이터 생성 */
    emp = (Employee *)malloc(sizeof(Employee));
    emp->empNum = 1;
    strcpy(emp->name, "Kim");
    LInsert(&list, emp);
    showEmployeeInfo(emp);

    emp = (Employee *)malloc(sizeof(Employee));
    emp->empNum = 2;
    strcpy(emp->name, "Lee");
    LInsert(&list, emp);
    showEmployeeInfo(emp);

    emp = (Employee *)malloc(sizeof(Employee));
    emp->empNum = 3;
    strcpy(emp->name, "Jang");
    LInsert(&list, emp);
    showEmployeeInfo(emp);

    emp = (Employee *)malloc(sizeof(Employee));
    emp->empNum = 4;
    strcpy(emp->name, "Sam");
    LInsert(&list, emp);
    showEmployeeInfo(emp);

    printf("\n");
    /* Kim 당직 3일뒤 누가 당직? */
    emp = WhosTheNightDuty(&list, "Kim", 3);
    showEmployeeInfo(emp);

    printf("\n");
    /* Lee 당직 30일뒤 누가 당직? */
    emp = WhosTheNightDuty(&list, "Lee", 30);
    showEmployeeInfo(emp);
    /* 할당된 메모리의 전체 소멸 */
    if (LFirst(&list, &emp))
    {
        free(emp);
        for (i = 0; i < LCount(&list) - 1; i++)
            LNext(&list, &emp);
        free(emp);
    }

    return 0;
}

Employee *WhosTheNightDuty(List *list, char *name, int day)
{
    Employee *tmp; /* 주어진 이름을 찾기 위해 일시적으로 만들어진 데이터 */
    int i, num;

    num = LCount(list);

    /* 이름 찾기 */
    LFirst(list, &tmp);
    if (strcmp(tmp->name, name) != 0) /* 첫번째 노드에 이름 없으면 */
    {
        for (i = 0; i < num; i++) /* 다음 노드 확인*/
        {
            LNext(list, &tmp);
            if (strcmp(tmp->name, name) == 0)
                break;
        }
        if (i >= num - 1)
        { /* 해당 이름이 리스트에 없는 경우 */
            return NULL;
        }
    }

    /* 그 뒤로 몇일 뒤 */
    for (i = 0; i < day; i++)
        LNext(list, &tmp);

    return tmp;
}

void showEmployeeInfo(Employee *e)
{
    printf("Employee number : %d\n", e->empNum);
    printf("Employee Name: %s\n", e->name);
}
