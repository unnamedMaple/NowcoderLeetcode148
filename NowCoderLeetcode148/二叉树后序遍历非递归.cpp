/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	vector<int> postorderTraversal(TreeNode *root) {
		stack<TreeNode*>mystack;
		stack<bool>signStack;
		bool sign = false;
		TreeNode*tmp = root;

		vector<int>ret;
		while (tmp != NULL || !mystack.empty())
		{
			if (tmp == NULL)
			{
				tmp = mystack.top();
				sign = signStack.top();
				if (sign == false)
				{
					signStack.pop();
					signStack.push(true);
					tmp = tmp->right;
				}
				else
				{
					ret.push_back(tmp->val);
					mystack.pop();
					signStack.pop();
					tmp = NULL;
				}

			}
			else
			{
				mystack.push(tmp);
				signStack.push(false);
				tmp = tmp->left;
			}
		}
		return ret;
	}
};