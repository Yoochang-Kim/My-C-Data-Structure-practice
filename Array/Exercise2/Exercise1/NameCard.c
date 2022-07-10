#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"

NameCard *MakeNameCard(char *name, char *phone)
{
    NameCard *temp;
    temp = (NameCard *)malloc(sizeof(NameCard));
    strcpy(temp->name,name);
    strcpy(temp->phone,phone);
    return temp;
}

void ShowNameCardInfo(NameCard *pcard)
{
    printf("Card name: %s \nCard phone: %s\n",pcard->name,pcard->phone);
}

//이름이 같으면 0, 다르면 0이 아닌 값 반환
int NameCompare(NameCard *pcard, char *name)
{
    if(strcmp(name,pcard->name) == 0){
        return 0;
    }
    else{
        return -1;
    }
}

//전화번호 정보를 변경
void ChangePhoneNum(NameCard *pcard, char *phone)
{
    strcpy(pcard->phone,phone);
}