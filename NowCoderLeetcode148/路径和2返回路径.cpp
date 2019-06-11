/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree andsum = 22,
5
/ \
4   8
/   / \
11  13  4
/  \    / \
7    2  5   1
return

[
[5,4,11,2],
[5,8,4,5]
]
*/
class Solution {
public:
	vector<vector<int>>ret;
	vector<vector<int> > pathSum(TreeNode *root, int sum) {

		if (root == nullptr)
		{
			return ret;
		}

		vector<int>path;
		visit(root, path, sum);

		return ret;
	}


	void visit(TreeNode* root, vector<int>path, int sum)
	{
		vector<int>tmp(path.begin(), path.end());
		if (root->left == nullptr && root->right == nullptr)
		{
			if (sum - root->val == 0)
			{
				tmp.push_back(root->val);
				ret.push_back(tmp);
			}

			return;
		}

		tmp.push_back(root->val);
		if (root->left != nullptr)
		{
			visit(root->left, tmp, sum - root->val);
		}

		if (root->right != nullptr)
		{
			visit(root->right, tmp, sum - root->val);
		}



	}
};