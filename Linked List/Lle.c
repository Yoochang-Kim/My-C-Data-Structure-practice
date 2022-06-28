#include <stdio.h>
#include <stdlib.h>

typedef struct _wallet{
    int coin100Num;
    int bill5000Num;
}Wallet;

int TakeOutMoney(Wallet *pw, int coinNum, int billNum);
/*
    
*/
void putMoney(Wallet *pw, int coinNum, int billNum);
int main(void)
{
    Wallet w1;
    w1.coin100Num = 5;
    w1.bill5000Num = 2;
    TakeOutMoney(&w1,10,2);
 
    return 0;
}

int TakeOutMoney(Wallet *pw, int coinNum, int billNum)
{
    if (pw->coin100Num - coinNum < 0)
    {
        printf("돈을 꺼낼 수 없습니다.\n");
    }
    else
    {
        printf("현재 남아 있는 코인의 수는 %d입니다.\n", pw->coin100Num);
    }
    if (pw->bill5000Num - billNum < 0)
    {
        printf("돈을 꺼낼 수 없습니다.\n");
    }
    else
    {
        pw->bill5000Num = pw->bill5000Num - billNum;
        printf("현재 남아 있는 지폐의 수는 %d입니다.\n", pw->bill5000Num);
    }
    return 0;
}
