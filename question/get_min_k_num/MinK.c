/*
 * MinK.c
 * email : ffhbird@gmail.com
 * Copyright (C) 2021 birdfss <ffhbird@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */
#include "HeapSort.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define DEBUG 1

bool buildMaxHeap(const void* pleft, const void* pright)
{
    int left = *(int*)pleft;
    int right = *(int*)pright;
    return left < right;
}

int* getLeastNumbers(int *arr, int arrSize, int k, int* returnSize)
{
    assert(NULL != returnSize);
    if(!arr || !arrSize || !k)
    {
        printf("param is error\n");
        *returnSize = 0;
        return NULL;
    }

    int* maxHeap = NULL, *retArr = NULL;
    int i = 0, len = 1;
    
    maxHeap = (int*)calloc(sizeof(int), k + 1);
    if(!maxHeap) {
        return NULL;
    }

    for(i = 0; i < arrSize; ++i) {
        if(len < k + 1) {
            maxHeap[len++] = arr[i];
        }else{
            break;
        }
    }

#if DEBUG    
    printf("len=%d\n", len);
    for(int j = 0; j < len; ++j)
    {
        printf("%d ", maxHeap[j]);
    }
#endif

    hsBuildHeap(maxHeap, len, buildMaxHeap);

#if DEBUG
    printf("len=%d\n", len);
    for(int j = 0; j < len; ++j)
    {
        printf("%d ", maxHeap[j]);
    }
#endif

    for(; i < arrSize; ++i)
    {
        if(arr[i] < maxHeap[1]) {
            maxHeap[1] = arr[i];
            hsAdjust(maxHeap, 1, len, buildMaxHeap);
        }
    }
    
#if DEBUG
    printf("len=%d\n", len);
    for(int j = 0; j < len; ++j)
    {
        printf("%d ", maxHeap[j]);
    }
#endif

    retArr = (int *)malloc(sizeof(int) * k);
    if(!retArr){
        return NULL;
    }

    *returnSize = len - 1;
    memcpy(retArr, maxHeap + 1, *returnSize * sizeof(int));
    free(maxHeap);

    return retArr;
}

int main()
{
    //int arr[] = {0, 9, 7, 5, 3, 1, 101,233,4, 5};
    //int arr[] = {3, 2, 1};
    //int k = 2;
    int arr[] = {0, 0, 0, 2, 0, 5};
    int k = 0;
    int retSize = 0;
    int *retArr = getLeastNumbers(arr, sizeof(arr) / sizeof(int), k, &retSize);
    if(!retArr) {
        return 0;
    }

    for(int i = 0; i < retSize; ++i) {
        printf("%d ", retArr[i]);
    }
    printf("\n");
    free(retArr);
    return 0;
}

