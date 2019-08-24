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
    int GetNumberOfK(vector<int> data ,int k) {
        int left = 0;
        int right = data.size() - 1;
        int middle = 0;
        while(left <= right)
        {
            middle = ((right - left) >> 1) + left;
            if(k == data[middle])
            {
                break;

            }else if(k > data[middle]){
                left = middle + 1;

            }else{
                right = middle - 1;

            }

        }

        if(k != data[middle])
        {
            return 0;
        }else{
            int cnt = 0;
            for(int i = middle; i >= 0; --i)
            {
                if(data[i] == k)
                {
                    ++cnt;

                }else{
                    break;

                }

            }

            for(int i = middle + 1; i < data.size(); ++i)
            {
                if(data[i] == k)
                {
                    ++cnt;

                }else{
                    break;

                }

            }
            return cnt;
        }

    }

};

int main()
{
    Solution s;
    vector<int> arr{1,3,3,3,3,3,4,5,6};
    cout << s.GetNumberOfK(arr, 3) << endl;
    return 0;
}

