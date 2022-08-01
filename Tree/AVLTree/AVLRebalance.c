#include <stdio.h>
#include "BinaryTree3.h"

//LL 회전
BTreeNode * RotateLL(BTreeNode * bst)
{
   BTreeNode * pNode;
   BTreeNode * cNode;

   pNode = bst;
   cNode = GetLeftSubTree(pNode);

   //LL회전
   ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
   ChangeRightSubTree(cNode, pNode);

    //변경된 루트 노드의 주소값 반환
    return cNode;
 }

//RR
BTreeNode * RotateRR(BTreeNode * bst)
{
    BTreeNode * pNode;
    BTreeNode * cNode;

    pNode = bst;
    cNode = GetRightSubTree(pNode);

    ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
    ChangeLeftSubTree(cNode, pNode);

    return cNode;
}
//RL
BTreeNode * RotateRL(BTreeNode * bst){
    BTreeNode * pNode;
    BTreeNode * cNode;

    pNode = bst;
    cNode = GetRightSubTree(pNode);

    ChangeRightSubTree(cNode, RotateLL(cNode)); //부분적 LL회전 후 다시 오른쪽에 붙임 
    return RotateRR(pNode); //RR 회전 
}
//LR
BTreeNode * RotateLR(BTreeNode * bst)
{
    BTreeNode * pNode;
    BTreeNode * cNode;

    pNode = bst;
    cNode = GetLeftSubTree(pNode);

    ChangeLeftSubTree(cNode, RotateRR(cNode)); //부분적 RR회전 후 다시 왼쪽에 붙임 
    return RotateLL(pNode); //LL 회전 
}

//트리 높이 반환
int GetHeight(BTreeNode * bst){
    int leftH; //left height
    int rightH; //right height

    if(bst == NULL)
        return 0;
    
    leftH = GetHeight(GetLeftSubTree(bst));
    rightH = GetHeight(GetRightSubTree(bst));
    
    //큰값의 높이를 반환 
    if(leftH > rightH)
        return leftH + 1;
    else
        return rightH + 1;
}

//두 서브 트리의 높이의 차 반환
int GetHeightDiff(BTreeNode * bst)
{
    int lsh; //left sub tree height
    int rsh; //right sub tree height

    if(bst == NULL)
        return 0;

    lsh = GetHeight(GetLeftSubTree(bst)); //왼쪽 서브 트리 높이
    rsh = GetHeight(GetRightSubTree(bst)); //오른쪽 서브 트리 높이

    return lsh - rsh; //균형 인수 계산결과 반환
}

// 트리의 균형을 잡음
BTreeNode * Rebalance(BTreeNode ** pRoot)
{
    int hDiff = GetHeightDiff(*pRoot); //균형 인수 계산

    //균형 인수가 +2 이상이면 LL or LR
    if(hDiff > 1) //왼쪽 서브 트리 방향으로 높이가 2이상 크다면
    {
        if(GetHeightDiff(GetLeftSubTree(*pRoot)) > 0) //LL
            *pRoot = RotateLL(*pRoot); //LL rotate
        else //LR
            *pRoot = RotateLR(*pRoot); //LR rotate
    }

    //균형 인수가 -2이하 이면 RR or RL
    if(hDiff < -1) //오른쪽 서브트리 방향으로 2이상 크다면
    {
        if(GetHeightDiff(GetRightSubTree(*pRoot)) < 0) //RR
            *pRoot = RotateRR(*pRoot);
        else//RL
            *pRoot = RotateRL(*pRoot);
    }

    return *pRoot;
}