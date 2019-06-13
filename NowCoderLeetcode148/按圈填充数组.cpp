/*

Given an integer n, generate a square matrix filled with elements from 1 to n 2 in spiral order.

For example,
Given n =3,

You should return the following matrix:
[
[ 1, 2, 3 ],
[ 8, 9, 4 ],
[ 7, 6, 5 ]
]

*/
class Solution {
public:
	vector<vector<int> > generateMatrix(int n) {
		if (n == 0){
			vector<vector<int>> tmp;
			return tmp;
		}
		vector<vector<int>>ret(n, vector<int>(n, 1));

		int num = 1;
		int circle = 0;
		int i = 0;
		for (int k = 0; k<(n + 1) / 2; k++){
			i = n - 2 * k;
			for (int j = 0; j <= i - 2; j++){
				ret[circle][circle + j] = num;
				num++;


			}

			for (int j = 0; j <= i - 2; j++){
				ret[circle + j][circle + i - 1] = num;
				num++;
			}

			for (int j = 0; j <= i - 2; j++){
				ret[circle + i - 1][circle + i - 1 - j] = num;
				num++;
			}

			for (int j = 0; j <= i - 2; j++){
				ret[circle + i - 1 - j][circle] = num;
				num++;
			}

			circle++;



		}
		if (n % 2 != 0){
			ret[n / 2][n / 2] = num;

		}
		return ret;
	}
};