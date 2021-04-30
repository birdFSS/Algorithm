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
 * param[in] : array for item
 * param[in] : array len, care for index 0
 * param[in] : item size
 * attention : index 0 shouldn't be used
 */
void HeapSort(ElemType *arr, size_t len, compFunc cfunc);

#endif /* !HEAPSORT_H */
