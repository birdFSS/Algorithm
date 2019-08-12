#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int Fib(int n)
{
    if(0 == n)
    {
        return 0;
    }else if(1 == n)
    {
        return 1;
    }

    return Fib(n-1) + Fib(n-2);
}

int main()
{
    cout << Fib(5);
    return 0;
}

