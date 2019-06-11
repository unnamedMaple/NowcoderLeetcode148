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
	void recoverTree(TreeNode *root) {
		if (root == nullptr)
		{
			return;
		}

		TreeNode*pre = nullptr;
		TreeNode*wrongB = nullptr;
		TreeNode*wrongS = nullptr;
		bool findone = false;
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
					if (!findone&&pre->val>tmp->val)
					{
						wrongB = pre;
						wrongS = tmp;
						findone = true;
					}

					else if (findone&&pre->val>tmp->val)
					{
						wrongS = tmp;
						break;
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


		int ex = wrongB->val;
		wrongB->val = wrongS->val;
		wrongS->val = ex;
		return;

	}
};