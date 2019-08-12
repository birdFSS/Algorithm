#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

typedef int ElemType;

namespace wd
{

class ListNode
{
public:
   ElemType m_val;
   ListNode* m_next;
};

void initList(ListNode** ppHead, int * a = nullptr, int len = 0)
{
    assert(ppHead != nullptr);
    

    if(nullptr != *ppHead)
    {
        ListNode* pCur = *ppHead;
        ListNode* pNext = nullptr;
        while(pCur)
        {
            pNext = pCur->m_next;
            free(pCur);
            pCur = pNext;
        }
        *ppHead = nullptr;
    }

    //初始化链表
    if(a != nullptr)
    {
        for(int i=0;i != len; ++i)
        {
            ListNode* pNew = (ListNode*)malloc(sizeof(ListNode));
            pNew->m_next = nullptr;
            pNew->m_val = a[i];
            if(nullptr == *ppHead)
            {
                *ppHead = pNew;
            }else{
                pNew->m_next = *ppHead;
                *ppHead = pNew;
            }
        }
    }else{
        int arr[10] = {8,21,43,2,3,12,25,32,8, 66};
        initList(ppHead, arr, sizeof(arr)/sizeof(arr[0]));
    }
}

void showList(ListNode* pHead)
{
    while(pHead)
    {
        printf("%d ", pHead->m_val);
        pHead = pHead->m_next;
    }
    printf("\n");
}



}//end of namespace wd

