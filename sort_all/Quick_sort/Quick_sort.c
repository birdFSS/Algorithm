#include <stdio.h>
#define ARRAY_SIZE 10
#define SWAP(x,y) do{ (x)=(x)^(y); (y)=(x)^(y); (x)=(x)^(y); }while(0);



int patition(int *arr, int left, int right)
{
    //找到分隔的数字
    int mid = (left + right) >> 2;
    if(arr[left] > arr[right] && arr[right] > arr[mid])
    {
        SWAP(arr[left], arr[right]);
    }else if(arr[right] > arr[mid] && arr[mid] > arr[left]){
        SWAP(arr[left], arr[mid]);
    }

    int pat = arr[left];
    //将数组中元素分开
    while(left < right)
    {
        while(left < right && arr[right] >= pat) --right;
        arr[left] = arr[right]; //这里需要改一下，因为保留的不是left值了,将结点放到left就好了
        while(left < right && arr[left] <= pat) ++left;
        arr[right] = arr[left];
    }
    //返回分隔数字的下标
    arr[right] = pat;
    return right;
}

int patition0(int *arr, int left, int right)
{
    //找到分隔的数字
    int pat = arr[left];
    //将数组中元素分开
    while(left < right)
    {
        while(left < right && arr[right] >= pat) --right;
        arr[left] = arr[right];
        while(left < right && arr[left] <= pat) ++left;
        arr[right] = arr[left];
    }
    //返回分隔数字的下标
    arr[right] = pat;
    return right;
}

void quick_sort(int *arr, int left, int right)
{
    if(left  > right)
    {
        return;
    }else if(left + 1 == right)
    {
        if(arr[left] > arr[right])
        {
            SWAP(arr[left], arr[right]);
        }
        return;
    }

    int pivotpos = patition(arr, left, right);
    printf("%d\n", pivotpos);
    quick_sort(arr, left, pivotpos-1);
    quick_sort(arr, pivotpos+1, right);
}

int main()
{
    int arr[ARRAY_SIZE] = {0,0,0,17,53,44,9,2,3,0};
    quick_sort(arr, 0, ARRAY_SIZE - 1);
    for(int i=0;i!=ARRAY_SIZE;++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    //printf("%d\n", MID(4,3,1));
    //printf("%d\n", MID(98,76,88));
    return 0;
}

