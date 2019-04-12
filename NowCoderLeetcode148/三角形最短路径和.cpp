/*

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
[2],
[3,4],
[6,5,7],
[4,1,8,3]
]

The minimum path sum from top to bottom is11(i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

*/


class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		int row = triangle.size();
		if (row<1 || triangle[0].size()<1)
		{
			return 0;
		}
		vector<int> minsum(triangle[row - 1].begin(), triangle[row - 1].end());

		for (int i = row - 2; i >= 0; i--)
		{
			for (int j = 0; j<triangle[i].size(); j++)
			{
				minsum[j] = min(minsum[j] + triangle[i][j], minsum[j + 1] + triangle[i][j]);
			}
		}
		return minsum[0];

	}


};