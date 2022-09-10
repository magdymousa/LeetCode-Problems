#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//https://leetcode.com/problems/find-the-duplicate-number/
//https://leetcode.com/submissions/detail/796393967/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
                return nums[i];
        }

        return nums[0];
    }
};


int main()
{

    Solution Sln;

    vector<int> v{ -2, 1, -3, 4, -1, 2, 1, -5, 4 };

    auto Ret = Sln.findDuplicate(v);

    cout << "Result: " << Ret;
}
