#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

//https://leetcode.com/problems/climbing-stairs/?envType=study-plan&id=dynamic-programming-i
//https://leetcode.com/submissions/detail/813071779/

class Solution {
public:
    int climbStairs(int n) {
        map<int, int> memo;

        return TakeStep(n, 1, memo) + TakeStep(n, 2, memo);
    }

    int TakeStep(int& n, int stepIndex, map<int, int>& memo)
    {
        auto it = memo.find(stepIndex);

        if (it != memo.end())
            return it->second;

        if (stepIndex == n-1 || stepIndex == n)
            return 1;

        if (stepIndex > n)
            return 0;
        auto ret = TakeStep(n, stepIndex + 1, memo) + TakeStep(n, stepIndex + 2, memo);

        memo[stepIndex] = ret;

        return ret;
    }
};
int main()
{

    Solution Sln;


    auto Ret = Sln.climbStairs(1);

    cout << "Result: " << Ret;
}
