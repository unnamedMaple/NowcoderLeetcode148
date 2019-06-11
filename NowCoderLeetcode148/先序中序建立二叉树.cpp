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
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		int len = preorder.size();
		if (len<1)
		{
			return nullptr;
		}

		TreeNode* root = new TreeNode(preorder[0]);


		int x = preorder[0];
		vector<int> inorderL;
		vector<int> inorderR;
		vector<int> preorderL;
		vector<int> preorderR;
		int i = 0;
		for (i = 0; inorder[i] != x; i++)
		{
			inorderL.push_back(inorder[i]);
			preorderL.push_back(preorder[i + 1]);
		}
		i++;
		for (; i <len; i++)
		{
			inorderR.push_back(inorder[i]);
			preorderR.push_back(preorder[i]);
		}

		root->left = buildTree(preorderL, inorderL);
		root->right = buildTree(preorderR, inorderR);
		return root;
	}
};