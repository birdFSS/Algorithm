#include "BinaryTree.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace wd;

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
void test0();

int main()
{
    test0();
    return 0;
}

void test0()
{
    int preOrder[5] = {3,2,1,5,6};
    int inOrder[5] = {1,2,3,6,5};
    TreeNode* root = buildBinaryTreeByPreorderAndInorder(preOrder, inOrder, 5);
    PreOrder(root);
    printf("\n");
    InOrder(root);
    printf("\n");
    PostOrder(root);
    printf("\n");
}

