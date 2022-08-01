#include<stdio.h>
#include<stdlib.h>
#include "Person.h"
#include "Table.h"

int myHashFunc(int k)
{
    return k % 100;
}

int main(void)
{
    Table myTbl;
    Person * np;
    Person * sp;
    Person * rp;

    TBLInit(&myTbl, myHashFunc);

    /* 데이터 입력 */
    np = MakePersonData(2012003, "Hans", "Hobart");
    TBLInsert(&myTbl, GetSSN(np),np);

    sp = MakePersonData(20150042,"Yuun","Melbourne");
    TBLInsert(&myTbl,GetSSN(sp),sp);
    
    rp = MakePersonData(2010005, "Lee", "Sydeny");
    TBLInsert(&myTbl,GetSSN(rp),rp);

    /* 데이터 탐색 */
    sp = TBLSearch(&myTbl,20120003);
    if(sp != NULL)
        ShowPerInfo(sp);
        
    sp = TBLSearch(&myTbl,20150042);
    if(sp != NULL)
        ShowPerInfo(sp);

    sp = TBLSearch(&myTbl,2010005);
    if(sp != NULL)
        ShowPerInfo(sp);

    /* 데이터 삭제 */
    rp = TBLDelete(&myTbl,20150042);
    if(rp != NULL)
        free(rp);
        
    rp = TBLDelete(&myTbl,20120003);
    if(rp != NULL)
        free(rp);
        
    rp = TBLDelete(&myTbl,2010005);
    if(rp != NULL)
        free(rp);
    
    return 0;

}
