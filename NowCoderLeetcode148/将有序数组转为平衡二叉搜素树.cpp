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
	TreeNode *sortedArrayToBST(vector<int> &num) {
		if (num.size()<1)
		{
			return nullptr;
		}
		return sortedArrayToBST_help(num, 0, num.size() - 1);
	}

	TreeNode *sortedArrayToBST_help(vector<int> &num, int left, int right) {
		if (left>right)
		{
			return nullptr;
		}

		int mid = (left + right + 1) / 2;
		TreeNode* root = new TreeNode(num[mid]);

		root->left = sortedArrayToBST_help(num, left, mid - 1);
		root->right = sortedArrayToBST_help(num, mid + 1, right);
		return root;


	}

};