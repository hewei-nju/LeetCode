/*
判断给定的链表中是否有环。如果有环则返回true，否则返回false。


数据范围：链表长度 0≤n≤10000，链表中任意节点的值满足 ∣val∣<=100000
要求：空间复杂度 O(1)，时间复杂度 O(n)

输入分为2部分，第一部分为链表，第二部分代表是否有环，然后回组成head头结点传入到函数里面。-1代表无环，其他的数字代表有环，这些参数解释仅仅是为了方便读者自测调试。实际在编码时读入的是链表的头节点。


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 快慢指针
class Solution {
public:
    bool hasCycle(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
            return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow != nullptr && fast != nullptr && slow != fast) {
            slow = slow->next;
            fast = fast->next;
            if (slow == fast)
                return true;
            if (fast == nullptr)
                return false;
            fast = fast->next;
        }
        if (slow == fast)
            return true;
        return false;
    }
};

/// 下面是一个写的更为优雅的方式
class Solution {
public:
    bool hasCycle(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while (slow != NULL && fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};