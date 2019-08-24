#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int best_value_of_gift(vector<vector<int>>& values)
{
    if(0 == values.size())
    {
        return -1;
    }
    size_t columes = values[0].size();

    for(size_t i = 1; i < values.size(); ++i)
    {
        if(values[i].size() != columes)
        {
            printf("error input in row %ld\n", i);
            return -1;
        }
    }

    int * maxValues = new int[columes]();
    for(size_t i =0; i < values.size(); ++i)
    {
        for(size_t j=0; j < columes; ++j)
        {
            int left = 0;
            int up = 0;
            if(i > 0)
            {
                up = maxValues[j];
            }

            if(j > 0)
            {
                left = maxValues[j - 1];
            }

            maxValues[j] = std::max(left, up) + values[i][j];
        }
    }

    int maxValue = maxValues[columes - 1];
    delete [] maxValues;
    return maxValue;
}

int main()
{
    vector<vector<int>> vec{{1,10,3, 8}, {12,2,9,6}, {5,7,4,11}, {3,7,16,5}};
    cout << best_value_of_gift(vec) << endl;
    return 0;
}

