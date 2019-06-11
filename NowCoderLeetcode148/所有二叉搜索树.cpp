/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };

Given n = 3, your program should return all 5 unique BST's shown below.

1         3     3      2      1
\       /     /      / \      \
3     2     1      1   3      2
/     /       \                 \
2     1         2                 3


*/
class Solution {
public:
    int numTrees(int n) {
        
        if(n <= 1)
        {
            return 1;
        }
        
        
        vector<int>tmp(n,0);
        tmp[0] = 1;
        tmp[1] = 1;
        
        
        int total = 0;
        for(int i=2;i<=n;i++)
        {
            total = 0;
            for(int j=0;j<i;j++)
            {
                total+=tmp[j]*tmp[i-1-j];
            }
            tmp[i]= total;
        }
        return tmp[n];
        
    }
};


class Solution {
public:
	vector<TreeNode *> generateTrees(int n) {

		vector<TreeNode *>ret;
		if (n == 0)
		{
			TreeNode* root = nullptr;
			ret.push_back(root);
			return ret;
		}

		vector<int>arr(n, 0);
		for (int i = 1; i <= n; i++)
		{
			arr[i - 1] = i;
		}
		ret = generateTreebyVector(arr);
		return ret;
	}

	vector<TreeNode*>generateTreebyVector(vector<int> arr)
	{
		vector<TreeNode*>ret;

		if (arr.size() == 0)
		{
			TreeNode* root = nullptr;
			ret.push_back(root);
			return ret;
		}

		if (arr.size() == 1)
		{
			TreeNode* root = new TreeNode(arr[0]);
			ret.push_back(root);
			return ret;
		}

		for (int k = 0; k<arr.size(); k++)
		{
			vector<int>left(arr.begin(), arr.begin() + k);
			vector<int>right(arr.begin() + k + 1, arr.end());

			vector<TreeNode*>leftT = generateTreebyVector(left);
			vector<TreeNode*>rightT = generateTreebyVector(right);

			for (int i = 0; i<leftT.size(); i++)
			{
				for (int j = 0; j<rightT.size(); j++)
				{
					TreeNode* root = new TreeNode(arr[k]);
					root->left = leftT[i];
					root->right = rightT[j];
					ret.push_back(root);
				}
			}
		}

		return ret;

	}

};