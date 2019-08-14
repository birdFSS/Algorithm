#ifndef __KMPSEARCH_H__
#define __KMPSEARCH_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void prefix_table(char* pattern, int* prefix, int n)
{
    assert(pattern != nullptr && prefix != nullptr && n > 0);

    prefix[0] = 0;
    int len = 0;
    int i = 1;
    while(i < n)
    {
        if(pattern[i] == pattern[len])
        {
            ++len;
            prefix[i] = len;
            ++i;
        }else{
            if(len > 0) //当len等于0或-1时停止继续遍历
            {
                len = prefix[len - 1];
            }else{
                prefix[i] = len;
                ++i;
            }
        }
    }
}

void move_prefix_table(int* prefix, int n)
{
    for(int i = n-1; i != 0; --i)
    {
        prefix[i] = prefix[i-1];
    }
    prefix[0] = -1;
}


void kmp_search(char* text, char* pattern)
{
    int len = strlen(pattern);
    int* prefix = (int*)malloc(sizeof(int) * len);
    prefix_table(pattern, prefix, len);
    move_prefix_table(prefix, len);

    int m = strlen(text);
    int i = 0;
    int j = 0;
    while(i < m)
    {
        if(len-1 == j && text[i] == pattern[j])
        {
            printf("find pattern in %d\n", i - j);
            j = prefix[j];
        }
        if(text[i] == pattern[j])
        {
            ++i;
            ++j;
        }else{
            j = prefix[j];
            if(-1 == j)
            {
                ++i;
                ++j;
            }
        }
    }
}
























#endif
