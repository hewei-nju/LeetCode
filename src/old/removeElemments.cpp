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
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val) {
        if (head == nullptr)
            return head;
        while (head != nullptr && head->val == val) {
            head = head->next;
        }
        ListNode *ret = head;
        while (head != nullptr) {
            if (head->next != nullptr) {
                if (head->next->val == val) {
                    head->next = head->next->next;
                } else {
                    head = head->next;
                }
            } else 
                break;
        }
        return ret;
    }
};
