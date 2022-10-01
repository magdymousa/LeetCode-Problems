#include <iostream>
#include <vector>

using namespace std;


//https://leetcode.com/problems/fibonacci-number/?envType=study-plan&id=dynamic-programming-i
//https://leetcode.com/submissions/detail/812251818/


class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;        
        if (n == 1) return 1;

        vector<int> x(n + 1);

        x[0] = 0;
        x[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            x[i] = x[i - 1] + x[i - 2];

        }

        return x[n];
    }
};

int main()
{

    Solution Sln;

    auto Ret = Sln.fib(30);

    cout << "Result: " << Ret;
}
