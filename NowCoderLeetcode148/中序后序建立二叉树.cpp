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
	TreeNode *buildTree(vector<int> inorder, vector<int> postorder) {
		int len = postorder.size();
		if (len<1)
		{
			return nullptr;
		}

		TreeNode* root = new TreeNode(postorder[len - 1]);


		int x = postorder[len - 1];
		vector<int> inorderL;
		vector<int> inorderR;
		vector<int> postorderL;
		vector<int> postorderR;
		int i = 0;
		for (i = len - 1; inorder[i] != x; i--)
		{
			inorderR.insert(inorderR.begin(), inorder[i]);
			postorderR.insert(postorderR.begin(), postorder[i - 1]);
		}
		i--;
		for (; i >= 0; i--)
		{
			inorderL.insert(inorderL.begin(), inorder[i]);
			postorderL.insert(postorderL.begin(), postorder[i]);
		}

		root->left = buildTree(inorderL, postorderL);
		root->right = buildTree(inorderR, postorderR);
		return root;




	}
};