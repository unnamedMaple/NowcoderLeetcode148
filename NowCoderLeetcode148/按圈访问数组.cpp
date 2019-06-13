/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
You should return[1,2,3,6,9,8,7,4,5].

*/
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int>ret;
		int m = matrix.size();
		if (m == 0){
			return ret;
		}
		int n = matrix[0].size();
		if (n == 0){
			return ret;
		}



		int num = m*n;
		int top = 0;
		int bottem = m - 1;
		int left = 0;
		int right = n - 1;
		while (num>0){
			for (int i = left; i <= right; i++){
				ret.push_back(matrix[top][i]);
				num--;

			}

			for (int i = top + 1; i <= bottem; i++){
				ret.push_back(matrix[i][right]);
				num--;

			}

			for (int i = right - 1; num>0 && i >= left; i--){
				ret.push_back(matrix[bottem][i]);
				num--;
			}

			for (int i = bottem - 1; num>0 && i >= top + 1; i--){

				ret.push_back(matrix[i][left]);
				num--;
			}
			top++;
			bottem--;
			left++;
			right--;

		}

		return ret;
	}
};