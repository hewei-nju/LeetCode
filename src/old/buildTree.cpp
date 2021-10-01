#include <iostream>
#include <vector>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size())
            return nullptr;
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, preorder.size() - 1);
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int pos, int preEnd, int head, int tail)
    {
        if (head > tail || pos > preEnd)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[pos]);
        int curPos = head;
        while (inorder[curPos] != preorder[pos])
            curPos += 1;
        root->left = buildTree(preorder, inorder, pos + 1, pos + curPos - head, head, curPos - 1);
        root->right = buildTree(preorder, inorder, pos + curPos - head + 1, pos + curPos - head + 1 + tail - curPos, curPos + 1, tail);
        return root;
    }
};

void print(TreeNode *root)
{
    if (root == nullptr)
        return;
    cout << root->val << " ";
    print(root->left);
    print(root->right);
}

int main()
{
    vector<int> pre{3,9,20,15,7};
    vector<int> in{9,3,15,20,7};
    Solution s;
    TreeNode *root = s.buildTree(pre, in);
    print(root);
}