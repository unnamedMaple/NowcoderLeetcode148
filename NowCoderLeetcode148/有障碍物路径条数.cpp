/*


Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as1and0respectively in the grid.

For example,

There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
[0,0,0],
[0,1,0],
[0,0,0]
]
The total number of unique paths is2.

Note: m and n will be at most 100.



*/

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		int m = obstacleGrid.size();
		if (m == 0){
			return 0;
		}
		int n = obstacleGrid[0].size();
		if (n == 0){
			return 0;
		}
		if (obstacleGrid[0][0] == 1){
			return 0;
		}
		vector<vector<int>>dp(m, vector<int>(n, 0));

		dp[0][0] = 1;
		for (int i = 1; i<m; i++){

			dp[i][0] = dp[i - 1][0];
			if (obstacleGrid[i][0] == 1){
				dp[i][0] = 0;
				break;
			}
		}

		for (int j = 1; j<n; j++){
			dp[0][j] = dp[0][j - 1];
			if (obstacleGrid[0][j] == 1){
				dp[0][j] = 0;
				break;
			}
		}

		for (int i = 1; i<m; i++){
			for (int j = 1; j<n; j++){
				if (obstacleGrid[i][j] == 1){
					dp[i][j] = 0;
				}
				else{
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}

			}
		}
		return dp[m - 1][n - 1];
	}
};