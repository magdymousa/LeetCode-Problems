#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
//https://leetcode.com/submissions/detail/823317938/



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
    int maxProfitGreedy(vector<int>& prices) {

        int MaxProfit = INT_MIN, profit;

        for (size_t i = 0; i < prices.size() - 1; i++)
        {
            for (size_t j = i + 1; j < prices.size(); j++)
            {
                profit = prices[j] - prices[i];

                MaxProfit = max(MaxProfit, profit);

            }
        }

        return max(MaxProfit, profit);
    }


    int maxProfit(vector<int>& prices) {

        int MaxProfit = INT_MIN, profit, MaxSell = INT_MIN, MinBuy = INT_MAX;

        MinBuy = prices[0];

        for (size_t i = 1; i < prices.size() - 1; i++)
        {
            profit = prices[i] - MinBuy;
            if(prices[i] < MinBuy)
            {
                MinBuy = prices[i];
            }
            else if (profit > MaxSell)
            {
                MaxProfit = profit;
            }
            



        }

        return max(MaxProfit, 0);
    }
};


int main()
{

    Solution Sln;

    vector<int> v = { 7,1,5,3,6,4 };

    auto Ret = Sln.maxProfit(v);

    cout << "Result: " << Ret << endl;
}
