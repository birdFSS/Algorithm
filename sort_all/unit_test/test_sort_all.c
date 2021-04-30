/*
 * test_sort_all.c
 * email : ffhbird@gmail.com
 * Copyright (C) 2021 birdfss <ffhbird@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include "test_sort_all.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n;
    SRunner *sr;
    sr = srunner_create(make_heap_sort_suite());
    srunner_run_all(sr, CK_NORMAL);
    n = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (0 == n) ? EXIT_SUCCESS : EXIT_FAILURE;
}


