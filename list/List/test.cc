#include "List.h"

using namespace wd;

int main()
{
    ListNode* head = nullptr;
    initList(&head);
    showList(head);

    int arr[12] = {1,2,3,9,8,7,4,5,6,345,543, 21};
    initList(&head, arr, sizeof(arr)/sizeof(arr[0]));
    showList(head);
    return 0;
}

