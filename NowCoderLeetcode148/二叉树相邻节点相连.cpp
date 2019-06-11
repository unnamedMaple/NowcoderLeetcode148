/**
* Definition for binary tree with next pointer.
* struct TreeLinkNode {
*  int val;
*  TreeLinkNode *left, *right, *next;
*  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}



* };

Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.

For example,
Given the following binary tree,

1
/  \
2    3
/ \    \
4   5    7

After calling your function, the tree should look like:

1 -> NULL
/  \
2 -> 3 -> NULL
/ \    \
4-> 5 -> 7 -> NULL


*/

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == nullptr)
		{
			return;
		}
		queue<TreeLinkNode*>myq;
		int laynum = 0;
		myq.push(root);
		while (!myq.empty())
		{
			laynum = myq.size();
			while (laynum>0)
			{
				TreeLinkNode*tmp = myq.front();
				myq.pop();
				laynum--;
				if (laynum == 0)
				{
					tmp->next = nullptr;
				}
				else
				{
					tmp->next = myq.front();
				}

				if (tmp->left != nullptr)
				{
					myq.push(tmp->left);
				}

				if (tmp->right != nullptr)
				{
					myq.push(tmp->right);
				}


			}

		}
		return;
	}
};