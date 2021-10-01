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
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        // 设置 dummyNode 是这一类问题的一般做法
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;
        head = dummyNode;
        right -= left;
        while (left > 1) {
            left -= 1;
            head = head->next;
        }  // head 指向left的前一个位置
        ListNode *pre = head->next;
        ListNode *cur = pre->next;
        ListNode *next;
        while (right > 0) {
            right -= 1;
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        head->next->next = cur;
        head->next = pre;
        return dummyNode->next;
    }
};