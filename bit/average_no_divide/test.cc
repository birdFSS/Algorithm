#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main()
{
    srand((unsigned int)time(NULL));
    int x, y;
    for(int i = 0; i < 1000; ++i)
    {
        x = rand() % 100000;
        y = rand() % 100000;
        
        int ave1 = (x & y) + ((x ^ y) >> 1) ;   //x & y 保存相同的1， x ^ y 将不同的1加起来然后除以2(右移一位)
        //int ave2 = (x + y) / 2;     //可能会溢出
        int ave2 = x / 2 + y / 2;
        if(x & 1 && y & 1)
        {
            ++ave2;
        }

        if(ave1 != ave2)
        {
            printf("don't equal ave1=%d\nave2=%d\n", ave1, ave2);
        }else{
            //printf("ave1=%d,ave2=%d\n", ave1, ave2);
        }
    }
    return 0;
}

