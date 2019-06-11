/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };

iven a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree andsum = 22,
5
/ \
4   8
/   / \
11  13  4
/  \      \
7    2      1
return true, as there exist a root-to-leaf path5->4->11->2which sum is 22.

*/
class Solution {
public:
	bool has = false;
	int aim = 0;
	bool hasPathSum(TreeNode *root, int sum) {
		if (root == nullptr)
		{
			return false;
		}
		aim = sum;
		visit(root, 0);
		return has;
	}

	void visit(TreeNode* root, int par)
	{
		if (root->left == nullptr && root->right == nullptr)
		{

			if (root->val + par == aim)
			{
				has = true;
			}
			return;
		}

		if (root->left != nullptr)
		{
			visit(root->left, par + root->val);
		}

		if (root->right != nullptr)
		{
			visit(root->right, par + root->val);
		}
	}


};