#include "../BinaryTree/BinaryTree.h"
#include <string.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cout;
using std::to_string;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using namespace wd;

class Solution {
public:
    char* Serialize(TreeNode *root) {    
        if(nullptr == root)
        {
            char* s = new char[2]();
            s[0] = '#';
            return s;

        }
        string str;
        SerializeCore(root, str);
        char* p = new char[str.size() + 1]();
        strcpy(p , str.c_str());
        return p;

    }

    void SerializeCore(TreeNode* root, string& str)
    {
        if(nullptr == root)
        {
            str.append("#");
            return ;

        }

        str.append(to_string(root->val) + "!");
        SerializeCore(root->left, str);
        SerializeCore(root->right, str);

    }

    TreeNode* Deserialize(char *str) {
        if(nullptr == str)
        {
            return nullptr;
        }

        TreeNode* root = DeserializeCore(&str);
        return root;
    }

    TreeNode* DeserializeCore(char** str)
    {
        if(**str == '#')
        {
            ++(*str);   //每次访问后要加1,
            return nullptr;
        }

        TreeNode* pNode = new TreeNode();
        pNode->val = getNum(str);
        pNode->left = DeserializeCore(str);
        pNode->right = DeserializeCore(str);
        return pNode;
    }

    int getNum(char** str)
    {
        assert(str != nullptr && *str != nullptr);

        int num = 0;
        while(**str != '!')
        {
            num = num * 10 + (**str - '0');
            ++(*str);
        }
        ++(*str);
        return num;
    }

};

void test1();
int main()
{
    test1();
    return 0;
}

void test(){
    char* str = new char[10]();
    strcpy(str, "5324189!");
    Solution s;
    cout << s.getNum(&str) << endl; 
    delete [] str;
}

void test1()
{
    char* str = new char[11]();
    strcpy(str, "5!3!##4!##");
    Solution s;
    TreeNode* root = s.Deserialize(str);
    PreOrder(root); 
    printf("\n");

    char* p = s.Serialize(root);
    printf("serialize=%s\n", p);
    delete [] str;
}

