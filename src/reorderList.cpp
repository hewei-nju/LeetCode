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
    void reorderList(ListNode* head) {
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode *last = head;
        if (head == nullptr) {
            return;
        }
        ListNode *pre = dummyNode;
        int len = 0;
        while (head != nullptr) {
            head = head->next;
            ++len;
        }
        head = dummyNode;
        while (len/2 >= 1) {
            len -= 2;
            pre = head;
            last = pre->next;
            while (last->next != nullptr) {
                pre = pre->next;
                last = last->next;
            }
            pre->next = nullptr;
            last->next = head->next->next;
            head->next->next = last;
            head = last;
            last = last->next;
        }
       head = dummyNode->next;
    }
};



