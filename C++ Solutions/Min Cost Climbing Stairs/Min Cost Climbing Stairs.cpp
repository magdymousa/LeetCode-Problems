#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

//https://leetcode.com/problems/min-cost-climbing-stairs/?envType=study-plan&id=dynamic-programming-i
//https://leetcode.com/submissions/detail/813020796/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        map<int, int> memo;

        return min(TakeStep(cost, 0, memo), TakeStep(cost, 1, memo));
    }

    int TakeStep(vector<int>& cost, int stepIndex, map<int, int> &memo)
    {
        auto it = memo.find(stepIndex);

        if (it != memo.end())
            return it->second;
        
        if (stepIndex >= cost.size())
            return 0;

        auto ret =  min(TakeStep(cost, stepIndex + 1, memo), TakeStep(cost, stepIndex + 2, memo)) + cost[stepIndex];
        
        memo[stepIndex] = ret;

        return ret;
    }
};
int main()
{

    Solution Sln;

    vector<int> v{ 1,100,1,1,1,100,1,1,100,1 };

    auto Ret = Sln.minCostClimbingStairs(v);

    cout << "Result: " << Ret;
}
