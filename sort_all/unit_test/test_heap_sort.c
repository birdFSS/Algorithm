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

static bool sort_by_ASE(const void* l, const void *r)
{
    int* left = (int *)l;
    int *right = (int *)r;
    return *left < *right;
}

static bool sort_by_DESC(const void* l, const void* r)
{
    int* left = (int *)l;
    int *right = (int *)r;
    return *left > *right;
}

int add(int a, int b)
{
    return a + b;
}

START_TEST(test_add){
    fail_unless(add(2,3) == 5, "error, 2 + 3 != 5");
}
END_TEST


START_TEST(test_heap_sort_ase){
    int arr[] = {0,9,3,7,4,5,6,2,8,1,0};
    int arr_len = sizeof(arr) / sizeof(arr[0]) - 1;
    HeapSort(arr, arr_len, sort_by_ASE);
    for(int i = arr_len; i != 1; --i)
    {
        fail_unless(arr[i - 1] < arr[i], "error: arr[%d](%d) < arr[%d](%d)", i - 1, arr[i - 1], i, arr[i]);
    }
}
END_TEST

START_TEST(test_heap_sort_desc){
    int arr[] = {0,389,111,112,2,576,1,0};
    int arr_len = sizeof(arr) / sizeof(arr[0]) - 1;
    HeapSort(arr, arr_len, sort_by_DESC);
    for(int i = arr_len; i != 1; --i)
    {
        fail_unless(arr[i - 1] > arr[i], "error: arr[%d](%d) < arr[%d](%d)", i - 1, arr[i - 1], i, arr[i]);
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
    return s;
}
