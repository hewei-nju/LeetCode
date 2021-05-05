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
    // vector<int> preorderTraversal(TreeNode* root) {
    //     if (root != nullptr) {
    //         ret.push_back(root->val);
    //         preorderTraversal(root->left);
    //         preorderTraversal(root->right);
    //     }
    //     return ret;
    // }

    vector<int> preorderTraversal(TreeNode *root) {
        if (root != nullptr) {
            stack<TreeNode *> st;
            st.push(root);
            while (!st.empty()) {
                TreeNode *top = st.top();
                st.pop();
                if (top != nullptr) {
                    if (top->right != nullptr) {
                        st.push(top->right);
                    }
                    if (top->left != nullptr) {
                        st.push(top->left);
                    }
                    st.push(top);
                    st.push(nullptr);
                } else {
                    top = st.top();
                    st.pop();
                    ret.push_back(top->val);
                }
                
            }
        }
        return ret;
    }

private:
    vector<int> ret;
};