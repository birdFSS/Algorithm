#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <assert.h>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

struct ListNode{

    ListNode(int val, ListNode* pNode) : 
        _val(val), _next(pNode)
    {

    }
    int _val;
    ListNode* _next;
};

void printList(ListNode* p)
{
    assert(p != NULL);
    if(p->_next != NULL)
    {
        printList(p->_next);
    }
    cout << p->_val << " ";
}

int main()
{
    ListNode* node1 = new ListNode(10, nullptr);
    ListNode* head = new ListNode(1, node1);
    printList(head);
    cout << endl;

    delete head;
    delete node1;
    return 0;
}

