#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//https://leetcode.com/problems/get-maximum-in-generated-array/
//https://leetcode.com/submissions/detail/827393072/

class Solution {
public:
    int getMaximumGenerated(int n) {
        int Max = INT_MIN;
        vector<int> v(n + 1, 0);

        if (n <= 1)
            return n;

        v[1] = 1;

        for (size_t i = 2; i <= n; i++)
        {
            int curr = i / 2;

            v[i++] = v[curr];

            if (i <= n)
                v[i] = v[curr] + v[curr + 1];

            Max = max(v[curr], Max);

            if (i <= n)
                Max = max(v[i], Max);
        }

        return Max;
    }
};


int main()
{

    Solution Sln;

    vector<vector<char>>  board;

    auto Ret = Sln.getMaximumGenerated(5);

    cout << "Result: " << Ret << endl;
}
