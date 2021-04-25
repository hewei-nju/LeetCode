#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Definition for a binary tree node.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que1;
        queue<TreeNode*> que2;
        vector<vector<int>> ret;
        if (root == nullptr) {
            return ret;
        }
        que1.push(root);
        while (!que1.empty()) {
            TreeNode *head = que1.front();
            que1.pop();
            if (head->left != nullptr) {
                que1.push(head->left);
            }
            if (head->right != nullptr) {
                que1.push(head->right);
            }
            que2.push(head);
        }
        TreeNode *slow = que2.front();
        TreeNode *fast = nullptr;
        vector<int> vec{slow->val};
        ret.push_back(vec);
        que2.pop();
        while (!que2.empty()) {
            slow = que2.front();
            fast = que2.front();
            que2.pop();
            vector<int> tmp{fast->val};
            while (!que2.empty()) {
                if (slow->left == nullptr && slow->right == nullptr) {
                    slow = fast;
                }
                fast = que2.front();
                if (fast == slow->left || fast == slow->right) {
                    break;
                }
                que2.pop();
                tmp.push_back(fast->val);
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};

void print(vector<vector<int>> &nums)
{
    for (auto &item: nums) {
        for (auto num: item) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main()
{
    TreeNode *root = new TreeNode;
    TreeNode *left = new TreeNode;
    TreeNode *right = new TreeNode;
    TreeNode *rightLeft = new TreeNode;
    TreeNode *rightRight = new TreeNode;
    root->val = 3;
    root->left = left;
    root->left->val = 9;
    root->left->left = nullptr;
    root->left->right = nullptr;
    root->right = right;
    root->right->val = 20;
    root->right->left = rightLeft;
    root->right->left->val = 15;
    root->right->left->left = nullptr;
    root->right->left->right = nullptr;
    root->right->right = rightRight;
    root->right->right->val = 7;
    root->right->right->left = nullptr;
    root->right->right->right = nullptr;

    Solution s;
    vector<vector<int>> nums = s.levelOrder(root);
    print(nums);
};
