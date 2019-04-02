
//Given a binary tree, find its minimum depth.The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
class Solution {
public:
	int run(TreeNode *root) {
		if (root == NULL)
		{
			return 0;
		}
		queue<TreeNode*>myqueue;
		TreeNode* tmp = NULL;
		myqueue.push(root);
		int layer = 0;
		int count = 0;
		int layernum = 0;
		while (!myqueue.empty())
		{
			count = 0;
			layernum = myqueue.size();
			layer++;
			while (count<layernum)
			{
				tmp = myqueue.front();
				myqueue.pop();
				if (tmp->left == NULL && tmp->right == NULL)
				{
					return layer;
				}

				if (tmp->left != NULL)
				{
					myqueue.push(tmp->left);
				}
				if (tmp->right != NULL)
				{
					myqueue.push(tmp->right);
				}
				count++;
			}
		}
		return 0;
	}
};