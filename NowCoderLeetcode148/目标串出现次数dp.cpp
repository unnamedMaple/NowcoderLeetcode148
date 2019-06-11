
/*

Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie,"ACE"is a subsequence of"ABCDE"while"AEC"is not).

Here is an example:
S ="rabbbit", T ="rabbit"

Return3.

*/
class Solution {
public:
	int numDistinct(string S, string T) {
		int n = S.size();
		int m = T.size();

		vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));

		for (int i = 0; i<n + 1; i++)
		{
			dp[0][i] = 1;
		}

		for (int j = 1; j<m + 1; j++)
		{
			dp[j][0] = 0;
		}


		for (int i = 1; i<m + 1; i++)
		{
			for (int j = 1; j<n + 1; j++)
			{
				if (S[j - 1] != T[i - 1])
				{
					dp[i][j] = dp[i][j - 1];
				}
				else
				{
					dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
				}
			}
		}

		return dp[m][n];



	}
};