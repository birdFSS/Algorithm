#include <string.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cout;
using std::to_string;
using std::cin;
using std::endl;
using std::vector;
using std::string;
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        int len = numbers.size();
        if(len == 0) return "";
        sort(numbers.begin(), numbers.end(), cmp);
        string res;
        for(int i = 0; i < len; i++){
            res += to_string(numbers[i]);

        }
        return res;

    }
    static bool cmp(int a, int b){
        string A = to_string(a) + to_string(b);
        string B = to_string(b) + to_string(a);
        return A < B;

    }

};

int main()
{
    Solution s;
    vector<int> vec{1,3,24,31,13,56,34};
    cout << s.PrintMinNumber(vec) << endl;
    return 0;
}

