#include "../BinaryTree/BinaryTree.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using namespace wd;

struct Result{
    int nMaxDistance;
    int nMaxDepth;
};

Result GetMaxDistance(TreeNode* root)
{
    if(!root)
    {
        Result empty = {0, -1};
        return empty;
    }
    Result lhs = GetMaxDistance(root->left);
    Result rhs = GetMaxDistance(root->right);
    Result ret;
    ret.nMaxDepth = std::max(lhs.nMaxDepth + 1, rhs.nMaxDepth + 1);
    ret.nMaxDistance = std::max(std::max(lhs.nMaxDistance, rhs.nMaxDistance), lhs.nMaxDepth + rhs.nMaxDepth + 2);
    return ret;
}

int main()
{
    int preOrder[6] = {3,2,1,7,5,6};
    int inOrder[6] = {1,2,7,3,6,5};
    TreeNode* root = buildBinaryTreeByPreorderAndInorder(preOrder, inOrder, 6);
    PreOrder(root);
    Result ret = GetMaxDistance(root);
    printf("\nmax distance=%d\n", ret.nMaxDistance);

    return 0;
}

