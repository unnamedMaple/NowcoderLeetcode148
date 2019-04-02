/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };


Given a linked list, return the node where the cycle begins. If there is no cycle, returnnull.

Follow up:
Can you solve it without using extra space?


*/
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {

		if (head == nullptr)
		{
			return nullptr;
		}


		ListNode*slow = head;
		ListNode*fast = head;

		while (fast->next != nullptr && fast->next->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
			{
				ListNode*tmp = head;
				while (tmp != slow)
				{
					tmp = tmp->next;
					slow = slow->next;
				}
				return tmp;
			}

		}
		return nullptr;
	}
};