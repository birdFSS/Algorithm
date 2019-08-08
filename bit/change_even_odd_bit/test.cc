#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int change_even_odd_bit(int n)
{
    return ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
}

int main()
{
#if 0
    int a = -1;
    printf("%d\n", change_even_odd_bit(a));
#endif
    int a , b, c;
    c=a=0x30;
    b=0x60;
    a = c | b >> 4;
    cout << a << "_" << b << "_" << c << endl;
    return 0;
}

