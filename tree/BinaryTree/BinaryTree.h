#pragma once
#include <vector>
#include <exception>
#include <stdexcept>


namespace wd
{

class BinaryTreeNode
{
public:
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(int x = 0) : val(x), left(nullptr), right(nullptr)
    {}
};

typedef BinaryTreeNode TreeNode;

TreeNode* ConstructCore(int * startPreorder, int *endPreorder, int *startInorder, int* endInorder);

void InOrder(TreeNode* root)
{
    if(root)
    {
        InOrder(root->left);
        printf("%d ", root->val);
        InOrder(root->right);
    }
}
void PreOrder(TreeNode* root)
{
    if(root)
    {
        printf("%d ", root->val);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PostOrder(TreeNode* root)
{
    if(root)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ", root->val);
    }
}


TreeNode* buildBinaryTreeByPreorderAndInorder(int *preorder, int *inorder, int length)
{
    if(nullptr == preorder || nullptr == inorder || length <= 0)
    {
        return nullptr;
    }
    return ConstructCore(preorder, preorder+length-1, inorder, inorder+length-1);
}

TreeNode* ConstructCore(int * startPreorder, int *endPreorder, int *startInorder, int* endInorder)
{
    int rootValue = startPreorder[0];
    TreeNode* root = new TreeNode(rootValue);//新结点
    //边界条件
    if(startPreorder == endPreorder)
    {
        if(startInorder == endInorder && *startInorder == *startPreorder)
        {
            return root;
        }else{
            throw std::runtime_error("Invalid input.");//非法输入
        }
    }
    //中序遍历中找到根结点的值
    int * rootInorder = startInorder;
    while(rootInorder <= endInorder && *rootInorder != rootValue)
    {
        ++rootInorder;
    }

    if(rootInorder == endInorder && *rootInorder != rootValue)
    {
        throw std::runtime_error("Invalid input");
    }

    int leftLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder + leftLength;
    //构建左子树
    if(leftLength > 0)
    {
        root->left = ConstructCore(startPreorder+ 1, leftPreorderEnd, startInorder, rootInorder - 1);
    }
    
    //构建右子树
    if(leftLength < endPreorder - startPreorder)
    {
        root->right = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder+1, endInorder);
    }
    return root;
}

}//end of namespace wd

