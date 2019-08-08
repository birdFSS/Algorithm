//leetcode 260 只出现一次的数字3

#include <iostream>

#include <string>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

vector<int> find_two_single_number(vector<int> nums)
{
    int bit1 = 1;
    int sum1 = 0;
    for(size_t i=0;i != nums.size(); ++i)
    {
        sum1 ^= nums[i];
    }

    bit1 = sum1 & (-sum1);
    
    vector<int> ret{0, 0};
    for(size_t j=0; j != nums.size(); ++j)
    {
        if(nums[j] & bit1)
        {
            ret[0] ^= nums[j];
        }else{
            ret[1] ^= nums[j];
        }
    }

    return ret;
}

int main()
{
    vector<int> vec{13,9,1,2,3,4,5,6,7,8,9,0,1,2,6,5,3,8,4,0};
    auto vec2 = find_two_single_number(vec);
    for(auto i : vec2)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

