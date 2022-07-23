#include <stdio.h>
#include "BinaryTree2.h"
#include "BinarySearchTree.h"

void BSTMakeAndInit(BTreeNode ** pRoot)
{
    *pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst)
{
    return GetData(bst);
}

/* BST를 대상으로 데이터 저장(노드의 생성과정 포함) */
void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
    BTreeNode * pNode = NULL; //Parent node
    BTreeNode * cNode = *pRoot; //current node
    BTreeNode * nNode = NULL; // new node

    /* 새로운 노드가(새 데이터가 담긴 노드가) 추가될 위치를 찾는다 */
    while(cNode !=NULL)
    {
        if(data == GetData(cNode))
            return; //데이터의(키의) 중복을 허용하지 않는다
        
        pNode = cNode;

        if(GetData(cNode) > data)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }

    /* pNode의 자식 노드로 추가할 새 노드 생성 */
    nNode = MakeBTreeNode();
    SetData(nNode,data);

    /* pNode의 자식 노드로 새 노드를 추가 한다 */
    if(pNode != NULL) /* 새노드가 루트 노드가 아니라면, */
    {
        if(data < GetData(pNode))
            MakeLeftSubTree(pNode, nNode);
        else
            MakeRightSubTree(pNode, nNode);
    }
    else
    {
        *pRoot = nNode;
    }
}

/* BST를 대상으로 데이터 탐색 */
BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
    BTreeNode * cNode = bst; //current node
    BSTData cd; //current daㅈta

    while(cNode != NULL)
    {
        cd = GetData(cNode);

        if(target == cd)
            return cNode;
        else if(target < cd)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }
    return NULL; //탐색 대상이 저장되어 있지 않음.
}