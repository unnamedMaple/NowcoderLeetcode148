/*

?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "*") ¡ú true
isMatch("aa", "a*") ¡ú true
isMatch("ab", "?*") ¡ú true
isMatch("aab", "c*a*b") ¡ú false

*/
//¶¯Ì¬¹æ»®
class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		int row = strlen(s);
		int col = strlen(p);
		vector<vector<bool>>dp(row + 1, vector<bool>(col + 1, false));

		dp[0][0] = true;
		for (int i = 1; i <= col; i++){
			if (dp[0][i - 1]){
				if (p[i - 1] == '*'){
					dp[0][i] = true;
				}

			}
			else
			{
				break;
			}
		}

		for (int i = 1; i <= row; i++){
			for (int j = 1; j <= col; j++){

				if (s[i - 1] == p[j - 1] || p[j - 1] == '?'){
					dp[i][j] = dp[i - 1][j - 1];
				}
				else if (p[j - 1] == '*'){
					dp[i][j] = dp[i - 1][j - 1] || dp[i - 1][j] || dp[i][j - 1];
				}

			}
		}
		return dp[row][col];
	}
};