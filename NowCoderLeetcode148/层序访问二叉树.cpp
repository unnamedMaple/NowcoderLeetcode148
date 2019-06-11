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
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector<vector<int> >ret;
		if (root == nullptr)
		{
			return ret;
		}

		queue<TreeNode*>myq;
		myq.push(root);
		int laynum = 0;
		while (!myq.empty())
		{
			laynum = myq.size();
			vector<int>layer;
			while (laynum>0)
			{
				TreeNode* tmp = myq.front();
				myq.pop();
				laynum--;
				layer.push_back(tmp->val);

				if (tmp->left != nullptr)
				{
					myq.push(tmp->left);
				}

				if (tmp->right != nullptr)
				{
					myq.push(tmp->right);
				}


			}
			ret.insert(ret.begin(), layer);
		}
		return ret;
	}
};