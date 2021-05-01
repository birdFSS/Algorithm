#include "HeapSort.h"
#include <stdio.h>

#define SWAP(x,y) do{(x)=(x)^(y);(y)=(x)^(y);(x)=(x)^(y);}while(0)

void hsAdjust(ElemType *arr, size_t k, size_t len, compFunc cfunc)
{
    arr[0] = arr[k];
    size_t i = k << 1;
    while(i < len) {
        if(i < len - 1 && cfunc(arr + i, arr + i + 1)) {
            ++i;
        }

        if(!cfunc(arr, arr + i)) {
            break;
        }else{
            arr[k] = arr[i];
            k = i;
        }
        i <<= 1;
    }
    arr[k] = arr[0];
}

void hsBuildHeap(ElemType *arr, size_t len, compFunc cfunc)
{
    for(size_t i = len >> 1; i != 0; --i)
    {
        hsAdjust(arr, i, len, cfunc);
    }
}

void HeapSort(ElemType *arr, size_t len, compFunc cfunc)
{
    hsBuildHeap(arr, len, cfunc);
    int i;
    for(i = len; i > 1; --i)
    {
        SWAP(arr[i], arr[1]);
        hsAdjust(arr, 1, i-1, cfunc);
    }
}
