#include <iostream>
#include <vector>

using namespace std;


//https://leetcode.com/problems/maximum-subarray/
//https://leetcode.com/submissions/detail/796369015/

class Solution {
public:

    int maxSubArray(vector<int>& nums) {

        int Max = nums[0];
        int currentMax = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            currentMax = max(nums[i], currentMax + nums[i]);
            Max = max(Max, currentMax);
        }

        return Max;
    }


    int maxSubArrayGreedy(vector<int>& nums) {
        int Max = INT_MIN, sum;

        for (size_t i = 0; i < nums.size(); i++)
        {
            sum = 0;

            for (size_t j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                Max = max(sum, Max);
            }
        }

        return Max;
    }
};


int main()
{

    Solution Sln;

    //vector<int> v{ -2,1,-3,4,-1,2,1,-5,4 };
    vector<int> v{ -2, 1, -3, 4, -1, 2, 1, -5, 4 };

    auto Ret = Sln.maxSubArray(v);

    cout << "Result: " << Ret;
}
