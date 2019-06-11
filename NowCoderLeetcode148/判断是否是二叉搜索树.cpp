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
	bool isValidBST(TreeNode *root) {

		if (root == nullptr)
		{
			return true;
		}

		TreeNode*pre = nullptr;
		stack<TreeNode*>mys;
		TreeNode* tmp = root;
		while (!mys.empty() || tmp != nullptr)
		{
			if (tmp == nullptr)
			{
				tmp = mys.top();
				mys.pop();

				if (pre != nullptr)
				{
					if (pre->val >= tmp->val)
					{
						return false;
					}
				}
				pre = tmp;
				tmp = tmp->right;
			}
			else
			{

				mys.push(tmp);
				tmp = tmp->left;
			}


		}


		return true;
	}


};