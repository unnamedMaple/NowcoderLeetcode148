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
	vector<int> preorderTraversal(TreeNode *root) {
		stack<TreeNode*>mystack;
		TreeNode*tmp = root;
		vector<int>ret;
		while (tmp != NULL || !mystack.empty())
		{
			if (tmp == NULL)
			{
				tmp = mystack.top();
				mystack.pop();

				ret.push_back(tmp->val);

				if (tmp->right != NULL)
				{
					mystack.push(tmp->right);
				}
				tmp = tmp->left;

			}
			else
			{
				ret.push_back(tmp->val);
				if (tmp->right != NULL)
				{
					mystack.push(tmp->right);
				}
				tmp = tmp->left;
			}
		}
		return ret;
	}
};