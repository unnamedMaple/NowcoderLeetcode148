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
	bool isSymmetric(TreeNode *root) {
		if (root == nullptr)
		{
			return true;
		}

		return mirrorTree(root->left, root->right);
	}

	bool mirrorTree(TreeNode* left, TreeNode* right)
	{
		if (left == nullptr && right == nullptr)
		{
			return true;
		}
		if (left == nullptr && right != nullptr)
		{
			return false;
		}

		if (left != nullptr&&right == nullptr)
		{
			return false;
		}

		if (left->val != right->val)
		{
			return false;
		}

		return mirrorTree(left->left, right->right) && mirrorTree(left->right, right->left);



	}
};