#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//https://leetcode.com/problems/pascals-triangle-ii/
//https://leetcode.com/submissions/detail/822589029/



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
    vector<int> getRow(int rowIndex) {
        vector<int> Ret(rowIndex + 1, 1);

        for (size_t i = 0; i < rowIndex+1; i++)
        {

            for (size_t j = i; j > 0; j--)
            {

                if (j == 0 || j == i)
                    continue;

                Ret[j] = Ret[j - 1] + Ret[j];

            }

        }

        return Ret;
    }
};

int main()
{

    Solution Sln;

    auto Ret = Sln.getRow(4);

    cout << "Result: "; print(Ret);
}
