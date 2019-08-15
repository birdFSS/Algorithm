#include <func.h>

#define SWAP(x,y) do{(x)=(x)^(y);(y)=(x)^(y);(x)=(x)^(y);}while(0)

void adjustDown(int *arr, int k, int len);


void BuildMaxHeap(int *arr, int len)
{
    for(int i=len/2; i != 0; --i)
    {
        adjustDown(arr, i, len);
    }
}

void adjustDown(int *arr, int k, int len)
{
    arr[0] = arr[k];
    int i = k << 1;
    while(i <= len)
    {
        if(i < len && arr[i] < arr[i+1])
        {
            ++i;
        }
        if(arr[0] >= arr[i]) 
            break;
        else{
            arr[k] = arr[i];
            k = i;
        }
        i <<= 1;
    }
    arr[k] = arr[0];
}

void HeapSort(int *arr, int len)
{
    BuildMaxHeap(arr, len);
    int i;
    for(i = len; i > 1; --i)
    {
        SWAP(arr[i], arr[1]);
        adjustDown(arr, 1, i-1);
    }
}

int main(int argc, char* argv[])
{
    int arr[11] = {0,9,3,7,4,5,6,2,8,1,0};
    HeapSort(arr, 10);
    for(int i=1;i !=11; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

