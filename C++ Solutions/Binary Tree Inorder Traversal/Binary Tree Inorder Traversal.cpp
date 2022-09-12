#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//https://leetcode.com/problems/binary-tree-inorder-traversal/
//https://leetcode.com/submissions/detail/798142686/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class Solution {
public:
    void NodeTraverse(TreeNode* pNode, vector<int> &Ret)
    {
        if (!pNode)
            return;

        if (pNode->left)
            NodeTraverse(pNode->left, Ret);

        Ret.push_back(pNode->val);
    
        if (pNode->right)
            NodeTraverse(pNode->right, Ret);

    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> Ret;

        NodeTraverse(root, Ret);

        return Ret;
    }
};

int main()
{

    Solution Sln;

    TreeNode* root = NULL;

    auto Ret = Sln.inorderTraversal(root);

    cout << "Result: " << Ret.size();
}
