#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int f[100][100];
int main()
{
    int N=3,V=5;
    int C[4] = {0,1,2,3};
    int W[4] = {0,60,100,120};
    for(int i=0;i <= V; ++i)
    {
        f[0][i] = 0;
    }
    for(int i = 1; i <= N; ++i)
    {
        f[i][0] = 0;
        for(int j=1; j <= V; ++j)
        {
            if(j < C[i])
            {
                f[i][j] = f[i-1][j];
            }else{
                f[i][j] = (f[i-1][j] > f[i-1][j - C[i]] + W[i])? f[i-1][j] : (f[i-1][j-C[i]] + W[i]);
            }
        }
    }
    cout << f[N][V] << endl;
    return 0;
}

