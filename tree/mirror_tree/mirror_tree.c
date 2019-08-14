#include <func.h>
typedef int ElemType;
typedef struct node{
    ElemType val;
    struct node *left;
    struct node *right;
}BinaryTreeNode, *BinPNode;

void MirrorRecursively(BinaryTreeNode *pNode){
    if(pNode == NULL){
        return;
    }
    if(pNode->left == NULL && pNode->right == NULL){
        return;
    }

    BinaryTreeNode *pTemp = pNode->left;
    pNode->left = pNode->right;
    pNode->right = pTemp;

    if(pNode->left){
        MirrorRecursively(pNode->left);
    }
    if(pNode->right){
        MirrorRecursively(pNode->right);
    }
}
