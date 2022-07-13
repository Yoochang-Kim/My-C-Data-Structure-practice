#include <stdio.h>
#include "BinaryTree.h"

void InorderTraverse(BTreeNode * self)
{
    if(self == NULL) /* bt가 NULL이면 재귀 탈출 */
        return;
    InorderTraverse(self->left); /* 1단계 왼쪽 서브 트리의 순회 */
    printf("%d \n", self->data); /* 2단계 루트 노드의 방문 */
    InorderTraverse(self->right); /* 3단계 오른쪽 서브 트리의 순회 */
}

void PreorderTraverse(BTreeNode * self)
{
    if(self == NULL) /* 재귀 탈출문 */
        return;
    printf("%d \n",self->data); /* 전위 순회이므로 루트 노드 먼저 방문 */
    PreorderTraverse(self->left); /* 왼쪽 서브 트리 순회 */
    PreorderTraverse(self->right); /*오른쪽 서브 트리 순회 */
}

void PostorderTraverse(BTreeNode * self)
{
    if(self == NULL)
        return;
    PostorderTraverse(self->left);
    PostorderTraverse(self->right);
    printf("%d \n", self->data); /* 후위 순회이므로 루트 노드 나중에 방문 */

}


int main(void)
{
    BTreeNode * bt1 = MakeBTreeNode(); /* 노드 bt1 생성 */
    BTreeNode * bt2 = MakeBTreeNode(); /* 노드 bt2 생성 */
    BTreeNode * bt3 = MakeBTreeNode(); /* 노드 bt3 생성 */
    BTreeNode * bt4 = MakeBTreeNode(); /* 노드 bt4 생성 */

    SetData(bt1,1); /* 노드에 데이터 저장 */
    SetData(bt2,2);
    SetData(bt3,3);
    SetData(bt4,4);

    MakeLeftSubTree(bt1, bt2); /* bt2를 bt1의 왼쪽 자식 노드로 */
    MakeRightSubTree(bt1, bt3); /* bt3를 bt1의 오른쪽 자식 노드로 */
    MakeLeftSubTree(bt2,bt4); /* bt4를 bt2의 오른쪽 자식 노드로 */

    InorderTraverse(bt1);


}