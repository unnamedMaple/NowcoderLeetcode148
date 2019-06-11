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
			//如果p->val!=pNext->val则p是非重复节点，pNext不能确定
			if (p->val != pNext->val){
				cur->next = p;
				cur = p;
			}
			else{
				//如果p为重复节点，则向后找到第一个与p不等的节点
				while (pNext && p->val == pNext->val)
					pNext = pNext->next;
				//删除与p节点值相等的节点
				cur->next = pNext;
			}
		}
		//返回伪头结点的下一个节点
		return preHead->next;
	}
};