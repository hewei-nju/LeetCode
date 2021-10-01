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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode *ans = head;
        while (head != nullptr) {
            if (head->next != nullptr) {
                if (head->val == head->next->val) {
                    ListNode *tmp = head->next;
                    head->next = tmp->next;
                    delete tmp;
                } else {
                    head = head->next;
                }
            } else {
                break;
            }
        }
        return ans;
    }
};