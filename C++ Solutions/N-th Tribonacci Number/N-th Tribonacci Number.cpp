#include <iostream>
#include <vector>

using namespace std;


//https://leetcode.com/problems/n-th-tribonacci-number/?envType=study-plan&id=dynamic-programming-i
//https://leetcode.com/submissions/detail/812254898/

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;

        vector<int> x(n + 1);

        x[0] = 0;
        x[1] = 1;
        x[2] = 1;


        for (int i = 3; i <= n; i++)
        {
            x[i] = x[i - 1] + x[i - 2] + x[i - 3];

        }

        return x[n];
    }
};

int main()
{

    Solution Sln;

    auto Ret = Sln.tribonacci(30);

    cout << "Result: " << Ret;
}
