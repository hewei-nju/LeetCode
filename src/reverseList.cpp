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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *next = head->next;
        while (next != nullptr) {
            cur->next = pre;
            pre = cur;
            cur = next;
            next = next->next;
        }
        cur->next = pre;
        return cur;
    }

    // 递归

    ListNode *reverseList(ListNode *pre, ListNode *cur, ListNode *next) {
        if (next == nullptr) {
            cur->next = pre;
            return cur;
        }
        cur->next = pre;
        pre = cur;
        cur = next;
        next = next->next;
        return reverseList(pre, cur, next);
    }
};