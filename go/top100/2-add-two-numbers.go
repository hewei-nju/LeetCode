/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 // 这题我思路都明白了，但是golang的用法没那么熟悉，所以就照着题解来熟悉语法了。
 func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	 var head *ListNode
	 var tail *ListNode
	 c := 0
	 for l1 != nil || l2 != nil {
		 n1, n2 := 0, 0
		 if l1 != nil {
			 n1 = l1.Val
			 l1 = l1.Next
		 }
		 if l2 != nil {
			 n2 = l2.Val
			 l2 = l2.Next
		 }

		 sum := n1 + n2 + c
		 sum, c = sum % 10, sum / 10
		 if head == nil {
			 head = &ListNode{Val : sum}
			 tail = head
		 } else {
			 tail.Next = &ListNode{Val : sum}
			 tail = tail.Next
		 }
		 if c > 0 {
			 tail.Next = &ListNode{Val: c}
		 }
	 }
	 return head

}