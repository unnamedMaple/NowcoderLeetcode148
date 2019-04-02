/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

/***


因为题目要求复杂度为O(nlogn),故可以考虑归并排序的思想。
归并排序的一般步骤为：
1）将待排序数组（链表）取中点并一分为二；
2）递归地对左半部分进行归并排序；
3）递归地对右半部分进行归并排序；
4）将两个半部分进行合并（merge）,得到结果。

注意初始fast = head->next，否则2个节点时陷入无限递归
***/

class Solution {
public:
	ListNode *sortList(ListNode *head) {
		if (head == NULL || head->next == NULL)
		{
			return head;
		}
		ListNode* fast = head->next;
		ListNode* slow = head;
		while (fast != NULL && fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode*right = sortList(slow->next);
		slow->next = NULL;
		ListNode*left = sortList(head);

		ListNode* ret = merge(left, right);
		return ret;

	}

	ListNode* merge(ListNode* left, ListNode* right)
	{
		ListNode start(0);
		ListNode* tmp = &start;
		while (left != NULL && right != NULL)
		{
			if (left->val < right->val)
			{
				tmp->next = left;

				left = left->next;
			}
			else
			{
				tmp->next = right;

				right = right->next;
			}
			tmp = tmp->next;
		}

		if (left != NULL)
		{
			tmp->next = left;


		}

		if (right != NULL)
		{
			tmp->next = right;

		}
		return start.next;
	}
};