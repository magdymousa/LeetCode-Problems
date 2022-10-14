#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
//https://leetcode.com/submissions/detail/822441877/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int Index = -1;
        ListNode* pCurrNode = head;
        ListNode* pDelNode = nullptr;

        int n = GetSize(head);

        if (n == 1)
            return nullptr;

        int middle = n / 2;

        while (pCurrNode)
        {
            Index++;

            if (Index == middle - 1)
            {
                pDelNode = pCurrNode->next;
                pCurrNode->next = pCurrNode->next->next;

                delete pDelNode;
                break;
            }

            pCurrNode = pCurrNode->next;
        }

        return head;
    }

    int GetSize(ListNode* head)
    {
        if (!head)
            return 0;

        return GetSize(head->next) + 1;
    }

};

int main()
{

    Solution Sln;


    auto Ret = Sln.deleteMiddle(new ListNode());

    cout << "Result: "; 
}
