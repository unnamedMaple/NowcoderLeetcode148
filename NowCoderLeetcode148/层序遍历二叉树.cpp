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
	vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int> >ret;


		queue<TreeNode*>myq;
		if (root == nullptr)
		{
			return ret;
		}

		myq.push(root);
		int laynum;
		while (!myq.empty())
		{
			laynum = myq.size();

			vector<int>tmpret;
			while (laynum>0)
			{
				TreeNode* tmp = myq.front();
				myq.pop();
				laynum--;

				tmpret.push_back(tmp->val);
				if (tmp->left != nullptr)
				{
					myq.push(tmp->left);
				}
				if (tmp->right != nullptr)
				{
					myq.push(tmp->right);
				}



			}
			ret.push_back(tmpret);
		}
		return ret;
	}
};