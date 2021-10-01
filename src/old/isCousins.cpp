#include <iostream>
#include <queue>
#include <cassert>
using namespace std;
// Definition for a binary tree node.
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
    // 直接使用三个队列广度优先搜索即可
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode *> que1;
        queue<TreeNode *> que2;
        if (root == nullptr)
            return false;
        que1.push(root);
        while (!que1.empty()) {
            TreeNode *top = nullptr;
            while (!que1.empty()) {
                top = que1.front();
                que1.pop();
                if (top->left != nullptr && top->right != nullptr)
                    if (top->left->val == x && top->right->val == y || top->left->val == y && top->right->val == x)
                        return false;
                if (top->left)
                    que2.push(top->left);
                if (top->right)
                    que2.push(top->right);
            }
            int cnt = 0;
            while (!que2.empty()) {
                // int cnt = 0;  这我心态崩了鸭!!!居然搞了个局部变量
                top = que2.front();
                que2.pop();
                que1.push(top);
                if (top->val == x || top->val == y)
                    cnt += 1;
                if (cnt == 2)
                    return true;
            }
        }
        return false;
    }

};


int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);
    Solution s;
    bool tag = s.isCousins(root, 4, 5);
    assert(tag);
    cout << "Hello world!" << endl;
}