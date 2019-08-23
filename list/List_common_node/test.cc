#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

class ListNode
{
public:
    int val;
    ListNode* next;
};

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2 ) 
    {
        if(nullptr == pHead1 || nullptr == pHead2)
        {
            return nullptr;

        }

        int len1 = 0;
        int len2 = 0;
        ListNode* pNode = pHead1;
        while(pNode)
        {
            pNode = pNode->next;
            ++len1;

        }
        pNode = pHead2;
        while(pNode)
        {
            pNode = pNode->next;
            ++len2;

        }

        if(len1 > len2)
        {
            pNode = getCommonNode(pHead1, pHead2, len1 - len2);

        }else{
            pNode = getCommonNode(pHead2, pHead1, len2 - len1);

        }
        return pNode;

    }

    ListNode* getCommonNode(ListNode* p1, ListNode* p2, int k)
    {
        ListNode* pNode = p1;
        while(k-- > 0)
        {
            pNode = pNode->next;

        }

        ListNode* pNode2 = p2;
        while(pNode != pNode2)
        {
            pNode = pNode->next;
            pNode2 = pNode2->next;

        }
        return pNode;

    }

};

int main()
{

    return 0;
}

