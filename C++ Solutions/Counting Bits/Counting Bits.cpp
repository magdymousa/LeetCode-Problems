#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//https://leetcode.com/problems/counting-bits/
//https://leetcode.com/submissions/detail/820460744/

void print(vector<int>& v)
{
    for_each(v.begin(), v.end(), [](int x) {cout << x << ' '; });
    cout << endl;
}

class Solution {
public:
    //5 >> [0, 1, 10, 11, 100, 101] 
    //15 >> [0, 1, 10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111]
    //15 >> [0, 1,  1,  2,   1,   2,   2,   3,    1,    2,    2,    3,    2,  
    vector<int> countBits(int n) {
        vector<int> Ret(n + 1, 0);
        
        int nextTwo = 2, inc = 0;

        for (size_t i = 0; i <= n; i++, inc++)
        {
            if (i <= 1)
            {
                Ret[i] = i;
                continue;
            }

            if (i == nextTwo)
            {
                Ret[i] = 1;
                inc = 0;
                nextTwo *= 2;
                continue;
            }


            Ret[i] = Ret[inc] + 1;
        }

        return Ret;
    }
};

int main()
{

    Solution Sln;


    auto Ret = Sln.countBits(5);

    cout << "Result: "; print(Ret);
}
