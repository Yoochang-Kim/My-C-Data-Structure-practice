#include <stdio.h>
#include <stdlib.h>
#include "NameCard.h"
#include "ArrayList.h"

int main(void)
{
    NameCard *ncp;
    List list;
    ListInit(&list);

    // 3명의 전화번호 정보를 리스트에 저장
    ncp = MakeNameCard("Yoochang Kim", "0415-112-23");
    LInsert(&list, ncp);

    ncp = MakeNameCard("Hyemin Jang", "0413-123-213");
    LInsert(&list, ncp);

    ncp = MakeNameCard("Json", "0482-32-122");
    LInsert(&list, ncp);

    // Yoochang Kim 정보 출력
    if (LFirst(&list, &ncp))
    {
        if (!NameCompare(ncp, "Yoochang Kim"))
            ShowNameCardInfo(ncp);
        while (LNext(&list, &ncp))
        {
            if (!NameCompare(ncp, "Yoochang Kim"))
                ShowNameCardInfo(ncp);
        }
    }

    // Heymin Jang 전화번호 변경
    if (LFirst(&list, &ncp))
    {
        if (!NameCompare(ncp, "Hyemin Jang"))
        {
            ChangePhoneNum(ncp, "changed numbers:03030-2312-32");
        }
        while (LNext(&list, &ncp))
        {
            if (!NameCompare(ncp, "Hyemin Jang"))
            {
                ChangePhoneNum(ncp, "changed numbers:03030-2312-32");
            }
        }
    }

    // Jason 탐색 후, 정보 삭제
    if (LFirst(&list, &ncp))
    {
        if (!NameCompare(ncp, "Json"))
        {
            ncp = LRemove(&list);
            free(ncp);
        }
        while (LNext(&list, &ncp))
        {
            if (!NameCompare(ncp, "Json"))
            {
                ncp = LRemove(&list);
                free(ncp);
            }
        }
    }
    return 0;
}