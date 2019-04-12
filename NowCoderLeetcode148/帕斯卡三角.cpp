/*

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]
]
*/

class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int> >ret;
		for (int i = 1; i <= numRows; i++)
		{
			vector<int>tmp(i, 1);

			for (int j = 1; j <= i - 2; j++)
			{
				tmp[j] = ret[i - 2][j - 1] + ret[i - 2][j];
			}

			ret.push_back(tmp);
		}

		return ret;
	}
};