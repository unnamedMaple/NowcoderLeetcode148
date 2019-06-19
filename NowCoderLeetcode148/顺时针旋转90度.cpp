//
//做两次翻转，先沿右上-左下的对角线翻转，再沿水平中线上下翻转
class Solution {
public:


	void rotate(vector<vector<int> > &matrix) {
		//对角线翻转
		const int n = matrix.size();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n - i; j++)
				swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
		for (int i = 0; i < n / 2; i++)
			for (int j = 0; j < n; j++)
				swap(matrix[i][j], matrix[n - 1 - i][j]);
	}



};