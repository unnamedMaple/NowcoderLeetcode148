/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };



Given a singly linked list L: L 0��L 1������L n-1��L n,
reorder it to: L 0��L n ��L 1��L n-1��L 2��L n-2����

You must do this in-place without altering the nodes' values.

For example,
Given{1,2,3,4}, reorder it to{1,4,2,3}.
*/
class Solution {
public:
	void reorderList(ListNode *head) {
		if (head == nullptr || head->next == nullptr)
		{
			return;
		}

		ListNode*slow = head;
		ListNode*fast = head;
		while (fast->next != nullptr && fast->next->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		ListNode* reverse = slow->next;

		slow->next = nullptr;

		ListNode* tmp = reverse;
		ListNode*last = reverse;
		while (last->next != nullptr)
		{
			tmp = last->next;
			last->next = tmp->next;
			tmp->next = reverse;
			reverse = tmp;


		}

		tmp = head;
		last = tmp;
		ListNode*tmpR = reverse;
		while (tmp != nullptr && reverse != nullptr)
		{
			last = last->next;
			tmp->next = reverse;

			tmpR = reverse->next;
			reverse->next = last;

			reverse = tmpR;

			tmp = last;

		}


	}
};