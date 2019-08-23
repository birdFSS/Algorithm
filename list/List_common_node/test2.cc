#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

class Solution {
public:
    static bool compare(const vector<int>& lhs, const vector<int> & rhs)
    { return lhs[0] < rhs[0]; }
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<vector<int>> rets;
        vector<int> vec;
        if(array.size() < 2)
        {
            return vec;

        }

        int i = 0;
        int j = array.size() - 1;

        while(i <= j)
        {
            if(array[i] + array[j] == sum)
            {
                rets.push_back(vector<int>{array[i], array[j]});
                ++i;
                --j;

            }else if(array[i] + array[j] > sum){
                --j;

            }else{
                ++i;

            }

        }

        return rets[0];


    }

};

int main()
{
    vector<int> vec{1,2,4,6,7,8,11,14,15};
    Solution s;
    auto vec2 =s.FindNumbersWithSum(vec, 15);
    cout << vec2[0] << "\n" << vec2[1] << endl;
    return 0;
}

