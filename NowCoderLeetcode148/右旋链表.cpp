/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given1->2->3->4->5->NULLand k =2,
return4->5->1->2->3->NULL.


*/
class Solution {
public:
	ListNode *rotateRight(ListNode *head, int k) {
		if (head == nullptr){
			return nullptr;
		}

		// get list len
		int num = 0;
		ListNode *tmp = head;
		while (tmp != nullptr){
			tmp = tmp->next;
			num++;
		}
		k = k%num;
		if (k == 0){
			return head;
		}

		int count = 1;
		ListNode*cur = head;
		ListNode*kthNode = head;
		while (count<k){
			kthNode = kthNode->next;
			if (kthNode == nullptr){
				return nullptr;
			}
			count++;
		}

		if (kthNode->next == nullptr){
			return cur;
		}

		ListNode*pre = cur;
		while (kthNode->next != nullptr){
			pre = cur;
			cur = cur->next;
			kthNode = kthNode->next;
		}
		kthNode->next = head;
		pre->next = nullptr;
		return cur;
	}
};