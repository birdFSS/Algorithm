#include "../List/List.h"
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

ListNode* findLoopBegin(ListNode* head)
{
    ListNode* n1 = head;
    ListNode* n2 = head;
    while(n2 != nullptr && n2->m_next != nullptr)   //n2 != nullptr 是需要的，不然当n2为空，n2->next 直接崩溃了
    {
        n1 = n1->m_next;
        //printf("n2->val = %d\n", n2->m_val);
        n2 = n2->m_next->m_next;
        if(n1 == n2)
        {
            break;
        }
    }

    if(n2 == nullptr || n2->m_next == nullptr)
    {
        return nullptr;
    }

    n1 = head;
    while(n1 != n2)
    {
        n1 = n1->m_next;
        n2 = n2->m_next;
    }
    return n2;
}

int main()
{
    ListNode* head = nullptr;
    initList(&head);
    ListNode* tail = head;
    while(tail->m_next)
    {
        tail= tail->m_next;
    }
    tail->m_next = head->m_next->m_next;
    cout << findLoopBegin(head)->m_val << endl;
    return 0;
}

