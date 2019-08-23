#include <string.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
void Permutation(char* pStr, char* pBegin);

void Permutation(char* pStr)
{
    if(nullptr == pStr)
    {
        return;
    }

    Permutation(pStr, pStr);
}

void Permutation(char* pStr, char* pBegin)
{
    if(*pBegin == '\0')
    {
        printf("%s\n", pStr);
    }else{
        for(char* pCh = pBegin; *pCh != '\0'; ++pCh)
        {
            char tmp = *pCh;
            *pCh = *pBegin;
            *pBegin = tmp;

            Permutation(pStr, pBegin + 1);

            tmp = *pCh;
            *pCh = *pBegin;
            *pBegin = tmp;
            
        }
    }
}

int main()
{
    char* p = new char[4]();
    strcpy(p, "nih");
    Permutation(p);
    return 0;
}

