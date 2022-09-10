#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//https://leetcode.com/problems/longest-consecutive-sequence/
//https://leetcode.com/submissions/detail/796406817/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if (!nums.size())
            return 0;

        sort(nums.begin(), nums.end());
        int MaxSeq = 1, currSeq = 1;

        for (size_t i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
                continue;

            if (nums[i] == nums[i - 1] + 1)
                currSeq++;
            else
                currSeq = 1;

            MaxSeq = max(currSeq, MaxSeq);
        }

        return MaxSeq;
    }
};

int main()
{

    Solution Sln;

    vector<int> v{ 0,3,7,2,5,8,4,6,0,1};

    auto Ret = Sln.longestConsecutive(v);

    cout << "Result: " << Ret;
}
