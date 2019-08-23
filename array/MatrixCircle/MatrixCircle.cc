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
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> vec;
        if(matrix.size() <= 0 || matrix[0].size() <= 0)
        {
            return vec;

        }

        int start = 0;
        int rows = matrix.size();
        int columns = matrix[0].size();
        //printf("%d,%d\n", rows, columns);
        while(columns > start * 2 && rows > start * 2)
        {
            PrintMatrixInCircle(matrix, columns, rows, start, vec);
            ++start;

        }
        return vec;
    }

    static void PrintMatrixInCircle(vector<vector<int> >& numbers, int columns, int rows, int start, vector<int>& vec)
    {
        int endX = columns - 1 - start;
        int endY = rows - 1 - start;

        for(int i = start; i <= endX; ++i)
        {
            vec.push_back(numbers[start][i]);

        }

        if(start < endY)
        {
            for(int i=start + 1; i <= endY; ++i)
            {
                vec.push_back(numbers[i][endX]);

            }

        }

        if(start < endX && start < endY)
        {
            for(int i = endX - 1; i >= start; --i)
            {
                vec.push_back(numbers[endY][i]);

            }

        }

        if(start < endX && start < endY - 1)
        {
            for(int i = endY - 1; i >= start + 1; --i)
            {
                vec.push_back(numbers[i][start]);

            }

        }

    }
};

int main()
{
    vector<vector<int>> arr{{1,2,3,4}, {5,6,7,8},{9,10,11,12}, {13,14,15,16}};
    Solution s;
    auto vec = s.printMatrix(arr);
    for(auto i : vec)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

