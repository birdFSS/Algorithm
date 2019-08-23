#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index);

void Print1ToMaxOfNDigits(int n)
{
    if(n <= 0)
    {
        return;
    }

    char* number = new char[n + 1]();
    for(int i=0; i < 10; ++i)
    {
        number[0] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, n, 0);
    }

    delete []number;
}

void PrintNumber(char* number)
{
    char* p = number;
    while('0' == *p)
    {
        ++p;
    }

    while(*p != '\0')
    {
        printf("%c", *p);
        ++p;
    }
    printf("\n");
}

void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index)
{
    if(index == length - 1)
    {
        PrintNumber(number);
        return;
    }

    for(int i=0; i < 10; ++i)
    {
        number[index + 1] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
    }
}

int main()
{
    Print1ToMaxOfNDigits(2);
    return 0;
}

