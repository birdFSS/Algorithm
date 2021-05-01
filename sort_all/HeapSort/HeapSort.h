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

typedef bool (*compFunc)(const void* a, const void* b);
typedef int ElemType;

/*
 * purpose   : input a unorder array, return a order array
 * param[in] arr : array for item
 * param[in] len : array len, index 0 should not save data
 * param[in] cfunc : compare function
 *              if left < right , the array is asc
 *              if left > right , the array is desc
 * attention : index 0 shouldn't save data
 */
void HeapSort(ElemType *arr, size_t len, compFunc cfunc);

/*
 * purpose   : adjust heap
 * param[in] arr : array for item
 * param[in] k   : adjust arr[k]
 * param[in] len : array len, index 0 should not save data
 * param[in] cfunc : compare function
 */
void hsAdjust(ElemType *arr, size_t k, size_t len, compFunc cfunc);

/*
 * purpose   : build heap
 * param[in] : array for item
 * param[in] : array len, index 0 should not save data
 * param[in] : cfunc 
 *              if left < right, build Max heap
 *              if left > right, build Min heap
 */
void hsBuildHeap(ElemType *arr, size_t len, compFunc cfunc);

#endif /* !HEAPSORT_H */
