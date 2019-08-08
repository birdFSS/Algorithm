#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
#define OFFSET(type, field) ((long)&(((type*)0)->field))

struct S{
    int a;
    char c;
    int b;
};

int main()
{
    cout << OFFSET(S, c) << endl;
    return 0;
}

