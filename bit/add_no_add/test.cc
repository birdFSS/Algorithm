#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int add_no_arithm(int a, int b)
{
    if(0 == b) return a;
    int sum = a ^ b;
    int carry = (a & b) << 1;
    return add_no_arithm( sum , carry );
}

int main()
{
    int a = 1090, b = 2130;
    printf("%d\n", add_no_arithm(a, b));
    return 0;
}

