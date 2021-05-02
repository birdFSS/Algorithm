/*
 * HeapSort.h
 * Copyright (C) 2021 birdfss <ffhbird@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <stddef.h>
#include <stdbool.h>

typedef int ElemType;
enum BF_HEAP_TYPE {
    BF_MIN_HEAP = 0,
    BF_MAX_HEAP
};

struct BFHeap;
typedef struct BFHeap BFHeap;

/*
 * purpose   : input a unorder array, return a order array
 * param[in] arr : array for item
 * param[in] len : array len, index 0 should not save data
 * param[in] type: 堆类型 BF_MIN_HEAP 降序 BF_MAX_HEAP 升序
 */
void HeapSort(ElemType *arr, int len, enum BF_HEAP_TYPE type);

BFHeap* bfCreateHeap(int size, enum BF_HEAP_TYPE type);
bool bfIsEmpty(BFHeap* pHeap);
int  bfSize(BFHeap* pHeap);
ElemType bfTop(BFHeap* pHeap);
ElemType bfPop(BFHeap* pHeap);
bool bfPush(BFHeap* pHeap, ElemType val);

#endif /* !HEAPSORT_H */
