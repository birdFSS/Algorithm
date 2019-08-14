#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 12

void swap(int& a, int & b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

//需要注意一个点，每一次冒泡中保留的点应该在气泡的最后面，而不是最前面
//如果从前往后，那么每次保留最后一个；如果从后往前，每次保留最前面的那个
//i决定保留位，如果i又小到大，那么j要从大到小。反之，i由大到小，j要由小到大
// 
void Bubble_sort(int* arr, int len)
{
    for(int i=len - 1;i != 0;--i)
    {
        for(int j=0; j != i; ++j)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
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
    Bubble_sort(arr, ARRAY_SIZE);
    for(int i=0;i != ARRAY_SIZE; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

