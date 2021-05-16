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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode *> que1;
        queue<TreeNode *> que2;
        stack<vector<int>> stk;
        vector<vector<int>> vec_t;
        if (root == nullptr)
            return vec_t;
        que1.push(root);
        TreeNode *top = nullptr;
        while (!que1.empty() || !que2.empty()) {
            vector<int> vec1;
            while (!que1.empty()) {
                top = que1.front();
                que1.pop();
                vec1.push_back(top->val);
                if (top->left)
                    que2.push(top->left);
                if (top->right)
                    que2.push(top->right);
            }
            if (!vec1.empty())
                stk.push(vec1);
            vector<int> vec2;
            while (!que2.empty()) {
                top = que2.front();
                que2.pop();
                vec2.push_back(top->val);
                if (top->left)
                    que1.push(top->left);
                if (top->right)
                    que1.push(top->right);
            }
            if (!vec2.empty())
                stk.push(vec2);
        }
        while (!stk.empty()) {
            vec_t.push_back(stk.top());
            stk.pop();
        }
        return vec_t;
    }
};