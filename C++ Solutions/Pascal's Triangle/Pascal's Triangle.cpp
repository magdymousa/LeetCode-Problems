#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//https://leetcode.com/problems/pascals-triangle/
//https://leetcode.com/submissions/detail/822580321/



void print(vector<int> v)
{
    for_each(v.begin(), v.end(), [](int x)
        {
            cout << x << ' ';
        }
    );
    cout << endl;
}

void print(vector<vector<int>> v)
{
    for_each(v.begin(), v.end(), [](vector<int> x)
        {
            print(x);
        }
    );
}

class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> Ret(numRows, vector<int>());


        for (size_t i = 0; i < numRows; i++)
        {
            for (size_t j = 0; j < i+1; j++)
            {
                Ret[i].push_back(1);

                if (j == 0 || j == i)
                    continue;

                Ret[i][j] = Ret[i - 1][j - 1] + Ret[i - 1][j];

            }

        }


        return Ret;
    }
};

int main()
{

    Solution Sln;

    auto Ret = Sln.generate(5);

    cout << "Result: "; print(Ret);
}
