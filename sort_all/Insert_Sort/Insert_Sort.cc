#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 12

void swap(int& a, int & b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

//需要保存当前值，找到该值在前面有序序列中的位置，再将其插入。
//每次对比，都是通过下一个元素与当前值做对比
//这里是升序排列
void Insert_sort(int* arr, int len)
{
    int i,j, tmp;
    for(i=1; i!=len; ++i)
    {
        if(arr[i] < arr[i-1])       //先判断一下，是否需要插入
        {
            tmp = arr[i];
            for(j=i-1; j>=0 && tmp < arr[j]; --j)
            {
                arr[j+1] = arr[j];
            }
            arr[j+1] = tmp;
        }
    }
}

//希尔排序
void xier_sort(int* arr, int len)
{
    int dk, i, k,tmp;
    for(dk=len/2; dk>=1; dk/=2)
    {
        for(i=dk; i<len; ++i)
        {
            if(arr[i] < arr[i-dk])
            {
                tmp = arr[i];
                for(k=i-dk; k>=0 && tmp < arr[k]; k-=dk)
                {
                    arr[k+dk] = arr[k];
                }
                arr[k+dk] = tmp;
            }
        }
    }
}

//希尔排序 带哨兵数组arr[0]
void xier_sort_with_guard(int* arr, int len)
{
    int dk, i,k;
    for(dk=len/2; dk>=1; dk/=2)
    {
        for(i=dk+1; i<len; ++i)
        {
            if(arr[i] < arr[i-dk])
            {
                arr[0] = arr[i];
                for(k=i-dk; k>=0 && arr[0] < arr[k]; k-=dk)
                {
                    arr[k+dk] = arr[k];
                }
                arr[k+dk] = arr[0];
            }
        }
    }
}

void test0()
{
    int arr[ARRAY_SIZE] = {11,12,5,4,3,6,7,2,8,1,9,2};
    for(int i=0;i != ARRAY_SIZE; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    //Insert_sort(arr, ARRAY_SIZE);
    xier_sort(arr, ARRAY_SIZE);
    for(int i=0;i != ARRAY_SIZE; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

}

void test1()
{
    int arr[ARRAY_SIZE] = {0,12,5,4,3,6,7,2,8,1,9,2};
    for(int i=1;i != ARRAY_SIZE; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    //Insert_sort(arr, ARRAY_SIZE);
    xier_sort_with_guard(arr, ARRAY_SIZE);
    for(int i=1;i != ARRAY_SIZE; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

}
int main()
{
    test1();
    return 0;
}

