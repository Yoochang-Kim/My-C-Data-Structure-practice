#include "ListBaseStack.h"
#include "BinaryTree2.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
BTreeNode * MakeExpTree(char exp[])
{
    Stack stack;
    BTreeNode * pnode;

    int expLen = strlen(exp); /* 문자 수 저장 ex) "23*4+7"은 6개의 문자 수*/
    int i;

    StackInit(&stack);

    for(i=0; i<expLen; i++)
    {
        pnode = MakeBTreeNode();

        if(isdigit(exp[i])) /* 피연산자라면 */
        {
            SetData(pnode, exp[i]-'0'); /* 문자를 정수로 바꿔서 저장 */
        }
        else{/* 연산자라면 */
            MakeRightSubTree(pnode, SPop(&stack));
            MakeLeftSubTree(pnode,SPop(&stack));
            SetData(pnode, exp[i]);
        }

        SPush(&stack,pnode);
    }

    return SPop(&stack);
}
int EvalueExTree(BTreeNode * bt)
{
    int op1, op2;
    
    if(GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL) /* 단말 노드라면 */
        return GetData(bt);

    op1 = EvalueExTree(GetLeftSubTree(bt));
    op2 = EvalueExTree(GetRightSubTree(bt));

    switch(GetData(bt))
    {
        case '+': 
            return op1+op2;
        case '-': 
            return op1-op2;
        case '*':
            return op1*op2;
        case '/':
            return op1/op2;
    }

    return 0;
}
void ShowNodeData(int data)
{
    if(0<=data && data<=9)
        printf("%d ",data); /* 피연산자 출력 */
    else
        printf("%c ", data); /* 연산자 출력 */
}

void ShowPrefixTypeExp(BTreeNode * bt)
{
    PreorderTraverse(bt, ShowNodeData);
}

 /* 중위 표기법 기반 출력 */
void ShowInfixTypeExp(BTreeNode * bt)
{
    if(bt == NULL)
        return;
    if(bt->left !=NULL || bt->right !=NULL)
        printf(" ( ");
    
    ShowInfixTypeExp(bt->left); /* 첫 번째 피연산자 출력 */
    ShowNodeData(bt->data);
    ShowInfixTypeExp(bt->right); /* 두 번째 피연산자 출력 */

    if(bt->left !=NULL || bt->right !=NULL)
        printf(" ) ");
}

/* 후위 표기법 기반 출력 */
void ShowPostfixTypeExp(BTreeNode * bt)
{
    PostorderTraverse(bt, ShowNodeData);
} 