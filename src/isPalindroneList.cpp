/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return true;
        }
        deque<int> dq;
        while (head != nullptr) {
            dq.push_back(head->val);
            head = head->next;
        }
        auto beg = dq.begin();
        auto end = dq.end() - 1;
        while (beg != end) {
            if (beg + 1 == end) {
                return *beg == *end;
                return true;
            } else {
                if ((*beg) == (*end)) {
                    beg += 1;
                    end -= 1;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};