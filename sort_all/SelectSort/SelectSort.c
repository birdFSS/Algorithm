#include <stdio.h>
#define SWAP(x,y) do{ (x)=(x)^(y); (y)=(x)^(y); (x)=(x)^(y); }while(0)

void SelectSort(int *arr, int len)
{
    for(int i=0; i < len; ++i)
    {
        int min = i;
        for(int j = i+1;j < len; ++j)
        {
            if(arr[min] > arr[j]) min = j;
        }
        if(min != i)
        {
            SWAP(arr[i], arr[min]);
        }
    }
}

int main(int argc, char* argv[])
{
    int arr[10] = {32,43,12,32,48,77,89,65,54,29};
    SelectSort(arr, 10);
    for(int i=0;i<10;++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

