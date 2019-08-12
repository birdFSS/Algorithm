#pragma once
#include <stdio.h>
#include <string.h>

namespace wd
{

class LCS_length
{
public:
    int operator()(const char* str1, const char* str2)
    {
        if(nullptr == str1 || nullptr == str2)
        {
            return 0;
        }

        int len1 = strlen(str1) + 1;    //还有空字符串
        int len2 = strlen(str2) + 1;

        int **arr = new int*[len1]();
        for(int i=0;i != len1; ++i)
        {
            arr[i] = new int[len2]();
        }

        for(int i = 1; i != len1; ++i)
        {
            for(int j = 1; j != len2; ++j)
            {
                if(str1[i - 1] == str2[j - 1])
                {
                    arr[i][j] = arr[i-1][j-1] + 1;
                }else{
                    arr[i][j] = arr[i-1][j] > arr[i][j-1] ? arr[i-1][j] : arr[i][j-1];
                }
            }
        }

        int len_ret = arr[len1 - 1][len2 - 1];
        for(int i=0;i != len1; ++i)
        {
            delete[] arr[i];
        }
        delete[] arr;
        return len_ret; 
    }
};







}//end of namespace wd

