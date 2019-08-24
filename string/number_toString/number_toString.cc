#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int cntCore(string& num, size_t pos)
{
    if(pos >= num.size() - 1)
    {
        return 1;
    } 

    int cnt = 0;
    if('1' == num[pos])
    {
        cnt = cntCore(num, pos+1) + cntCore(num, pos+2);
    }else if('2' == num[pos] && (num[pos + 1] <= '5' && num[pos + 1] >= 0)){
        cnt = cntCore(num, pos + 1) + cntCore(num, pos + 2);
    }else{
        cnt =  cntCore(num, pos + 1);
    }
    return cnt;
}

int number_toString_count(int n)
{
    if(n < 0)
    {
        n = -n;
    }
    string number = std::to_string(n);
    int num = cntCore(number, 0);
    return num;
}

int main()
{
    int n = -22267;
    cout << number_toString_count(n) << endl;;
    return 0;
}

