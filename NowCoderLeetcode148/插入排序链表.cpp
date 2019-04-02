/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };


Sort a linked list using insertion sort.
*/
class Solution {
public:
	ListNode *insertionSortList(ListNode *head) {
		if (head == NULL || head->next == NULL)
		{
			return head;
		}

		ListNode*List = head->next;
		ListNode* tmp = head;
		tmp->next = NULL;
		while (List != NULL)
		{
			tmp = head;
			while (tmp->next != NULL &&tmp->val<List->val)
			{
				tmp = tmp->next;
			}
			if (tmp->next == NULL)
			{
				if (tmp->val>List->val)
				{
					int tem = List->val;
					List->val = tmp->val;
					tmp->val = tem;


				}
				tmp->next = List;
				List = List->next;
				tmp->next->next = NULL;
			}
			else
			{
				ListNode* tmpP = List->next;

				List->next = tmp->next;
				tmp->next = List;

				int tem = List->val;
				List->val = tmp->val;
				tmp->val = tem;

				List = tmpP;

			}


		}
		return head;
	}
};