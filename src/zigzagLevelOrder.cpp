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
        deque<TreeNode *> deq;
        queue<TreeNode *> que;
        bool tag = true;
        vector<vector<int>> ret;
        if (root == nullptr) {
            return ret;
        }
        deq.push_back(root);
        //vector<int> tmp{deq1.front()->val};
        //tag = false;
        //ret.push_back(tmp);
        TreeNode *last = new TreeNode;
        TreeNode *next = nullptr;
        last->left = root;
        last->right = nullptr;

        while (!deq.empty()) {
            vector<int> vec;
            while (tag && !deq.empty()) {
                next = deq.front();
                if (last->left == nullptr && last->next == nullptr) {
                    last = next;
                }
                if (last->left == next || last->right == next) {
                    tag = false;
                    break;
                }
                vec.push_back(next->val);
                que.push(next);
                deq.pop_front();
            }
            while (!tag) {
                next = deq.back();
            }
            vector<int> vec;
            
        }
    }
};