/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };


Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

1
/ \
2   3

Return6.

*/
class Solution {
public:
	int max = INT_MIN;
	int maxPathSum(TreeNode *root) {

		maxSum(root);
		return max;

	}

	int maxSum(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}

		int leftmax = maxSum(root->left);
		int rightmax = maxSum(root->right);
		int sum = root->val;
		if (leftmax>0)
		{
			sum += leftmax;
		}

		if (rightmax>0)
		{
			sum += rightmax;
		}

		if (max<sum)
		{
			max = sum;
		}

		if (leftmax<0 && rightmax<0)
		{
			return root->val;
		}
		int ret = leftmax<rightmax ? rightmax : leftmax;
		return ret + root->val;

	}
};