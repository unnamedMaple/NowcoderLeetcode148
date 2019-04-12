/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };


Given a binary tree containing digits from0-9only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path1->2->3which represents the number123.

Find the total sum of all root-to-leaf numbers.

For example,

 1
/ \
2   3

The root-to-leaf path1->2represents the number12.
The root-to-leaf path1->3represents the number13.

Return the sum = 12 + 13 =25.

*/
class Solution {
public:
	int sum = 0;
	int sumNumbers(TreeNode *root) {
		preVisit(root, 0);
		return sum;
	}

	void preVisit(TreeNode * root, int par){

		if (root == nullptr)
		{
			return;
		}

		int cur = par * 10 + root->val;

		if (root->left == nullptr && root->right == nullptr){
			sum += cur;
		}

		preVisit(root->left, cur);
		preVisit(root->right, cur);
	}
};