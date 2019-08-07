#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

//输入两个整数a, b ， 输出将a转换为b所需改变的二进制位数
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int find_1_cnt(int n)
{
    int cnt = 0;
    while(n != 0)
    {
        n &= n - 1;
        ++ cnt;
    }
    return cnt;
}

int find_1_cnt1(unsigned int n)  //unsigned 不可省略
{
    int cnt = 0;
    while(n > 0)                //这里是大于号，如果省略unsigned， 无法计算负数。
    {
        n &= n - 1;
        ++ cnt;
    }
    return cnt;
}

//还可以用1左移， & 来统计数中位为1的个数
//
//
int main()
{
    int a = 11, b = 16;
    int c = a ^ b;  //找出a,b不同的位
    printf("%d\n", find_1_cnt(c));
    return 0;
}

