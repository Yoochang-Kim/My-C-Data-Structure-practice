#include <stdio.h>

typedef struct _empInfo
{
    int empNum;
    int age;
}EmpInfo;

int GetHash(int empNum)
{
    return empNum % 100;
}

int main(void)
{
    EmpInfo empInfoArr[100];
    
    EmpInfo emp1 = {20120003, 42};
    EmpInfo emp2 = {20140013, 23};
    EmpInfo emp3 = {2006049, 43};

    EmpInfo r1, r2, r3;

    /* 키를 인덱스 값으로 이용해서 저장 */
    empInfoArr[GetHash(emp1.empNum)] = emp1;
    empInfoArr[GetHash(emp2.empNum)] = emp2;
    empInfoArr[GetHash(emp3.empNum)] = emp3;

    /* 키를 인덱스 값으로 이용해서 탐색 */
    r1 = empInfoArr[GetHash(emp1.empNum)];
    r2 = empInfoArr[GetHash(emp2.empNum)];
    r3 = empInfoArr[GetHash(emp3.empNum)];

    printf("사번 %d 나이 %d \n",r1.empNum,r1.age);
    printf("사번 %d 나이 %d \n",r2.empNum,r2.age);
    printf("사번 %d 나이 %d \n",r3.empNum,r3.age);
}