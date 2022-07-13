#include <stdio.h>

void Reculsive(int num)
{
    if(num <= 0) /* 재귀의 탈출 조건 */
        return;   /* 재귀 탈출 */
    printf("Recursice call! %d \n",num);
    Reculsive(num-1);
}
int main()
{

   Reculsive(4);
   return 0;    
}