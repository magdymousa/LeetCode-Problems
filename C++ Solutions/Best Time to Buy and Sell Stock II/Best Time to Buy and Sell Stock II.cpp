#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
//https://leetcode.com/submissions/detail/824715113/



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
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int profit = 0;

        if (len == 0 || len == 1)
            return 0;

        for (int i = 0; i < len - 1; i++)
        {
            if (prices[i] < prices[i + 1])
                profit += prices[i + 1] - prices[i];
        }

        return profit;
    }
};


int main()
{

    Solution Sln;

    vector<int> v = { 7,1,5,3,6,4 };

    auto Ret = Sln.maxProfit(v);

    cout << "Result: " << Ret << endl;
}
