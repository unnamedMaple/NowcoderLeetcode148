/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

/***


��Ϊ��ĿҪ���Ӷ�ΪO(nlogn),�ʿ��Կ��ǹ鲢�����˼�롣
�鲢�����һ�㲽��Ϊ��
1�������������飨����ȡ�е㲢һ��Ϊ����
2���ݹ�ض���벿�ֽ��й鲢����
3���ݹ�ض��Ұ벿�ֽ��й鲢����
4���������벿�ֽ��кϲ���merge��,�õ������

ע���ʼfast = head->next������2���ڵ�ʱ�������޵ݹ�
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