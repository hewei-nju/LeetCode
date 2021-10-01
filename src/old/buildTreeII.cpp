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

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty() || inorder.size() != postorder.size())
            return nullptr;
        return buildTree(inorder, postorder, inorder.size() - 1, 0, 0 ,inorder.size() - 1);
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int pos, int postHead, int head, int tail) {
        if (head > tail || pos < postHead)
            return nullptr;
        TreeNode *root = new TreeNode(postorder[pos]);
        int curPos = head;
        while (inorder[curPos] != postorder[pos])
            curPos += 1;
        root->left = buildTree(inorder, postorder, pos - (tail - curPos) - 1, head-curPos, head, curPos - 1);
        root->right = buildTree(inorder, postorder, pos - 1, pos - 1 - (tail - curPos)-1, curPos + 1, tail);
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
    vector<int> in{1,2,3,4,5};
    vector<int> post{4,5,3,2,1};
    Solution s;
    TreeNode *root = s.buildTree(in, post);
    print(root);
}