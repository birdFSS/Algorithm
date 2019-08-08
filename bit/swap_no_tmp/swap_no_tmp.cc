#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

#define SWAP(x, y) do{ (x) = (x) ^ (y); (y) = (x) ^ (y); (x) = (x) ^ (y); }while(0);


void swap_no_tmp(int & a, int & b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

//这个在数值过大，可能会溢出
void swap_no_tmp2(int &a, int & b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

int main()
{
    int a = -2121, b =31;
    printf("a=%d, b=%d\n", a, b);
    swap_no_tmp(a, b);
    //SWAP(a , b);
    printf("a=%d, b=%d\n", a, b);

    return 0;
}

