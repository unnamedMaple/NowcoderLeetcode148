/*

Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

1         3     3      2      1
\       /     /      / \      \
3     2     1      1   3      2
/     /       \                 \
2     1         2                 3
*/

class Solution {
public:
	int numTrees(int n) {

		if (n <= 1)
		{
			return 1;
		}


		vector<int>tmp(n, 0);
		tmp[0] = 1;
		tmp[1] = 1;


		int total = 0;
		for (int i = 2; i <= n; i++)
		{
			total = 0;
			for (int j = 0; j<i; j++)
			{
				total += tmp[j] * tmp[i - 1 - j];
			}
			tmp[i] = total;
		}
		return tmp[n];

	}
};