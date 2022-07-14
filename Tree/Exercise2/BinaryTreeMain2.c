#include <stdio.h>
#include "BinaryTree2.h"

void ShowIntData(int data);
void DeleteTree(BTreeNode * bt);
int main(void)
{
    BTreeNode * bt1 = MakeBTreeNode(); /* 노드 bt1 생성 */
    BTreeNode * bt2 = MakeBTreeNode(); /* 노드 bt2 생성 */
    BTreeNode * bt3 = MakeBTreeNode(); /* 노드 bt3 생성 */
    BTreeNode * bt4 = MakeBTreeNode(); /* 노드 bt4 생성 */
    BTreeNode * bt5 = MakeBTreeNode(); /* 노드 bt5 생성 */
    BTreeNode * bt6 = MakeBTreeNode(); /* 노드 bt6 생성 */

    SetData(bt1,1); /* 노드에 데이터 저장 */
    SetData(bt2,2);
    SetData(bt3,3);
    SetData(bt4,4);
    SetData(bt5,5);
    SetData(bt6,6);

    MakeLeftSubTree(bt1, bt2); /* bt2를 bt1의 왼쪽 자식 노드로 */
    MakeRightSubTree(bt1, bt3); /* bt3를 bt1의 오른쪽 자식 노드로 */
    MakeLeftSubTree(bt2,bt4); /* bt4를 bt2의 오른쪽 자식 노드로 */
    MakeRightSubTree(bt2,bt5); /* bt4를 bt2의 오른쪽 자식 노드로 */
    MakeRightSubTree(bt3,bt6); /* bt4를 bt2의 오른쪽 자식 노드로 */

    DeleteTree(bt1);
    printf("\n");
    return 0;

}

void ShowIntData(int data)
{
    printf("%d ", data);
}

void DeleteTree(BTreeNode * bt)
{
    BTreeNode * Ltmp = bt->left;
    BTreeNode * Rtmp = bt->right;
    if(bt==NULL) return;

    DeleteTree(Ltmp);
    DelteTree(Rtmp);

    printf("del tree data: %d \n", bt->data);
    free(bt);
}