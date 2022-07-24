#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree2.h"

int main(void)
{
    BTreeNode * bstRoot;
    BTreeNode * sNode;

    BSTMakeAndInit(&bstRoot);
    
    BSTInsert(&bstRoot, 5);
    BSTInsert(&bstRoot, 4);
    BSTInsert(&bstRoot, 1);
    BSTInsert(&bstRoot, 7);
    BSTInsert(&bstRoot, 6);
    BSTInsert(&bstRoot, 10);
    BSTInsert(&bstRoot, 9);

    BSTShowAll(bstRoot); printf("\n");
    sNode = BSTRemove(&bstRoot, 4);
    free(sNode);

    BSTShowAll(bstRoot); printf("\n");
    sNode = BSTRemove(&bstRoot, 10);
    free(sNode);

    BSTShowAll(bstRoot); printf("\n");
    sNode = BSTRemove(&bstRoot, 3);
    free(sNode);

    BSTShowAll(bstRoot); printf("\n");
    sNode = BSTRemove(&bstRoot, 2);
    free(sNode);

    BSTShowAll(bstRoot);printf("\n");
    return 0;
}