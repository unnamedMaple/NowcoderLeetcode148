/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree 
in which the depth of the two subtrees of every node never differ by more than 1.


*/
class Solution {
public:
	bool balanced = true;
	bool isBalanced(TreeNode *root) {
		height(root);
		return balanced;
	}

	int height(TreeNode * root)
	{
		if (root == nullptr)
		{
			return 0;
		}


		int leftH = height(root->left);
		int rightH = height(root->right);
		if (abs(rightH - leftH)>1)
		{
			balanced = false;
		}

		int tmp = leftH>rightH ? leftH : rightH;
		return tmp + 1;


	}

};