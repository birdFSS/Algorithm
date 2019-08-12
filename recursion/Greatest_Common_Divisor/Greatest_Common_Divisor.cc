#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;


//时间复杂度为 logN
int func(int m, int n)
{
    if(m % n == 0)
    {
        return n;
    }else{
        return func(n , m % n);
    }
}

int main()
{
    cout << func(2012, 2102) << endl;
    return 0;
}

