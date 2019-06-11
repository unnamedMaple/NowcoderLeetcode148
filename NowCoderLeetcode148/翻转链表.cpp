/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given1->2->3->4->5->NULL, m = 2 and n = 4,

return1->4->3->2->5->NULL.

*/
class Solution {
public:
	ListNode *reverseBetween(ListNode *head, int m, int n) {


		ListNode*pre = head;
		ListNode*cur = head;
		int count = 1;
		while (count<m)
		{
			pre = cur;
			cur = cur->next;
			count++;
		}
		count = n - m;

		if (m == 1)
		{
			ListNode*tmp = new ListNode(0);
			tmp->next = head;
			pre = tmp;
		}

		while (count>0)
		{


			ListNode*tmp = cur->next;
			cur->next = cur->next->next;
			tmp->next = pre->next;
			pre->next = tmp;

			count--;
		}

		if (m == 1)
		{
			return pre->next;
		}

		return head;
	}
};