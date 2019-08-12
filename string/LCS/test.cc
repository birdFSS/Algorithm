#include "LCS_length.h"
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

int c[100][100];
int LCS_LENGTH(const char* X, const char* Y)
{
    if(nullptr == X || nullptr == Y)
    {
        return 0;
    }

    int m = strlen(X);
    int n = strlen(Y);
    for(int i = 1; i < m; ++i)
    {
        c[i][0] = 0;
    }
    for(int j = 1; j < n; ++j)
    {
        c[0][j] = 0;
    }
    c[0][0] = 0;
    //printf("c[m-1][n-1]=%d\n", c[m][n]);
    for(int i= 1;i<=m;++i)
    {
        for(int j=1; j <= n; ++j)
        {
            //printf("X[i]=%c,Y[i]=%c\n", X[i], Y[i]);
            //if(X[i] == Y[j])//错的 ABC CBA
            if(X[i - 1] == Y[j - 1])
            {
                c[i][j] = 1 + c[i-1][j-1];
            }else{
                //c[i][j] = std::max(c[i][j-1], c[i-1][j]);
                c[i][j] =  c[i][j-1] > c[i-1][j] ? c[i][j-1] : c[i-1][j];
            }
        }
    }
    return c[m][n];
}

int main()
{
    const char* s1 = "ABCD";
    const char* s2 = "DCBA";

    wd::LCS_length lcs;

    cout << LCS_LENGTH(s1, s2) << endl;
    cout << "LCS_length() = " << lcs(s1, s2) << endl;
    return 0;
}

