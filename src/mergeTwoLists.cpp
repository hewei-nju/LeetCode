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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ansList = nullptr;
        ListNode *head = nullptr;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                if (ansList == nullptr) {
                    ansList = new ListNode;
                    ansList->val = l1->val;
                    head = ansList;
                } else {
                    ListNode *tmpList = new ListNode;
                    tmpList->val = l1->val;
                    tmpList->next = nullptr;
                    ansList->next = tmpList;
                    ansList = ansList->next;
                }
                l1 = l1->next;
            } else {
                if (ansList == nullptr) {
                    ansList = new ListNode;
                    ansList->val = l2->val;
                    head = ansList;
                } else {
                    ListNode *tmpList = new ListNode;
                    tmpList->val = l2->val;
                    tmpList->next = nullptr;
                    ansList->next = tmpList;
                    ansList = ansList->next;
                }
                l2 = l2->next;
            }
        } 
        while (l1 != nullptr) {
            if (ansList == nullptr) {
                ansList = new ListNode;
                ansList->val = l1->val;
                l1 = l1->next;
                head = ansList;
            } else {
                ListNode *tmpList = new ListNode;
                tmpList->val = l1->val;
                l1 = l1->next;
                tmpList->next = nullptr;
                ansList->next = tmpList;
                ansList = ansList->next;
            }
        }
        while (l2 != nullptr) {
            if (ansList == nullptr) {
                ansList = new ListNode;
                ansList->val = l2->val;
                l2 = l2->next;
                head = ansList;
            } else {
                ListNode *tmpList = new ListNode;
                tmpList->val = l2->val;
                l2 = l2->next;
                tmpList->next = nullptr;
                ansList->next = tmpList;
                ansList = ansList->next;
            }
        }
        return head;
    }
};