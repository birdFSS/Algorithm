/*
 * test_heap_sort.c
 * email : ffhbird@gmail.com
 * Copyright (C) 2021 birdfss <ffhbird@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */
#include "test_sort_all.h"
#include "HeapSort.h"
#include <check.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int add(int a, int b)
{
    return a + b;
}

START_TEST(test_add){
    fail_unless(add(2,3) == 5, "error, 2 + 3 != 5");
}
END_TEST


START_TEST(test_heap_sort_ase){
    int arr[] = {9,3,7,4,5,6,2,8,1,0};
    int arr_len = sizeof(arr) / sizeof(arr[0]);
    HeapSort(arr, arr_len, BF_MAX_HEAP);

#ifdef HEAP_SORT_DEBUG
    printf("ase:");
    for(int i = 0; i < arr_len; ++i) {
        printf("%d%c", arr[i], i == arr_len - 1 ? '\n' : ' ');
    }
#endif

    for(int i = arr_len - 1; i != 1; --i)
    {
        fail_unless(arr[i - 1] < arr[i], "error: arr[%d](%d) < arr[%d](%d)", i - 1, arr[i - 1], i, arr[i]);
    }
}
END_TEST

START_TEST(test_heap_sort_desc){
    int arr[] = {389,111,112,2,576,1,0};
    int arr_len = sizeof(arr) / sizeof(arr[0]);
    HeapSort(arr, arr_len, BF_MIN_HEAP);

#ifdef HEAP_SORT_DEBUG
    printf("desc:");
    for(int i = 0; i < arr_len; ++i) {
        printf("%d%c", arr[i], i == arr_len - 1 ? '\n' : ' ');
    }
#endif

    for(int i = 1; i < arr_len; ++i)
    {
        fail_unless(arr[i - 1] > arr[i], "error: arr[%d](%d) < arr[%d](%d)", i - 1, arr[i - 1], i, arr[i]);
    }
}
END_TEST

START_TEST(test_heap_push){
    int arr[] = {0,1,2,4,3,7,8,10};
    int checkList[] = {0, 1, 2, 4, 4, 7, 8, 10};
    int arr_len = sizeof(arr) / sizeof(arr[0]);
    BFHeap* pHeap = bfCreateHeap(arr_len, BF_MAX_HEAP);
    if(NULL == pHeap){
        return;
    }

    for(int i=0; i < arr_len; ++i){
        bfPush(pHeap, arr[i]);
        fail_unless(bfSize(pHeap) == i + 1, "error : bfHeap size");
        fail_unless(bfTop(pHeap) == checkList[i], "error : Heap Top should be [%d], but it is [%d]", checkList[i], bfTop(pHeap));
    }
}
END_TEST

Suite *make_heap_sort_suite(void){
    Suite *s = suite_create("heap_sort");
    TCase *tc_heap_sort = tcase_create("heap_sort");
    suite_add_tcase(s, tc_heap_sort);
    tcase_add_test(tc_heap_sort, test_add);
    tcase_add_test(tc_heap_sort, test_heap_sort_ase);
    tcase_add_test(tc_heap_sort, test_heap_sort_desc);
    tcase_add_test(tc_heap_sort, test_heap_push);
    return s;
}
