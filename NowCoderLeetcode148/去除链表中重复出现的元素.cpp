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
	ListNode *deleteDuplicates(ListNode *head) {


		if (head == NULL)
			return NULL;
		ListNode *preHead = new ListNode(head->val - 1);
		preHead->next = head;
		ListNode *cur = preHead;
		while (cur->next && cur->next->next){
			ListNode *p = cur->next;
			ListNode *pNext = p->next;
			//���p->val!=pNext->val��p�Ƿ��ظ��ڵ㣬pNext����ȷ��
			if (p->val != pNext->val){
				cur->next = p;
				cur = p;
			}
			else{
				//���pΪ�ظ��ڵ㣬������ҵ���һ����p���ȵĽڵ�
				while (pNext && p->val == pNext->val)
					pNext = pNext->next;
				//ɾ����p�ڵ�ֵ��ȵĽڵ�
				cur->next = pNext;
			}
		}
		//����αͷ������һ���ڵ�
		return preHead->next;
	}
};