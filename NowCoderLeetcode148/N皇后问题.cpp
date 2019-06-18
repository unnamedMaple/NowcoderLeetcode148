/*
N皇后问题

*/
class Solution {
public:
	vector<vector<string> > solveNQueens(int n) {
		vector<vector<string> > res;
		vector<string> vec;
		sloveNQueens(res, vec, 0, n);
		return res;
	}
	void sloveNQueens(vector<vector<string> > &res, vector<string> vec, int r, int n)
	{
		if (r == n)  // r表示在填第r行的皇后
		{
			res.push_back(vec);
			return;
		}
		string str(n, '.');
		for (int i = 0; i < n; i++)  // 试着填在【r,i】
		{
			str[i] = 'Q';
			vec.push_back(str);
			if (isvalid(vec, r, i, n))
				sloveNQueens(res, vec, r + 1, n);
			vec.pop_back();
			str[i] = '.';
		}
	}
	bool isvalid(const vector<string> &vec, int r, int c, int n)
	{
		for (int i = 0; i < r; i++)  // cols
		{
			if (vec[i][c] == 'Q')
				return false;
		}
		for (int i = 0; i < r; i++)    //dujiaoxian
			for (int j = 0; j < n; j++)
			{
				if (abs(i - r) == abs(j - c) && vec[i][j] == 'Q')
					return false;
			}
		return true;
	}
};