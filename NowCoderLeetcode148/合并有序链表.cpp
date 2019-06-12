/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode*Head = new ListNode(0);
		ListNode*cur = Head;
		while (l1 != nullptr&&l2 != nullptr){
			if (l1->val<l2->val){
				cur->next = l1;
				l1 = l1->next;
			}
			else{
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;



		}

		while (l1 != nullptr){
			cur->next = l1;
			l1 = l1->next;
			cur = cur->next;

		}

		while (l2 != nullptr){
			cur->next = l2;
			l2 = l2->next;
			cur = cur->next;

		}

		return Head->next;
	}
};