#include "HeapSort.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SWAP(x,y) do{(x)=(x)^(y);(y)=(x)^(y);(x)=(x)^(y);}while(0)

typedef bool (*CompFunc)(const void* a, const void* b);

struct BFHeap{
    ElemType *arr;
    int capacity;
    int size;
    CompFunc comfunc;
};

/* Max Heap
 * 可以根据sink 函数中，cfunc(i, i+1)中，选择大的还是小的，来
 * 判断是大顶堆还是小顶堆。这里可以看到arr[i] < arr[i+1]时，
 * 选择i+1 即大的那个，可以判断是大顶堆
 */
static bool sort_by_ASE(const void* l, const void *r)
{
    int* left = (int *)l;
    int *right = (int *)r;
    return *left < *right;
}

/* Min Heap
 * 最小堆，会把最小的放在最后，整体就是降序排列 
 */
static bool sort_by_DESC(const void* l, const void* r)
{
    int* left = (int *)l;
    int *right = (int *)r;
    return *left > *right;
}

/*
 * purpose: 将第k个节点从下往上调整
 *
 */
static void swim(ElemType *arr, int k, CompFunc cfunc) {
    while(k > 1 && cfunc(arr + (k >> 1), arr + k)) {
        SWAP(arr[k >> 1], arr[k]);
        k >>= 1;
    }
}

/*
 * purpose: 将第k个节点从上往下调整
 */
static void sink(ElemType *arr, int k, int len, CompFunc cfunc) {
    arr[0] = arr[k];
    int i = k << 1;
    while(i <= len) {
        if(i < len && cfunc(arr + i, arr + i + 1)) {
            ++i;
        }

        if(cfunc(arr, arr + i)) {
            arr[k] = arr[i];
            k = i;
        }else{
            break;
        }
        i <<= 1;
    }
    arr[k] = arr[0];
}

void HeapSort2(ElemType *arr, int len, enum BF_HEAP_TYPE type)
{
    CompFunc cfunc = (type == BF_MAX_HEAP ? sort_by_ASE : sort_by_DESC);
    int i;

    for(i = len >> 1; i != 0; --i)
    {
        sink(arr, i, len - 1, cfunc);
    }

    for(i = len - 1; i > 1; --i)
    {
        SWAP(arr[i], arr[1]);
        sink(arr, 1, i-1, cfunc);
    }

    for(i = 1; i < len; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

BFHeap* bfCreateHeap(int size, enum BF_HEAP_TYPE type)
{
    BFHeap *p = (BFHeap*)malloc(sizeof(BFHeap));
    if(!p){
        return NULL;
    }

    p->arr = (ElemType *)malloc(sizeof(ElemType) * (size + 1));
    if(!p->arr){
        free(p);
        return NULL;
    }

    p->capacity = size + 1;
    p->size = 0;
    p->comfunc = (BF_MAX_HEAP == type ? sort_by_ASE : sort_by_DESC);
    return p; 
}

bool bfIsEmpty(BFHeap* pHeap){
    assert(NULL != pHeap);
    return 0 == pHeap->size;
}

bool bfIsFull(BFHeap* pHeap){
    assert(NULL != pHeap);
    return pHeap->capacity == pHeap->size;
}

bool bfPush(BFHeap* pHeap, ElemType val){
    assert(NULL != pHeap);
    if(bfIsFull(pHeap)){
        return false;
    }
    pHeap->arr[++pHeap->size] = val;
    swim(pHeap->arr, pHeap->size, pHeap->comfunc);
    return true;
}

ElemType bfTop(BFHeap* pHeap){
    assert(NULL != pHeap);
    if(bfIsEmpty(pHeap)){
        return false;
    }
    return pHeap->arr[1];
}

ElemType bfPop(BFHeap* pHeap) {
    assert(NULL != pHeap);
    if(bfIsEmpty(pHeap)){
        return 0; 
    }

    ElemType ret = pHeap->arr[1];

    SWAP(pHeap->arr[1], pHeap->arr[pHeap->size]);
    --pHeap->size;
    sink(pHeap->arr, 1, pHeap->size, pHeap->comfunc);
    return ret;
}

int bfSize(BFHeap* pHeap){
    assert(NULL != pHeap);
    return pHeap->size;
}

void bfHeapFree(BFHeap* pHeap){
    assert(NULL != pHeap);
    free(pHeap->arr);
    pHeap->arr = NULL;
    free(pHeap);
}

void HeapSort(ElemType *arr, int len, enum BF_HEAP_TYPE type){
    BFHeap *pHeap = bfCreateHeap(len, type);
    int i;
    for(i = 0; i < len; ++i){
        bfPush(pHeap, arr[i]);
    }

    for(i = len - 1; i >= 0; --i){
        if(!bfIsEmpty(pHeap)){
            arr[i] = bfPop(pHeap);
        }else{
            printf("error: heap is empty\n");
        }
    }
}
