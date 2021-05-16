/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode *> stk1;
        stack<TreeNode *> stk2;
        bool tag = true;
        vector<vector<int>> ret;
        if (root == nullptr)
            return ret;
        stk1.push(root);
        TreeNode *top = nullptr;
        while (!stk1.empty() || !stk2.empty()) {
            vector<int> vec1, vec2;
            while (!stk1.empty()) {
                top = stk1.top();
                stk1.pop();
                vec1.push_back(top->val);
                if (top->left != nullptr)
                    stk2.push(top->left);
                if (top->right != nullptr)
                    stk2.push(top->right);
            }
            if (!vec1.empty())
                ret.push_back(vec1);
            while (!stk2.empty()) {
                top = stk2.top();
                stk2.pop();
                vec2.push_back(top->val);
                if (top->right != nullptr)
                    stk1.push(top->right);
                if (top->left != nullptr)
                    stk1.push(top->left);
            }
            if (!vec2.empty())
                ret.push_back(vec2);
        }
        return ret;
    }
};