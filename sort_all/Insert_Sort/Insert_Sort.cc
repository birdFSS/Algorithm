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
void Insert_sort(int* arr, int len)
{
    for(int i=1; i!=len; ++i)
    {
        int tmp = arr[i];
        int j;
        for(j=i; j!=0; --j)
        {
            if(tmp < arr[j-1])
            {
                arr[j] = arr[j-1];
            }else{
                break;
            }
        }
        arr[j] = tmp;
    }
}

//希尔排序
void xier_sort(int* arr, int len)
{
    for(int i=1; i!=len; ++i)
    {
        int tmp = arr[i];
        int j;
        for(j=i; j!=0; --j)
        {
            if(tmp < arr[j-1])
            {
                arr[j] = arr[j-1];
            }else{
                break;
            }
        }
        arr[j] = tmp;
    }
}


int main()
{
    int arr[ARRAY_SIZE] = {11,12,5,4,3,6,7,2,8,1,9,2};
    for(int i=0;i != ARRAY_SIZE; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    Insert_sort(arr, ARRAY_SIZE);
    for(int i=0;i != ARRAY_SIZE; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

