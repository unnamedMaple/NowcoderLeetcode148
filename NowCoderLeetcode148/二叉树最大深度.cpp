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
	int maxDepth(TreeNode *root) {
		if (root == nullptr)
		{
			return 0;
		}

		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		int tmp = left>right ? left : right;

		return tmp + 1;

	}
};